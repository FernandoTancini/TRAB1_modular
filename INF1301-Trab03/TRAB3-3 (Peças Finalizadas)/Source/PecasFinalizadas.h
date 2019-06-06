#if ! defined( FINALIZADAS_ )
#define FINALIZADAS_

#include "PECA.h"
/*******************************************************************************************
* $MCI Módulo de definição: Módulo pecas dinalizadas
* Arquivo gerado:     PecasFinalizadas.h
* Letras identificadoras:   PFZ
*
* Projeto:            Disciplina INF 1301
*
*   Autor:                    sipf - Suemy Inagaki Pinheiro Fagundes
*
* $HA Histórico de evolução:
* Versão  Autor    Data     Observações
* 1.00    sipf   06/jun/2019 Desenvolvimento
*
*       $ED Descrição do módulo
*       Define as Funções de PecasFinalizadas
* No início de cada partida não existe pecas finalizadas
*
*****************************************************************************************/
#if defined(FINALIZADAS_OWN)
   #define FINALIZADAS_EXT
#else
   #define FINALIZADAS_EXT extern
#endif

/************************ Declarações exportadas pelo módulo ****************************/
/* Tipo de referência para uma peca fnializada*/

typedef struct PFZ_tpPecasFinalizadas* PFZ_PCabeca;

/******************************************************************************************
*
*  $TC Tipo de dados: PFZ Condicao de Retorno
*
*
****************************************************************************************/

   typedef enum {

      PFZ_OK = 0 ,
          /* Funcionou sem problemas*/

      PFZ_Memoria = 1
          /* Faltou memoria*/
         
   } PFZ_tpCondRet ;


/***********************************************************************
*
*  $FC Função: PFZ Criar
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
*     PFZ_OK
*     PFZ_Memoria
*
***********************************************************************/

   PFZ_tpCondRet PFZ_Criar( PFZ_PCabeca * pFinalizadas ) ;

/***********************************************************************
*
*  $FC Função: PFZ Destruir
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
*     PFZ_OK
*
***********************************************************************/

   PFZ_tpCondRet PFZ_Destruir( PFZ_PCabeca pFinalizadas ) ;

/***********************************************************************
*
*  $FC Função: PFZ Incluir Peça
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
*     PFZ_CondRetMemoria 
*     PFZ_CondRetOK
*
***********************************************************************/

   PFZ_tpCondRet PFZ_InserirPeca ( PFZ_PCabeca pFinalizadas , char* peca ) ;

 /***********************************************************************
*
*  $FC Função: PFZ Contar Peças
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
*     PFZ_CondRetOK
*
***********************************************************************/

   PFZ_tpCondRet PFZ_ContaPecas ( PFZ_PCabeca pFinalizadas , int * qtd_pecas ) ;

/********** Fim do módulo de definição: Módulo Peças Finalizadas **********/


#else
#endif
