#if ! defined(GENERICO_)
#define GENERICO_
/***************************************************************************
*
*  $MCD Mulo de defini鈬o: TSTG Controlador de teste gen駻ico
*
*  Arquivo gerado:              GENERICO.h
*  Letras identificadoras:      TST
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
*     O mulo de teste gen駻ico cont駑 um conjunto de fun鋏es de
*     coordena鈬o, apoio e controle da execu鈬o de testes de mulos
*     quaisquer.
*
*     Embora na pr疸ica a fun鈬o de teste espec凬ica seja uma extens縊 da
*     fun鈬o de teste gen駻ica, a fun鈬o de teste espec凬ica encontra-se em
*     outro mulo. Desta forma as altera鋏es necess疵ias para cada
*     mulo a testar concentram-se exclusivamente naquele mulo.
*
*  $EIU Interface com o usu疵io pessoa
*     Os seguintes comandos gen駻icos est縊 definidos:
*
*     linha em branco - faz nada
*
*     //      - coment疵io, ・impresso no LOG
*
*     ==      - t咜ulo de caso de teste, o t咜ulo ・impresso no LOG
*
*     =recuperar
*             - Caso o comando imediatamente anterior ao comando
*               =recuperar retorne TST_CondRetOK, obviemanete o comando
*               executou corretamente, portanto o comando =recuperar
*               reportar・uma falha no script de teste, uma vez que n縊
*               foi encontrada a falha esperada ao executar o comando.
*             - Caso o comando antecessor retorne TST_CondRetErro,
*               ou TST_CondRetParm (erro de par穃etros do comando)
*               a falha reportada ser・desconsiderada, uma vez que
*               era esperada. O comando =recuperar destina-se a
*               apoiar o teste da corretude dos validadores de
*               par穃etros dos comandos e das fun鋏es por eles
*               ativadas.
*             - caso o comando antecessor retorne outras condi鋏es, o
*               comando =recuperar ser・tratado como falha.
*
*     =bkpt   - permite interagir com o depurador utilizado para
*               desenvolver os mulos sob teste. O comando =bkpt
*               executa um cigo "dummy" no qual pode ser inserido
*               um "breakpoint" do depurador. Desta forma o teste pode
*               prosseguir sem interrup鈬o at・o comando =bkpt.
*               Para isto
*               - apague ou desative todos os breakpoints do depurador
*               - insira o comando =bkpt no script pouco antes do ponto
*                 de interrup鈬o desejado
*               - usando o depurador, estabele軋 um breakpoint na linha de
*                 cigo: "Dummy = 0;" contida no mulo de teste
*                 gen駻ico. Esta linha pode ser encontrada
*                 procurando por "BKPT_CMD"
*               - d・partida no programa e espere at・chegar ao breakpoint
*                 associado ao comando "dummy". Agora reative ou instale
*                 os breakpoints requeridos pela a sess縊 de depura鈬o.
*                 e continue depurando
*
*     =cancelar
*             - termina a interpreta鈬o dos comandos de teste.
*               Sempre sinaliza falha.
*
*     =AceitaFalhasAcumuladas  numFalhas
*             - caso o contador de falhas registre numFalhas, ele ser・*               tornado zero. Este comando ・similar a =recuperar.
*               Difere deste por ser executado desde que o comando
*               anterior n縊 tenha reportado erro, tal como acontece
*               com todos os comandos, exceto =recuperar.
*               O comando permite recuperar falhas sinalizadas por
*               mulos de apoio, tais como, leitor de par穃etros,
*               contador de passagens e controle de espa輟 din穃ico.
*               Caso o contador de n伹ero de falhas contenha um valor
*               diferente de numFalhas, ser・reportado um erro e
*               o contador ・incrementado de 1.
*
*     Os demais comandos s縊 passados para as fun鋏es de teste espec凬ico.
*     Primeiro para as do arcabou輟, depois para a espec凬ica do mulo
*     a testar. A 伃tima fun鈬o de teste espec凬ico deve retornar a condi鈬o
*     TST_CondRetNaoConhec caso n縊 consiga interpretar a diretiva.
*
*  $EIM Interface com outros mulos
*     A primeira fun鈬o do arcabou輟 ("framework") a ser chamada deve a
*     sempre ser TST_InicializarTeste. Caso n縊 o seja, ocorrer縊 erros
*     de execu鈬o (assert).
*
*     Ap abra o arquivo de script executando a fun鈬o
*     TST_AbrirArquivoScript. Se for desejado gerar um log abra
*     o arquivo corresponente com a fun鈬o TST_AbrirArquivoLog.
*
*     Depois de abrir os arquivos, execute os testes chamando a fun鈬o
*     TST_RealizarTeste. A fun鈬o de teste gen駻ico ler・todo o arquivo
*     de script, retornando ap concluir o teste.
*
*     Ap, termine o teste atrav駸 da fun鈬o TST_TerminarTeste.
*     Esta fun鈬o exibe as estat﨎ticas do teste e, caso solicitado,
*     acumula essas estat﨎ticas em um arquivo acumulador (ver
*     par穃etro /a do programa principal.
*
*     As fun鋏es "TST_ObterXXX" podem ser utilizadas antes de fechar o
*     mulo de teste para exibir o resumo do teste no mulo cliente do
*     mulo de controle gen駻ico.
*
*     O programa cliente do mulo controle de teste gen駻ico pode
*     efetuar as opera鋏es acima repetidas vezes, permitindo, assim o
*     teste envolvendo diversos arquivos scripts de teste. A sa冝a
*     de cada teste deve ser dirigida para um log espec凬ico, ou para
*     stdout, uma vez que, ao abrir um arquivo log, o seu conte棈o ser・*     sempre destru冝o.
*
*     O mulo de teste gen駻ico tamb駑 implementa diversas fun鋏es
*     de compara鈬o "TST_CompararXXX" use-as no mulo de controle de
*     teste espec凬ico. Desta forma ser・assegurado o tratamento uniforme
*     de todas as falhas possivelmente encontradas.
*
*     O mulo disponibiliza ainda a fun鈬o TST_ExibirPrefixo
*     que gera uma linha de sa冝a obedecendo aos padrs de interface
*     estabelecidos. Sendo desejado pode-se adicionar textos ・linha
*     usando a funcao fprintf(TST_pArqLog , ...). Um exemplo disso
*     ・quando se deseja imprimir informa鈬o complementar ao interpretar
*     uma determinada diretiva.
*
*     Finalmente, o mulo disponibiliza a fun鈬o TST_NotificarFalha
*     que incrementa o contador de falhas al駑 de emitir uma mensagem
*     de erro.
*
***************************************************************************/
 
#if defined(GENERICO_OWN)
   #define GENERICO_EXT
#else
   #define GENERICO_EXT extern
#endif

/***** Declara鋏es exportadas pelo mulo *****/

#include    "TST_Espc.h"


/***********************************************************************
*
*  $TC Tipo de dados: TST Cond ret mulo de teste gen駻ico
*
*
***********************************************************************/

   typedef enum {

         TST_CondOK ,
               /* Generico executou correto */

         TST_CondNaoAbriu
               /* Gen駻ico n縊 abriu arquivo */

   } TST_tpCond;


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Inicializar o mulo de teste
*
*  $ED Descri鈬o da fun鈬o
*     Inicializa todas as vari疱eis globais exportadas e encapsuladas
*     do mulo de teste gen駻ico.
*
*     Embora pouco recomend疱el (ver descri鈬o do mulo TesteSpc)
*     esta fun鈬o pode ser alterada para assegurar o estabelecimento
*     do contexto inicial do mulo TesteSpc. Este deve conter uma
*     fun鈬o de inicializa鈬o a ser chamada pela presente fun鈬o.
*
***********************************************************************/

   void TST_InicializarTeste(void);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Terminar a execu鈬o do mulo de teste
*
*  $ED Descri鈬o da fun鈬o
*     Fecha todos os arquivos e desaloca todos os espa輟s de dados
*     alocados sob controle do mulo de teste gen駻ico
*
***********************************************************************/

   void TST_TerminarTeste(void);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Obter origem do nome da extens縊 de arquivo
*
*  $ED Descri鈬o da fun鈬o
*     Procura o in兤io do nome da extens縊 contido no nome do arquivo
*     dado por par穃etro
*
*     Evite o uso de nomes de arquivos com dois ou mais caracteres ".".
*     Isto pode confundir no caso de se desejar a adi鈬o de algum nome
*     de extens縊 padr縊.
*
*  $EP Par穃etros
*     $P NomeArqParm - nome de arquivo a ser analisado
*
*  $FV Valor retornado
*     Ponteiro para o caractere '.' que separa a extens縊.
*     Ser・NULL caso o nome do arquivo n縊 contenha extens縊.
*
***********************************************************************/

   char * TST_ObterInicioExtensao(char * NomeArqParm);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Abrir arquivo log
*
*  $ED Descri鈬o da fun鈬o
*     Abre o arquivo log a ser utilizado como sa冝a durante os testes.
*     Todas as sa冝as geradas pelo mulo de teste s縊 dirigidos para
*     este arquivo. Caso n縊 tenha sido aberto, ser・utilizado o
*     arquivo stdout.
*
*     A extens縊 default do arquivo log ・".log" e ser・acrescida ao nome
*     do arquivo caso este n縊 contenha nome de extens縊.
*
*  $EP Par穃etros
*     $P NomeArqParm - nome do arquivo. Pode (deve) ser um nome relativo
*                      ao diretio corrente. Caso o arquivo
*                      exista, ser・destruido sem perguntar se pode.
*
*  $FV Valor retornado
*     TST_CondRetOK       - abriu corretamente
*     TST_CondRetNaoAbriu - ocorreu algum problema ao tentar abrir.
*                           O problema n縊 ・descriminado.
*                           O arquivo de sa冝a do log volta a ser stdout
*
*  $EIU Interface com usu疵io pessoa
*     Esta fun鈬o deve ser chamada antes de iniciar a execu鈬o dos testes.
*
***********************************************************************/

   TST_tpCondRet TST_AbrirArquivoLog(char * NomeArqParm);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Obter ponteiro para arquivo LOG
*
*  $ED Descri鈬o da fun鈬o
*     Retorna o ponteiro para o FILE do log.
*     Ser・stdout caso n縊 seja definido explicitamente por
*     TSTG_DefinirLog
*
*  $FV Valor retornado
*     Ponteiro v疝ido para um arquivo de texto de sa冝a
*
***********************************************************************/

   FILE * TST_ObterArqLog(void);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Registrar nome do arquivo acumulador
*
*  $ED Descri鈬o da fun鈬o
*     Registra o nome do arquivo acumulador. Este arquivo ・utilizado
*     para acumular as estat﨎ticas de um teste formado por um conjunto
*     de massas de teste. Cada massa de teste gera o seu conjunto de
*     estat﨎ticas de execu鈬o. O arquivo acumulador acumula estas
*     estat﨎ticas permitindo ver o total de todas as massas de teste.
*
*  $EIU Interface com usu疵io pessoa
*     O arquivo acumulador tem serventia somente se o teste ・formado
*     por um conjunto de duas ou mais massas de teste.
*     Antes de executar a primeira deve ser apagado o arquivo acumulador.
*     Ap terminar a execu鈬o da 伃tima massa de teste exiba o resultado
*     como o programa "ExbeEstat" que faz parte do arcabou輟.
*
***********************************************************************/

   void TST_RegistrarArquivoAcumulador(char * pNomeArquivoAcumulador);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Interpretar toda a massa de teste
*
*  $ED Descri鈬o da fun鈬o
*     Interpreta o arquivo de diretivas (script) de teste j・aberto
*
*     A fun鈬o de teste ・dividida em tr黌 classes de comandos:
*
*     - os de teste gen駻ico, que coordenam e controlam a realiza鈬o do
*       teste. Estes comandos s縊 interpretados por esta fun鈬o.
*     - os de teste e controle de mulos componentes do arcabou輟.
*       Estes comandos s縊 interpretados por fun鋏es de teste espec凬icas
*       para cada um dos mulos componentes.
*     - os de teste espec凬ico do mulo (ou mulos) a ser testado.
*       O mulo de teste espec凬ico interpreta os comandos projetados
*       para realizar os testes do mulo a testar.
*
*     A fun鈬o de teste gen駻ico l・um arquivo de diretivas de teste.
*     Cada linha deste arquivo ・um comando de teste.
*     A fun鈬o de teste l・uma a uma as linhas do arquivo, limpa os
*     caracteres em branco no final da linha e procura interpretar o
*     comando.
*
*     As fun鋏es de teste espec凬icas comunicam os resultados da execu鈬o
*     de cada comando por meio de uma condi鈬o de retorno.
*
*     Cada linha do arquivo script de teste corresponde a um comando de
*     teste.
*
*     Caso seja encontrada uma falha n縊 esperada (ver comando =recuperar)
*     os restantes comandos do caso de teste ser縊 ignorados e contados
*     como problemas.
*
*     A sintaxe utilizada pelos comandos de teste ・semelhante a assembler.
*     Esta sintaxe facilita a an疝ise:
*
*        =<cmd> <par穃etros>
*
*     em que:
*        =            - todos os comandos a serem interpretados iniciam
*                       com este caractere
*        <cmd>        - ・o string que identifica o comando
*        <par穃etros> - s縊 zero ou mais itens a serem utilizados
*                       pelo comando de teste. Os itens devem, de prefer麩cia,
*                       ser separados um do outro por um caractere "espa輟"
*
*     Deve ser adotado o seguinte padr縊 de uso:
*
*     - procure sempre utlizar uma das fun鋏es TST_CompararXXX, na forma:
*          return TST_CompararXXX(valoresperado, funcao a testar , mensagem)
*
*     - as fun鋏es de compara鈬o fornecidas sempre geram as mensagens no
*       padr縊 estipulado
*
*     - quando n縊 for poss咩el utilizar uma fun鈬o de compara鈬o, reporte
*       a falha, esperadas ou n縊, atrav駸 da fun鈬o
*          TST_ImprimirPrefixo(Mensagem)
*
*     - a seguir mostre o valor esperado e o obtido
*
*     - Informa鋏es relativas a falhas dos testes s縊 sinalizadas por
*       uma mensagem iniciando com ">>>" o n伹ero da linha do comando de teste
*       e o n伹ero de falhas encontradas at・o momento.
*
*     - Informa鋏es relativas ・execu鈬o dos testes s縊 sinalizadas por
*       uma mensagem iniciando com "!!!".
*
*  $FV Valor retornado
*     TST_CondRetErro   - caso tenha sido encontrado um ou mais problemas
*     TST_CondRetOK     - caso o teste tenha terminado com zero problemas
*                         n縊 esperados.
*
*  $FGP Tipos e Vari疱eis globais externas do prrio mulo
*     pArqScript - deve referenciar o arquivo script aberto
*     pArqLog    - deve referenciar o arquivo log aberto
*
***********************************************************************/

   TST_tpCondRet TST_RealizarTeste(char * Construto);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Obter n伹ero de casos de teste efetuados
*
*  $ED Descri鈬o da fun鈬o
*     Retorna o n伹ero de casos de teste lidos.
*     Cada caso de teste inicia com o comando "== <nome do caso de teste>".
*
***********************************************************************/

   int TST_ObterNumCasosTeste();


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Obter n伹ero de comandos espec凬icos corretamente interpretados
*
*  $ED Descri鈬o da fun鈬o
*     Retorna o n伹ero de comandos de teste espec凬icos lidos e
*     corretamente interpretados. N縊 conta comandos que retornem n縊 OK
*     independentemento do motivo. Tamb駑 n縊 conta comandos recuperar.
*
***********************************************************************/

   int ObterNumComandosExecutados(void);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Obter n伹ero de problemas encontrados
*
*  $ED Descri鈬o da fun鈬o
*     Retorna o n伹ero de problemas encontrados.
*     O mulo de teste espec凬ico sinaliza problemas atrav駸 de
*     uma condi鈬o de retorno diferente de TST_CondRetOK.
*     S縊 tratados como problema tamb駑 comandos de teste em erro,
*     e todos os comandos de teste de um dado caso de teste ignorados
*     em virtude de alguma falha encontrada.
*     Portanto, ・poss咩el que o n伹ero de problemas venha a ser maior do
*     que o n伹ero de casos de teste existente no script.
*
***********************************************************************/

   int TST_ObterNumFalhas(void);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Incrementar contador de falhas
*
***********************************************************************/

   void TST_ContarFalhas();


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar booleano
*
*  $ED Descri鈬o da fun鈬o
*     Compara valor booleano esperado com valor booleano obtido,
*     reportamdo uma falha caso n縊 sejam iguais.
*     Note que "!= 0" corresponde a TRUE e "== 0" corresponde a FALSE
*
*  $EP Par穃etros
*     ValorEsperado  - ・um valor fornecido como par穃etro do comando
*                      de teste
*     ValorObtido    - ・o valor retornado pela fun鈬o em teste
*     pMensagem      - mensagem explanatia da falha encontrada
*
*  $FV Valor retornado
*     TST_CondRetErro  se o valor esperado n縊 for consistente com o obtido
*     TST_CondRetOK    se os valores forem consistentes
*
***********************************************************************/

   TST_tpCondRet TST_CompararBool(int    ValorEsperado ,
                                   int    ValorObtido   ,
                                   char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar caractere
*
*  $ED Descri鈬o da fun鈬o
*     Compara um caractere esperado com um caractere obtido, emitindo mensagem de
*     erro caso n縊 sejam iguais.
*
*  $EP Par穃etros
*     ValorEsperado  - ・um valor fornecido como par穃etro do comando
*                      de teste
*     ValorObtido    - ・o valor retornado pela fun鈬o em teste
*     pMensagem      - mensagem explanatia da falha encontrada
*
*  $FV Valor retornado
*     TST_CondRetErro  se o valor esperado n縊 for igual ao obtido
*     TST_CondRetOK    se os valores forem iguais
*
***********************************************************************/

   TST_tpCondRet TST_CompararChar(char   ValorEsperado ,
                                   char   ValorObtido   ,
                                   char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar inteiro
*
*  $ED Descri鈬o da fun鈬o
*     Compara valor inteiro long esperado com valor inteiro obtido,
*     reportamdo uma falha caso n縊 sejam iguais.
*
*  $EP Par穃etros
*     ValorEsperado  - ・um valor fornecido como par穃etro do comando
*                      de teste
*     ValorObtido    - ・o valor retornado pela fun鈬o em teste
*     pMensagem      - mensagem explanatia da falha encontrada
*
*  $FV Valor retornado
*     TST_CondRetErro  se o valor esperado n縊 for igual ao obtido
*     TST_CondRetOK    se os valores forem iguais
*
***********************************************************************/

   TST_tpCondRet TST_CompararInt(long   ValorEsperado ,
                                  long   ValorObtido   ,
                                  char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar flutuante
*
*  $ED Descri鈬o da fun鈬o
*     Compara valor flutuante esperado com valor flutuante obtido,
*     reportando uma falha caso
*     1 - Tolerancia > esperado / obtido ou
*     1 + Tolerancia < esperado / obtido
*
*  $EP Par穃etros
*     ValorEsperado  - ・um valor fornecido como par穃etro do comando
*                      de teste
*     ValorObtido    - ・o valor retornado pela fun鈬o em teste
*     Toler穗cia     - indica os limites da rela鈬o entre esperado e obtido.
*                      Deve ser um valor positivo, menor do que 1.
*                      Use um valor do tipo 10 ** -n, no qual n ・o
*                      n伹ero de d刕itos significativos desejado.
*     pMensagem      - mensagem explanatia da falha encontrada
*
*  $FV Valor retornado
*     TST_CondRetErro  se o valor obtido n縊 estiver dentro do dom匤io da
*                      toler穗cia em torno do valor esperado
*     TST_CondRetOK    se os valores estiverem dentro da toler穗cia
*
***********************************************************************/

   TST_tpCondRet TST_CompararFloat(double   ValorEsperado ,
                                    double   ValorObtido   ,
                                    double   Tolerancia    ,
                                    char *   pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar string
*
*  $ED Descri鈬o da fun鈬o
*     Compara string esperado com string obtido, reportamdo uma falha
*     caso n縊 sejam iguais. Ambos os strings devem obedecer o
*     padr縊 C, terminando em zero.
*
*  $EP Par穃etros
*     ValorEsperado  - ・um string fornecido como par穃etro do comando
*                      de teste.
*     ValorObtido    - ・o string retornado pela fun鈬o em teste
*     pMensagem      - mensagem explanatia da falha encontrada
*
*  $FV Valor retornado
*     TST_CondRetErro  se o valor esperado n縊 for igual ao obtido
*     TST_CondRetOK    se os valores forem iguais
*
***********************************************************************/

   TST_tpCondRet TST_CompararString(char * ValorEsperado ,
                                     char * ValorObtido   ,
                                     char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar espa輟
*
*  $ED Descri鈬o da fun鈬o
*     Compara espa輟s de dados, reportando uma falha caso n縊 sejam iguais.
*     Esta fun鈬o pode ser utilizada para comparar qualquer coisa,
*     inclusive valores do tipo  "struct"
*     O tipo do valor ・indefinido e os valores ser縊 exibidos em
*     formato hexadecimal, caso n縊 sejam iguais
*
*  $EP Par穃etros
*     ValorEsperado  - ponteiro para o espa輟 que cont駑 o valor esperado
*     ValorObtido    - ponteiro para o espa輟 que cont駑 o valor obtido
*     TamEspaco      - tamanho do espa輟 a ser comparado
*     pMensagem      - mensagem explanatia da falha encontrada
*
*  $FV Valor retornado
*     TST_CondRetErro  se o valor esperado n縊 for igual ao obtido
*     TST_CondRetOK    se os valores forem iguais
*
***********************************************************************/

   TST_tpCondRet TST_CompararEspaco(void * ValorEsperado ,
                                     void * ValorObtido   ,
                                     int    TamEspaco     ,
                                     char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar ponteiro
*
*  $ED Descri鈬o da fun鈬o
*     Compara dois ponteiros emitindo uma mensagem caso n縊 sejam iguais
*
*  $FV Valor retornado
*     TST_CondRetErro  se os dois ponteiros forem diferentes
*     TST_CondRetOK    se forem iguais
*
***********************************************************************/

   TST_tpCondRet TST_CompararPonteiro(void * PonteiroEsperado ,
                                       void * PonteiroObtido   ,
                                       char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Comparar ponteiro nulo
*
*  $ED Descri鈬o da fun鈬o
*     Verifica
*       - quando ModoEsperado     ・0 se o ponteiro ・nulo
*       - quando ModoEsperado n縊 ・0 se o ponteiro ・n縊 nulo
*
*  $FV Valor retornado
*     TST_CondRetErro  se os dois ponteiros forem diferentes
*     TST_CondRetOK    se forem iguais
*
***********************************************************************/

   TST_tpCondRet TST_CompararPonteiroNulo(int ModoEsperado ,
                                           void * PonteiroObtido   ,
                                           char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Assertiva controlada
*
*  $ED Descri鈬o da fun鈬o
*     Esta fun鈬o substitui a fun鈬o assert de C.
*     ﾉ utilizada no contexto do arcabou輟 de teste.
*     Ela imprime mensagens mais vis咩eis tanto no log como na
*     janela de comando.
*
*     Recomenda-se, no entanto, utilizar a fun鈬o assert de C em aplica鋏es.
*
*  $FV Valor retornado
*     Termina a execu鈬o do programa com cigo de retorno == 4
*
***********************************************************************/

   #define  TST_ASSERT(Expressao) \
      TST_Assert(Expressao , __LINE__ , __FILE__)

   void TST_Assert(int Expressao , int Linha , char * NomeArq);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Notificar falha
*
*  $ED Descri鈬o da fun鈬o
*     Exibe uma mensagem de falha no formato padr縊 do arcabou輟.
*
*  $FV Valor retornado
*     TST_CondRetErro  sempre
*
***********************************************************************/

   TST_tpCondRet TST_NotificarFalha(char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Exibir prefixo da mensagem
*
*  $ED Descri鈬o da fun鈬o
*     Imprime o prefixo de mensages de falha
*
*  $EH Hipeses assumidas pela fun鈬o
*     O contador de falhas ・incrementado somente pela fun鈬o de teste
*     gen駻ica e ap ・conclus縊 da interpreta鈬o do comando.
*
***********************************************************************/

   void TST_ExibirPrefixo(char * Indicador , char * pMensagem);


/***********************************************************************
*
*  $FC Fun鈬o: TSTG &Exibir um espa輟 qualquer em formato hexadecimal e char
*
*  $EP Par穃etros
*     $P tamEspaco - tamanho em bytes do espa輟 a exibir
*     $P Ponteiro  - ponteiro para o primeiro byte do espa輟 a exibir
*
***********************************************************************/

   void TST_ExibirEspacoHexa(int    tamEspaco ,
                              void * Ponteiro);

#undef GENERICO_EXT

/********** Fim do mulo de defini鈬o: TSTG Controlador de teste gen駻ico **********/

#else
#endif
