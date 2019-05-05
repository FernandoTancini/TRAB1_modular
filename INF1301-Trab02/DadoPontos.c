/***************************************************************************
*  $MCI Módulo de implementação: DPTS Módulo Dado de Pontos
*
*  Arquivo gerado:              DadoPontos.c
*  Letras identificadoras:      DPTS
*
*
*  Projeto: Disciplina INF 1301
* 
*  Autores: ft   - Fernando Tancini
*			jr	 - Júlia Rocha
*			sipf - Suemy Inagaki Pinheiro Fagundes
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       sipf   30/abr/2019 início desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define DadoPontos_OWN
#include "DadoPontos.h"
#undef DadoPontos_OWN


/***********************************************************************
*
*  $TC Tipo de dados: DPTS Descritor do dado de pontos
*
*  $ED Descrição do tipo
*		Descreve a organização de um dado de pontos
***********************************************************************/
typedef struct DPTS_tpDadoPontos
{

	int Ponto;
	/* Pontuação  do jogo no momento*/

	int CorPeca;
	/*Cor do jogador que pode dobrar a pontuacao do jogo*/

} DPTS_tpDadoPontos;

/***************************************************************************
*
*  Função: DPTS Criar Dado  Pontos
* 
***************************************************************************/
DPTS_CondRet DPTS_CriarDadoPontos(DPTS_tpDadoPontos **pDadoPontos)
{
	*pDadoPontos = (DPTS_DadoPontos *) malloc(sizeof(DPTS_DadoPontos));
	if(*pDadoPontos == NULL)
	{
		return DPTS_FaltouMemoria ;
	} 

	(*pDadoPontos)->Ponto = 1;

	return DPTS_Feito ;

} /* Fim função: DPTS Criar Dado Pontos */


/***************************************************************************
*
*  Função: DPTS Jogador Dobra Atualiza
*  
***************************************************************************/
DPTS_CondRet DPTS_JogadorDobraAtualiza(DPTS_tpDadoPontos *pDadoPontos, int CorPeca)
{
	if(pDadoPontos == NULL) 
	{
		return DPTS_DadoPontosNaoExiste;
	} 

	pDadoPontos->CorPeca = CorPeca;

	return DPTS_Feito;

} /* Fim função: DPTS Jogador Dobra Atualiza */


/***************************************************************************
*
*  Função: DPTS Dobrar Pontuacao Atual
*  
****************************************************************************/
DPTS_CondRet DPTS_DobrarPontuacaoAtual(DPTS_DadoPontos *pDadoPontos, int CorPeca)
{
	if(pDadoPontos == NULL) 
	{
		return  DPTS_DadoPontosNaoExiste;
	} 
	if(pDadoPontos->CorPeca != CorPeca)
	{
		return DPTS_JogadorNaoTemDadoPontos;
	}

	pDadoPontos->Ponto *= 2;

	return DPTS_Feito ;
}/* Fim função:  DPTS Dobrar Pontuacao Atual*/


/***************************************************************************
*
*  Função: DPTS Obter jogador Dobra Ponto
*  
*****************************************************************************/
DPTS_CondRet DPTS_ObterJogadorDobraPonto(DPTS_DadoPontos *pDadoPontos, int *pCorPeca)
{
	if(pDadoPontos == NULL)
	{
		return DPTS_DadoPontosNaoExiste;
	}

	if(pDadoPontos->Ponto == 1)
	{
		return DPTS_NaoExisteJogadorComDadoPontos;
	}

	*pCorPeca = pDadoPontos->CorPeca;

	return DPTS_Feito ;
} /* Fim função:  DPTS Obter jogador Dobra Ponto*/



/***************************************************************************
*
*  Função: DPTS Obter pontuação partida
*  
****************************************************************************/
DPTS_CondRet DPTS_ObterPontuacaoPartida(DPTS_DadoPontos *pDadoPontos, int *pPonto)
{
	if(pDadoPontos == NULL) 
	{
		return DPTS_DadoPontosNaoExiste;
	}

	*pPonto = pDadoPontos->Ponto;

	return DPTS_Feito ;
} /* Fim função:  DPTS Obter pontuação partida*/

/***************************************************************************
*
*  Função: DPTS Destruir dado de pontos
*  
***************************************************************************/
DPTS_CondRet DPTS_DestruirDadoPontos(DPTS_DadoPontos **pDadoPontos)
{
	if(*pDadoPontos == NULL) 
	{
		return DPTS_DadoPontosNaoExiste;
	} 

	free(*pDadoPontos);
	*pDadoPontos = NULL;

	return DPTS_Feito;

} /* Fim função: DPTS Destruir dado de pontos */

/********** Fim do módulo de implementação: Módulo Dado de Pontos **********/

