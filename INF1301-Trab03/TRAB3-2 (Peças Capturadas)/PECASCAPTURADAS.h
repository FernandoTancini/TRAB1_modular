#if ! defined(PECASCapturadas_)
#define PECASCapturadas_

#include "PECA.h"

#include "LISTA.h"

/***************************************************************************
*
*  $MCD Módulo de definição: Módulo peças Capturadas
*
*  Arquivo gerado:              PecasCapturadas.h
*  Letras identificadoras:      BAR
*
*  Projeto: Disciplina INF 1301
*
*  Autores: sipf - Suemy Inagaki Pinheiro Fagundes
*
*  $HA Histórico de evolução:
*     Versão       Autor          Data          Observações
*       1.00       sipf        09/jun/2019   Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa funções do módulo de peças Capturadas
*     Não existe peças Capturadas no inicio do programa
*
***************************************************************************/
 
#if defined(PECASCapturadas_OWN)
   #define PECASCapturadas_EXT
#else
   #define PECASCapturadas_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista de peças Capturadas */

typedef struct BAR_tagPecasCapturadas* BAR_tpPecasCapturadas;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         BAR_OK = 0,
               /* Executou correto */

		   BAR_NaoExisteLista = 1,
			   /* Lista de peças Capturadas não existe */

         BAR_SemMemoria = 2,
               /* Faltou memória ao alocar dados */
         BAR_CondRetVazia = 3,
         /*Não tem peças na lista*/

   } BAR_tpCondRet;


/***********************************************************************
*
*  $FC Função: BAR Criar lista de peças Capturadas
*
*  $ED Descrição da função
*     Cria uma nova lista de peças Capturadas.
*
*  $EP Parâmetros
*     $P pPecasCapturadas - ponteiro para a lista de peças Capturadas a ser criada. Passado por referência.
*
*  $FV Valor retornado
*     BAR_OK
*     BAR_SemMemoria
*
***********************************************************************/

   BAR_tpCondRet BAR_CriarListaPecasCapturadas(BAR_tpPecasCapturadas *pPecasCapturadas);

/***********************************************************************
*
*  $FC Função: BAR Inserir peça
*
*  $ED Descrição da função
*     Insere uma peça na lista de peças Capturadas.
*
*  $EP Parâmetros
*     $P pPecasCapturadas - ponteiro para a lista de peças Capturadas a ser utilizada.
*     $P pPeca - ponteiro para a peça a ser utilizada.
*
*  $FV Valor retornado
*     BAR_OK
*     BAR_NaoExisteLista
*	  BAR_SemMemoria
*
***********************************************************************/

   BAR_tpCondRet BAR_InserirPeca(BAR_tpPecasCapturadas pPecasCapturadas, tppPeca pPeca);

/***********************************************************************
*
*  $FC Função: BAR Contar peças
*
*  $ED Descrição da função
*     Conta as peças de uma determinada cor na lista de peças Capturadas
*
*  $EP Parâmetros
*     $P pPecasCapturadas - ponteiro para a lista de peças Capturadas a ser utilizada.
*     $P CorPeca - cor das peças a serem contadas.
*     $P pContagem - ponteiro para o inteiro onde será armazenado o número de peças.
*
*  $FV Valor retornado
*     BAR_OK
*	  BAR_NaoExisteLista
*
***********************************************************************/

   BAR_tpCondRet BAR_ContarPecas(BAR_tpPecasCapturadas pPecasCapturadas, PEC_CorDaPeca  CorPeca, int *pContagem);

/***********************************************************************
*
*  $FC Função: BAR Destruir lista de peças Capturadas
*
*  $ED Descrição da função
*     Destrói a lista de peças Capturadas.
*
*  $EP Parâmetros
*     $P pPecasCapturadas - ponteiro para a lista de peças Capturadas a ser utilizada. Passado por referência.
*
*  $FV Valor retornado
*     BAR_OK
*	  BAR_NaoExisteLista
*
***********************************************************************/

   BAR_tpCondRet BAR_DestruirListaPecasCapturadas(BAR_tpPecasCapturadas *pPecasCapturadas);

   BAR_tpCondRet BAR_RemoverPeca(BAR_tpPecasCapturadas pPecasCapturadas, PEC_CorDaPeca  CorPeca);

#undef BAR_EXT

/********** Fim do módulo de definição: Módulo peças Capturadas **********/

#else
#endif
