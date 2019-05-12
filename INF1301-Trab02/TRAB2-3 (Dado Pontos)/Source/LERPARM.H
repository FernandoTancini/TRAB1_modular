#if ! defined(LerParm_)
#define LerParm_
/***************************************************************************
*
*  $MCD Mulo de defini鈬o: LER  Ler par穃etros de comandos
*
*  Arquivo gerado:              LerParm.h
*  Letras identificadoras:      LER
*
*  Nome da base de software:    Arcabou輟 para a automa鈬o de testes de programas redigidos em C
*  Arquivo da base de software: C:\AUTOTEST\PROJETOS\INSTRUM.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza鈬o dos testes de mulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Histico de evolu鈬o:
*     Vers縊  Autor    Data     Observa鋏es
*     4       avs   01/fev/2006 criar linguagem script simbica
*     3       avs   08/dez/2004 uniformiza鈬o dos exemplos
*     2       avs   07/jul/2003 unifica鈬o de todos os mulos em um s・projeto
*     1       avs   16/abr/2003 in兤io desenvolvimento
*
*  $ED Descri鈬o do mulo
*     Le par穃etros contidos em um buffer.
*     Os par穃etros podem ser simbicos ou literais.
*     Par穃etros simbicos devem ser declarados antes de serem utilizados.
*
***************************************************************************/
 
#if defined(LerParm_OWN)
   #define LerParm_EXT
#else
   #define LerParm_EXT extern
#endif

/***** Declara鋏es exportadas pelo mulo *****/

#define  LER_DIM_NOME     32
#define  LER_DIM_STRING  500
#define  LER_DIM_BUFFER      250


/***********************************************************************
*
*  $TC Tipo de dados: LER Condi鋏es de retorno
*
*
***********************************************************************/

   typedef enum {

         LER_CondRetOK ,
               /* Ler retorno OK */

         LER_CondRetNaoAbriu
               /* Ler n縊 abriu arquivo */

   } LER_tpCondRet;

/***** Dados exportados pelo mulo *****/

   /* Estrutura de dados: *LER  Dados globais p炻licos */

   LerParm_EXT int LER_TamBuffer;
         /* Tamanho do string contido no buffer de leitura */

   LerParm_EXT char LER_Buffer[LER_DIM_BUFFER + 1];
         /* Buffer de leitura */


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Inicializar mulo LerParm
*
*  $ED Descri鈬o da fun鈬o
*     Inicializa o mulo.
*     Deve ser chamada antes de iniciar a an疝ise de comandos.
*     Deve ser chamada uma 佖ica vez no in兤io ou ap terminar o mulo.
*
***********************************************************************/

   int LER_InicializarLeitura(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Obter nome do arquivo script
*
***********************************************************************/

   char * LER_ObterNomeArqScript(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Interpretar comandos de teste
*
*  $ED Descri鈬o da fun鈬o
*     Interpreta os comandos de teste disponibilizados pelo mulo
*     de leitura.
*
*     Ver a descri鈬o do mulo para mais detalhes
*
***********************************************************************/

   TST_tpCondRet LER_InterpretarComandos(char * ComandoTeste);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Terminar mulo LerParm
*
***********************************************************************/

   void LER_TerminarLeitura(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Abrir arquivo script de teste
*
*  $ED Descri鈬o da fun鈬o
*     Abre o arquivo que cont駑 o script de teste.
*     A extens縊 default do arquivo de comandos script de teste ・*     ".script" e ser・acrescida ao nome do arquivo caso este n縊
*     contenha nome de extens縊.
*
*  $EP Par穃etros
*     $P NomeArqParm - nome do arquivo contendo o script de teste
*
*  $FV Valor retornado
*     LER_CondRetOK        - caso tenha sido poss咩el abrir o arquivo.
*     LER_CondRetNaoAbriu  - caso tenha ocorrido algum erro.
*                            N縊 h・discrimina鈬o do erro encontrado.
*
***********************************************************************/

   LER_tpCondRet LER_AbrirArquivoScript(char * NomeArqParm);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Fechar arquivo script
*
***********************************************************************/

   void LER_FecharScript(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Declarar par穃etro simbico
*
***********************************************************************/

   int LER_DeclararParametro(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Exibir declara鈬o de s匇bolo
*
***********************************************************************/

   void LER_ExibirParametro(char * Simbolo);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler linha script eliminando brancos ao final
*
*  $ED Descri鈬o da fun鈬o
*     L・uma linha do arquivo script e elimina os caracteres branco,
*     fim de linha, tabula鈬o etc. do final da linha lida.
*
*  $FV Valor retornado
*     Retorna o tamanho da linha lida.
*     Ser・
*        -1 caso tenha ocorrido fim de arquivo.
*        -2 caso tenha ocorrido algum problema de leitura.
*
***********************************************************************/

   int LER_LerLinhaScript(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Obter n伹ero de linhas lidas at・o momento
*
***********************************************************************/

   int LER_ObterNumLinhas(void);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler linha de par穃etros
*
*  $ED Descri鈬o da fun鈬o
*     L・um n伹ero vari疱el de par穃etros
*
*  $EP Par穃etros
*     Tipos   ・um string contendo a identifica鈬o dos tipos dos par穃etros
*             a serem lidos.
*     ...     Os demais par穃etros s縊 refer麩cias (ponteiros) para os
*             espa輟s onde dever縊 ser armazenados os valores lidos.
*
*     Tal como em scanf deve-se tomar o cuidado de assegurar que a lista
*     de refer麩cia e o string de tipos tenha o mesmo tamanho
*     e que os indicadores de tipo sejam consistentes com a refer麩cia
*     posicionalmente correspondente.
*
*     Ao ler um campo primeiro procura ler um nome de par穃etro j・*     declarado. Caso isto seja poss咩el e o tipo esteja correto
*     ・" lido" o valor contido no par穃etro
*     Caso n縊 seja poss咩el tenta ler um literal em acordo com o tipo
*     dado.
*
*     Gera mensagens de erro para par穃etros desconhecidos, sintaxe errada
*     e tipo inconsistente com o solicitado.
*
*  $FV Valor retornado
*     Retorna o n伹ero de campos lidos at・concluir ou at・encontrar
*     um erro.
*
***********************************************************************/

   int LER_LerParametros(char * Tipos , ...);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler par穃etro caractere
*
***********************************************************************/

   int LER_LerParmChar(char * Parm);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler par穃etro flutuante
*
***********************************************************************/

   int LER_LerParmDouble(double * Parm);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler par穃etro nome
*
***********************************************************************/

   int LER_LerParmNome(char * Parm , int * tamNome , int dimNome);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler par穃etro inteiro
*
***********************************************************************/

   int LER_LerParmInt(int * Parm);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Ler par穃etro string
*
***********************************************************************/

   int LER_LerParmString(char * Parm , int * tamString , int dimString);


/***********************************************************************
*
*  $FC Fun鈬o: LER  &Pular comando de teste
*
***********************************************************************/

   void LER_PularComando(void);

#undef LerParm_EXT

/********** Fim do mulo de defini鈬o: LER  Ler par穃etros de comandos **********/

#else
#endif
