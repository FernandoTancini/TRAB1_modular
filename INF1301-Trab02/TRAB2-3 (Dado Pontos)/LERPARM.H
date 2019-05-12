#if ! defined(LerParm_)
#define LerParm_
/***************************************************************************
*
*  $MCD MÛdulo de definiÁ„o: LER  Ler par‚metros de comandos
*
*  Arquivo gerado:              LerParm.h
*  Letras identificadoras:      LER
*
*  Nome da base de software:    ArcabouÁo para a automaÁ„o de testes de programas redigidos em C
*  Arquivo da base de software: C:\AUTOTEST\PROJETOS\INSTRUM.BSW
*
*  Projeto: INF 1301 / 1628 AutomatizaÁ„o dos testes de mÛdulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA HistÛrico de evoluÁ„o:
*     Vers„o  Autor    Data     ObservaÁıes
*     4       avs   01/fev/2006 criar linguagem script simbÛlica
*     3       avs   08/dez/2004 uniformizaÁ„o dos exemplos
*     2       avs   07/jul/2003 unificaÁ„o de todos os mÛdulos em um sÅEprojeto
*     1       avs   16/abr/2003 in˙Äio desenvolvimento
*
*  $ED DescriÁ„o do mÛdulo
*     Le par‚metros contidos em um buffer.
*     Os par‚metros podem ser simbÛlicos ou literais.
*     Par‚metros simbÛlicos devem ser declarados antes de serem utilizados.
*
***************************************************************************/
 
#if defined(LerParm_OWN)
   #define LerParm_EXT
#else
   #define LerParm_EXT extern
#endif

/***** DeclaraÁıes exportadas pelo mÛdulo *****/

#define  LER_DIM_NOME     32
#define  LER_DIM_STRING  500
#define  LER_DIM_BUFFER      250


/***********************************************************************
*
*  $TC Tipo de dados: LER CondiÁıes de retorno
*
*
***********************************************************************/

   typedef enum {

         LER_CondRetOK ,
               /* Ler retorno OK */

         LER_CondRetNaoAbriu
               /* Ler n„o abriu arquivo */

   } LER_tpCondRet;

/***** Dados exportados pelo mÛdulo *****/

   /* Estrutura de dados: *LER  Dados globais p˙blicos */

   LerParm_EXT int LER_TamBuffer;
         /* Tamanho do string contido no buffer de leitura */

   LerParm_EXT char LER_Buffer[LER_DIM_BUFFER + 1];
         /* Buffer de leitura */


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Inicializar mÛdulo LerParm
*
*  $ED DescriÁ„o da funÁ„o
*     Inicializa o mÛdulo.
*     Deve ser chamada antes de iniciar a an·lise de comandos.
*     Deve ser chamada uma ˙nica vez no in˙Äio ou apÛs terminar o mÛdulo.
*
***********************************************************************/

   int LER_InicializarLeitura(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Obter nome do arquivo script
*
***********************************************************************/

   char * LER_ObterNomeArqScript(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Interpretar comandos de teste
*
*  $ED DescriÁ„o da funÁ„o
*     Interpreta os comandos de teste disponibilizados pelo mÛdulo
*     de leitura.
*
*     Ver a descriÁ„o do mÛdulo para mais detalhes
*
***********************************************************************/

   TST_tpCondRet LER_InterpretarComandos(char * ComandoTeste);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Terminar mÛdulo LerParm
*
***********************************************************************/

   void LER_TerminarLeitura(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Abrir arquivo script de teste
*
*  $ED DescriÁ„o da funÁ„o
*     Abre o arquivo que contÈm o script de teste.
*     A extens„o default do arquivo de comandos script de teste ÅE*     ".script" e serÅEacrescida ao nome do arquivo caso este n„o
*     contenha nome de extens„o.
*
*  $EP Par‚metros
*     $P NomeArqParm - nome do arquivo contendo o script de teste
*
*  $FV Valor retornado
*     LER_CondRetOK        - caso tenha sido poss˙ìel abrir o arquivo.
*     LER_CondRetNaoAbriu  - caso tenha ocorrido algum erro.
*                            N„o hÅEdiscriminaÁ„o do erro encontrado.
*
***********************************************************************/

   LER_tpCondRet LER_AbrirArquivoScript(char * NomeArqParm);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Fechar arquivo script
*
***********************************************************************/

   void LER_FecharScript(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Declarar par‚metro simbÛlico
*
***********************************************************************/

   int LER_DeclararParametro(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Exibir declaraÁ„o de s˙äbolo
*
***********************************************************************/

   void LER_ExibirParametro(char * Simbolo);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler linha script eliminando brancos ao final
*
*  $ED DescriÁ„o da funÁ„o
*     LÅEuma linha do arquivo script e elimina os caracteres branco,
*     fim de linha, tabulaÁ„o etc. do final da linha lida.
*
*  $FV Valor retornado
*     Retorna o tamanho da linha lida.
*     SerÅE
*        -1 caso tenha ocorrido fim de arquivo.
*        -2 caso tenha ocorrido algum problema de leitura.
*
***********************************************************************/

   int LER_LerLinhaScript(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Obter n˙mero de linhas lidas atÅEo momento
*
***********************************************************************/

   int LER_ObterNumLinhas(void);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler linha de par‚metros
*
*  $ED DescriÁ„o da funÁ„o
*     LÅEum n˙mero vari·vel de par‚metros
*
*  $EP Par‚metros
*     Tipos   ÅEum string contendo a identificaÁ„o dos tipos dos par‚metros
*             a serem lidos.
*     ...     Os demais par‚metros s„o referÍncias (ponteiros) para os
*             espaÁos onde dever„o ser armazenados os valores lidos.
*
*     Tal como em scanf deve-se tomar o cuidado de assegurar que a lista
*     de referÍncia e o string de tipos tenha o mesmo tamanho
*     e que os indicadores de tipo sejam consistentes com a referÍncia
*     posicionalmente correspondente.
*
*     Ao ler um campo primeiro procura ler um nome de par‚metro jÅE*     declarado. Caso isto seja poss˙ìel e o tipo esteja correto
*     ÅE" lido" o valor contido no par‚metro
*     Caso n„o seja poss˙ìel tenta ler um literal em acordo com o tipo
*     dado.
*
*     Gera mensagens de erro para par‚metros desconhecidos, sintaxe errada
*     e tipo inconsistente com o solicitado.
*
*  $FV Valor retornado
*     Retorna o n˙mero de campos lidos atÅEconcluir ou atÅEencontrar
*     um erro.
*
***********************************************************************/

   int LER_LerParametros(char * Tipos , ...);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler par‚metro caractere
*
***********************************************************************/

   int LER_LerParmChar(char * Parm);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler par‚metro flutuante
*
***********************************************************************/

   int LER_LerParmDouble(double * Parm);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler par‚metro nome
*
***********************************************************************/

   int LER_LerParmNome(char * Parm , int * tamNome , int dimNome);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler par‚metro inteiro
*
***********************************************************************/

   int LER_LerParmInt(int * Parm);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Ler par‚metro string
*
***********************************************************************/

   int LER_LerParmString(char * Parm , int * tamString , int dimString);


/***********************************************************************
*
*  $FC FunÁ„o: LER  &Pular comando de teste
*
***********************************************************************/

   void LER_PularComando(void);

#undef LerParm_EXT

/********** Fim do mÛdulo de definiÁ„o: LER  Ler par‚metros de comandos **********/

#else
#endif
