#if ! defined(DadoPontos_)
#define DadoPontos_

#include "PECA.h"
/*******************************************************************************************
*	$MCI Módulo de definição: Módulo dado pontos
*	Arquivo gerado:		  DadoPontos.h
*	Letras identificadoras:	  DPTS
*
*	Projeto:	          Disciplina INF 1301
*
*  	Autor:                    sipf - Suemy Inagaki Pinheiro Fagundes
*
*	$HA Histórico de evolução:
*	Versão  Autor    Data     Observações
*	1       sipf   30/abr/2019 início desenvolvimento
*
*       $ED Descrição do módulo
*       Define as Funções de DadoPontos.
*	No início de cada partida não existe dado de pontos
*
*****************************************************************************************/

#if defined(DadoPontos_OWN)
   #define DadoPontos_EXT
#else
   #define DadoPontos_EXT extern
#endif


/************************ Declarações exportadas pelo módulo ****************************/


/* Tipo de referência para um dado de pontos*/

typedef struct DPTS_tpDadoPontos DPTS_tpDadoPontos;




/******************************************************************************************
*
*  $TC Tipo de dados: DPTS Condicao de Retorno
*
*
****************************************************************************************/

typedef enum {
   	 DPTS_FaltouMemoria = -1,
          /* Faltou  memoria ao tentar alocar */

         DPTS_Feito = 0,
          /* Dado Criado corretamente */

	 DPTS_DadoPontosNaoExiste = 1,
	  /* Dado de pontos não existe */

	 DPTS_JogadorNaoTemDadoPontos = 2,
	  /* Jogador não tem dado de pontos no momento */

	 DPTS_NaoExisteJogadorComDadoPontos = 3,
	  /* Não existe jogador atual com dado de pontos */

 }DPTS_CondRet;


 /*****************************************************************************************
*
*  $FC Função: DPTS Criar Dado Pontos
*
*  $ED Descrição da função
*     Cria um dado de pontos.
*
*  $EP Parâmetros
*     $P pDadoPontos - Ponteiro para o Dado de Pontos.
*                    - Passado por Referência.
*
*  $FV Valor retornado
*     DPTS_Feito
*     DPTS_FaltouMemoria
*
*****************************************************************************************/

DPTS_CondRet DPTS_CriarDadoPontos(DPTS_tpDadoPontos **pDadoPontos);


/*****************************************************************************************
*
*  $FC Função: DPTS Jogador Dobra Atualiza
*
*  $ED Descrição da função
*     Atualiza o jogador que pode dobrar a pontuacao da partida.
*
*  $EP Parâmetros
*     $P pDadoPontos - ponteiro para o dado de pontos.
*     $P CorPeca - char que representa a cor do jogador.
*
*  $FV Valor retornado
*     DPTS _Feito
*     DPTS_DadoPontosNaoExiste
******************************************************************************************/

DPTS_CondRet DPTS_JogadorDobraAtualiza(DPTS_tpDadoPontos *pDadoPontos, char CorPeca);


/*****************************************************************************************
*
*  $FC Função: DPTS Dobrar pontuação Atual
*
*  $ED Descrição da função
*     Dobra o valor da pontuação da partida.
*
*  $EP Parâmetros
*     $P pDadoPontos - ponteiro para o dado de pontos.
*     $P CorPeca - char que representa a cor do jogador.
*
*  $FV Valor retornado
*     DPTS_Feito
*     DPTS_DadoPontosNaoExiste
*     DPTS_JogadorNaoTemDadoPontos
*
******************************************************************************************/

DPTS_CondRet DPTS_DobrarPontuacaoAtual(DPTS_tpDadoPontos *pDadoPontos, char CorPeca);


/*****************************************************************************************
*
*  $FC Função: DPTS Obter jogador Dobra Ponto
*
*  $ED Descrição da função
*     Obtém o jogador que pode dobrar a pontuacao da partida.
*
*  $EP Parâmetros
*     $P pDadoPontos - ponteiro para o dado de pontos.
*     $P pCorPeca - ponteiro que vai obter por referencia a cor do jogador que pode dobrar a pontuacao da partida.
*
*  $FV Valor retornado
*     DPTS_Feito
*     DPTS_DadoPontosNaoExiste
*     DPTS_NaoExisteJogadorComDadoPontos
*
******************************************************************************************/

DPTS_CondRet DPTS_ObterJogadorDobraPonto(DPTS_tpDadoPontos *pDadoPontos, char *pCorPeca);



/*****************************************************************************************
*
*  $FC Função: DPTS Obter Pontuação Partida
*
*  $ED Descrição da função
*     Obtém a pontuação atual da partida
*
*  $EP Parâmetros
*     $P pDadoPontos - ponteiro para o dado de pontos.
*     $P pPonto - Ponteiro que vai obter por referencia a pontuacao atual da partida.
*
*  $FV Valor retornado
*     DPTS_Feito
*     DPTS_DadoPontosNaoExiste
*
******************************************************************************************/

DPTS_CondRet DPTS_ObterPontuacaoPartida(DPTS_tpDadoPontos *pDadoPontos, int *pPonto);


/*****************************************************************************************
*
*  $FC Função: DPT Destruir dado de pontos
*
*  $ED Descrição da função
*     Destrói a peça.
*
*  $EP Parâmetros
*     $P pDadoPontos - ponteiro para o dado de pontos a ser destruído 
*                    - Passado por referência
*
*  $FV Valor retornado
*     DPTS_Feito
*     DPTS_DadoPontosNaoExiste
*
*******************************************************************************************/

DPTS_CondRet DPTS_DestruirDadoPontos(DPTS_tpDadoPontos **pDadoPontos);

#undef DadoPontos_EXT

/***************** Fim do módulo de definição: Módulo Dado Pontos **********************/
#else
#endif
