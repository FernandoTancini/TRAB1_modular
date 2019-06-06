#if ! defined( FINALIZADAS_ )
#define FINALIZADAS_
*******************************************************************************************
* $MCI Módulo de definição: Módulo dado pontos
* Arquivo gerado:     DadoPontos.h
* Letras identificadoras:   DPTS
*
* Projeto:            Disciplina INF 1301
*
*   Autor:                    sipf - Suemy Inagaki Pinheiro Fagundes
*
* $HA Histórico de evolução:
* Versão  Autor    Data     Observações
* 1.03    sipf   11/05/2019  Refiz as assertivas de entrada e saída
* 1.02    sipf   10/05/2019  Refiz o código todo para mudar a estrutura de dadopontos
* 1.01    sipf   09/05/2019  Assertivas das funções adicionadas
* 1.00    sipf   30/abr/2019 Desenvolvimento
*
*       $ED Descrição do módulo
*       Define as Funções de DadoPontos.
* No início de cada partida não existe dado de pontos
*
*****************************************************************************************/

#include "peca.h"

/***********************************************************************
*
*  $TC Tipo de dados: PFN Condições de retorno
*
*
***********************************************************************/

   typedef enum {

      PFN_CondRetOK = 0 ,
          /* Rodou sem erros */

      PFN_CondRetMemoria = 1
          /* Erro ao alocar memória */

   } PFN_tpCondRet ;


/***********************************************************************
*
*  $TC Tipo de dados: PFN Tipo abstrato peças finalizadas
*
*
***********************************************************************/

typedef struct tpFinalizadas * PFN_tppFinalizadas ;

/***********************************************************************
*
*  $FC Função: PFN Criar
*
*  $ED Descrição da função
*     Cria uma lista de peças finalizadas vazia
*
*  $EP Parâmetros:
*     $P pFinalizadas   - Parâmetro de retorno do lista de pças
*						  finalizadas criada.
*                         Esse parâmetro é passado por referência
*
*  Assertivas de entrada:
*     - O ponteiro passado como parametro deve ser válido.
*
*  Assertivas de saída:
*     - *pFinalizadas deve conter a lista de peças finalizadas criada.
*
*  $FV Valor retornado:
*     PFN_CondRetOK
*     PFN_CondRetMemoria
*
***********************************************************************/

   PFN_tpCondRet PFN_Criar( PFN_tppFinalizadas * pFinalizadas ) ;

/***********************************************************************
*
*  $FC Função: PFN Destruir
*
*  $ED Descrição da função:
*     Destroi a lista e as peças nela contidas
*
*  $EP Parâmetros:
*     $P pFinalizadas - Lista de peças finalizadas a ser destruída
*
*  Assertivas de entrada:
*     - pFinalizadas deve ser uma instância válida de lista de peças finalizadas.
*
*  Assertivas de saída:
*     - A memória ocupada pela lista passada por parâmetro deve
*       ser desalocada.
*
*  $FV Valor retornado:
*     PFN_tpCondRetOK
*
***********************************************************************/

   PFN_tpCondRet PFN_Destruir( PFN_tppFinalizadas pFinalizadas ) ;

/***********************************************************************
*
*  $FC Função: PFN Incluir Peça
*
*  $ED Descrição da função:
*     Inclui uma peça na lista de peças finalizadas
*
*  $EP Parâmetros:
*     $P pFinalizadas - Lista de peças a ser operado
*     $P peca         - Peça a ser incluída
*
*  Assertivas de entrada:
*     - pFinalizadas deve ser uma instância válida de lista de peças finalizadas.
*     - peca deve ser uma instância válida de peça.
*
*  Assertivas de saída:
*     - A peça passada no parâmetro peca será incluída na lista passada.
*
*  $FV Valor retornado
*     PFN_CondRetMemoria 
*     PFN_CondRetOK
*
***********************************************************************/

   PFN_tpCondRet PFN_InserirPeca ( PFN_tppFinalizadas pFinalizadas , PEC_tppPeca peca ) ;

 /***********************************************************************
*
*  $FC Função: PFN Contar Peças
*
*  $ED Descrição da função:
*     Conta as peças da lista de peças finalizadas.
*
*  $EP Parâmetros:
*     $P pFinalizadas - Lista de peças a ser operado.
*     $P qtd_pecas    - Ponteiro para a quantidade de peças a ser contada
*
*  Assertivas de entrada:
*     - pFinalizadas deve ser uma instância válida de lista de peças finalizadas.
*     - qtd_pecas deve ser um ponteiro válido
*
*  Assertivas de saída:
*     - qtd_pecas tem o tamnaho da lista.
*
*  $FV Valor retornado:
*     PFN_CondRetOK
*
***********************************************************************/

   PFN_tpCondRet PFN_ContaPecas ( PFN_tppFinalizadas pFinalizadas , int * qtd_pecas ) ;

/********** Fim do módulo de definição: Módulo tabuleiro **********/


#else
#endif
