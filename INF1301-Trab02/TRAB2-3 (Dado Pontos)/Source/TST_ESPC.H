#if ! defined(Tst_Espc_)
#define Tst_Espc_
/***************************************************************************
*
*  $MCD Módulo de definição: TSTE Interface de teste especúƒico
*
*  Arquivo gerado:              Tst_Espc.h
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: C:\AUTOTEST\PROJETOS\INSTRUM.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     4       avs   01/fev/2006 criar linguagem script simbólica
*     3       avs   08/dez/2004 uniformização dos exemplos
*     2       avs   07/jul/2003 unificação de todos os módulos em um sEprojeto
*     1       avs   16/abr/2003 iniio desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo consta somente do módulo de definição de todos os módulos
*     de teste especúƒicos a serem desenvolvidos, e também da especificação
*     do tipo de condições de retorno deste módulo.
*
*     Ele estabelece a interface a ser utilizada pelo módulo de teste
*     genérico com todos os módulos de teste especúƒico a serem
*     desenvolvidos.
*
*     Os módulos de teste especúƒico devem sempre incluir este módulo
*     de definição e, idealmente, não devem adicionar mais itens
*     Einterface.
*
***************************************************************************/
 
#if defined(Tst_Espc_OWN)
   #define Tst_Espc_EXT
#else
   #define Tst_Espc_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

#define     SINALIZA_ERRO       ">>>"
#define     SINALIZA_RECUPERA   "<<<"
#define     SINALIZA_COMENTARIO "!!!"


/***********************************************************************
*
*  $TC Tipo de dados: TST Condições de retorno do módulo de teste
*
*
*  $ED Descrição do tipo
*     Este tipo enumera todas as condições de retorno que podem ser
*     geradas pela função de teste especúƒica.
*
***********************************************************************/

   typedef enum {

         TST_CondRetOK ,
               /* Comando de teste executou corretamente */

         TST_CondRetErro ,
               /* Comando de teste encontrou uma ou mais falhas
               *
               *$ED Descrição
               *   Esta condição sinaliza que um ou mais resultados da execução
               *   da função sob teste resultou em um valor diferente do esperado. */

         TST_CondRetParm ,
               /* Comando de teste estEcom a sintaxe em erro
               *
               *$ED Descrição
               *   A presente condição de retorno deve ser retornada caso a sintaxe
               *   ou os valores do comando de teste estiverem em erro.
               *
               *   Todos os fragmentos de interpretação devem:
               *   - realizar a análise dos parâmetros do comando
               *   - verificar se todos os parâmetros foram lidos
               *   - verificar se os valores dos parâmetros estão corretos
               *     por exemplo: verificar se os ú‹dices de acesso a elementos
               *     estão dentro dos limites dos correspondentes vetores.
               *   - efetuar a função a testar
               *   - verificar se os resultados retornados por esta função estão
               *     corretos */

         TST_CondRetNaoExecutou ,
               /* Comando de teste não se destina ao presente interpretador
               *
               *$ED Descrição
               *   Esta condição deve ser retornada por todas as funções de interpretação
               *   de comandos de teste relativas a módulos do próprio arcabouço,
               *   caso não tenha sido encontrado um comando válido. Isso permite
               *   estabelecer um "daisy chain" de interpretadores em que cada qual
               *   tenha finalidade especúƒica no contexto do arcabouço. */

         TST_CondRetNaoConhec ,
               /* Comando de teste não Econhecido
               *
               *$ED Descrição
               *   Esta condição deve ser retornada por todas as funções de interpretação
               *   de casos de teste especúƒico visando determinado módulo em teste,
               *   sempre que esse interpretador não consiga identificar o comando.
               *
               *   Cabe salientar a diferença entre TST_CondRetNaoExecutou e
               *   TST_CondRetNaoConhec. A primeira corresponde Enão interpretação
               *   de um comando possivelmente válido em interpretadores subsequentes.
               *   A segunda corresponde a comandos não válidos considerando todos
               *   os interpretadores. */

         TST_CondRetNaoImplementado ,
               /* Comando de teste não implementado
               *
               *$ED Descrição
               *   Esta condição deve ser retornada ao interpretar um comando de teste
               *   especúƒico ainda não implementado.
               *
               *   Recomenda-se que o desenvolvimento dos módulos sob teste e do
               *   correpondente módulo de teste especúƒico se dEincrementalmente.
               *   Consequentemente diversos comandos não estarão implementados
               *   no inú€io do desenvolvimento. Esta incompleteza poderEser
               *   sinalizada com esta condição de retorno. */

         TST_CondRetMemoria
               /* Faltou memória para executar o comando
               *
               *$ED Descrição
               *   Esta condição deve ser retornada caso tenha ocorrido algum erro
               *   quando o módulo de teste especúƒico tentar alocar memória ou
               *   outro recurso. */

   } TST_tpCondRet;


/***********************************************************************
*
*  $FC Função: TSTE &Efetuar comandos de teste especúƒicos
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste especúƒicos para o módulo
*     sendo testado.
*
*     Cada módulo de teste especúƒico deve desenvolver esta função.
*     PoderEconter diversas outras conforme necessário. No entanto
*     estas devem todas ser funções encapsuladas no módulo (static)
*
*     FreqEntemente Enecessário desenvolver um contexto para o teste.
*     Por exemplo, pode ser necessário tratar n elementos disponibilizados
*     pelo módulo sob teste. Neste caso deveria ser criado um vetor
*     global com referências para estas elemento. Ao iniciar os teste
*     este vetor deverEser inicializado. Ao terminar, os elementos do
*     vetor referenciando algum elemento devem ser destruúos.
*
*     Uma das formas para estabelecer o contexto seria a de incluir
*     no mçodulo de teste especúƒico comando semelhantes a:
*
*       =iniciaXXX  que inicializa o contexto do módulo sob teste para
*                   vazio. Este comando deve ser utilizado uma única vez
*                   logo ao inciar a execução do teste.
*       =reset      restaura o contexto para vazio. Este comando usualmente
*                   assumirEque o contexto a esvaziar esteja correto.
*                   O comando deverEliberar os espaços alocados aos
*                   elementos, anular as referências a ele, inicializar
*                   valores de vetores de referências, etc.
*                   O comando tem utilidade especial ao segmentar um teste
*                   em partes estanques e ao controlar vazamento de
*                   memória.
*       =terminaXXX este comando destrói todo o contexto e não o
*                   reinicializa. O objetivo Epoder verificar vazamento
*                   de memória.
*
*     Evidentemente, outra forma seria a de alterar as funções de
*     inicialização e término do módulo de teste genérico o que Epouco
*     recomendável pois viola o princúio de um mesmo módulo genérico
*     servir para testar todos os construtos.
*
*     Para cada função do módulo a ser testado deve existir pelo menos
*     um comando. Em alguns casos pode ser interessante criar
*     comandos que armazenem, alterem ou consultem variáveis de
*     estado do próprio módulo de teste. Ver os comentários sobre
*     contexto acima.
*
*     Todos os controles de consistência devem ser realizados no
*     módulo de teste especúƒico.
*
*     A função TST_EfetuarComando() deve retornar as condições de retorno
*     identificadas no tipo TST_tpCondRet definida no módulo TesteGen.
*
*     As funções do módulo sob teste que retornam algum valor sempre
*     devem sempre ter este valor verificado, mesmo sendo uma condição de
*     retorno. Para fazer a vereficação da corretude, recomenda-se
*     utilizar as funções TST_CompararXXX definidas no módulo genérico.
*     Assegura-se assim a uniformidade da saúa gerada durante o teste.
*
*     Para realizar a análise de um comando de teste recomenda-se
*     utilizar as funções definidas no módulo LerParm. Elas, além
*     de realizarem a análise léxica, permitem o uso intercambiável
*     de parâmetros simbólicos ou literais. Também realizam a
*     verificação da corretude dos tipos dos parâmetros, contribuindo
*     assim para a redução de erros de redação de scripts de teste
*     que possam passar despercebidos.
*
*     As funções a serem testadas que requeiram algum argumento, devem
*     ser chamadas com valores (parâmetros) extraúos do comando de
*     teste sendo executado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     TST_CondRetXXX       - veja a descriÓcão dos possú“eis valores
*                            retornados na especificação do correspondente
*                            enum
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando(char * ComandoTeste);

#undef Tst_Espc_EXT

/********** Fim do módulo de definição: TSTE Interface de teste especúƒico **********/

#else
#endif
