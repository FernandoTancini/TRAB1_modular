/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico DPTS
*
*  Arquivo gerado:              TestDadoPontos.C
*  Letras identificadoras:      TDPTS
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*
*	Autores:	sipf - Suemy Inagaki Pinheiro Fagundes
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data		 Observações
*       1.00   sipf   09/05/2019       Desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo testa utilizando as funções específicas do
*     módulo de DadoPontos
*
*
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo peca:
*
*       =criardadopontos         chama a função  DPTS_CriarDadoPontos
*	=destruirdadopontos      chama a função  DPTS_DestruirDadoPontos
*	=jogadordobraatualiza    chama a função  DPTS_JogadorDobraAtualiza
*	=dobrarpontuacao         chama a função  DPTS_DobrarPontuacaoAtual
*	=obterjogadordobrapts    chama a função  DPTS_ObterJogadorDobraPonto
*	=obterpontuacaopartida   chama a função  DPTS_ObterPontuacaoPartida
*
***************************************************************************/

#include<stdio.h>
#include<string.h>

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "LERPARM.H"
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "DadoPontos.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define VERMELHA  0
#define PRETA     1

#define CERTO     1
#define ERRADO    0

static const char CMD_CRIAR_DADO_PONTOS       [] = "=criardadopontos" ;
static const char CMD_DESTRUIR_DADO_PONTOS    [] = "=destruirdadopontos";
static const char CMD_JOGADOR_DOBRA_ATUALIZA  [] = "=jogadordobraatualiza";
static const char CMD_DOBRAR_PONTUACAO        [] = "=dobrarpontuacao";
static const char CMD_OBTER_JOGADOR_DOBRA_PTS [] = "=obterjogadordobrapts";
static const char CMD_OBTER_PONTUACAO_PARTIDA [] = "=obterpontuacaopartida";

/* Singleton para realização dos testes */
static PecaHead peca = NULL;

/***********************************************************************
*
*  $FC Função: TDPTS Realizar Testes Específicas para DadoPonto
*
*  $ED Descrição da função
*     Efetua os comandos de teste específicos para o módulo DadoPontos
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	 
	      int DadoPontos  = -1 ,
                  numLidos     = -1 ,
                  CondRetEsp   = -1,	  
                  Pontuacao    = -1,
                  ValEsp       = -1;
              int  ValorEsperado;
              int i;
              char CorPeca;

      DPTS_CondRet CondRetObtido   = DPTS_OK;
      DPTS_CondRet CondRetEsperado = DPTS_SemMemoria;
                                      /* inicializa para qualquer coisa */
      TST_tpCondRet Ret ;

      /* Testar PEC Criar peça */

	if(strcmp(ComandoTeste , CMD_CRIAR_DADO_PONTOS) == 0){

              numLidos = LER_LerParametros("ii", DadoPontos, &CondRetEsp);
            
	      if(numLidos != 2)
                  return TST_CondRetParm;
              
              CondRetObtido = DPTS_CriarDadoPontos(&DadoPontos);

              return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro na criação de um novo dado de pontos");
         } /* fim ativa: Testar Criar Dado de Pontos */

	/* Testar Destruir Dado de Pontos */
         else if(strcmp(ComandoTeste , CMD_DESTRUIR_DADO_PONTOS) == 0){

            numLidos = LER_LerParametros("ii" , DadoPontos, &CondRetEsp);

            if(numLidos != 2)
               return TST_CondRetParm;
            
	    CondRetObtido = DPTS_DestruirDadoPontos(&DadoPontos);

            return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao destruir Dado de Pontos.");
         } /* fim ativa: Testar Destruir Dado de Pontos */

	/* Testar Atualizar jogador de dobra */
         else if(strcmp(ComandoTeste ,CMD_JOGADOR_DOBRA_ATUALIZA) == 0){

            numLidos = LER_LerParametros("iii" , &DadoPontos, &CorPeca, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;
            
            CondRetObtido = DPTS_JogadorDobraAtualiza(DadoPontos, CorPeca);

            return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao atualizar jogador de dobra.");
         } /* fim ativa: Testar Atualizar jogador de dobra */
	
	/* Testar Dobrar pontuação da partida */
         else if(strcmp(ComandoTeste , CMD_DOBRAR_PONTUACAO) == 0){

            numLidos = LER_LerParametros("iii" , DadoPontos, &CorPeca, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;

	    CondRetObtido = DPTS_DobrarPontuacaoAtual(&DadoPontos, CorPeca);

            return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao dobrar pontuacao da partida.");
         } /* fim ativa: Dobrar pontuação da partida */



         /* Testar Obter jogador dobra partida */
         else if(strcmp(ComandoTeste , CMD_OBTER_JOGADOR_DOBRA_PTS) == 0){

            numLidos = LER_LerParametros("iii", DadoPontos, &ValorEsperado, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;

            CondRetObtido = DPTS_ObterJogadorDobraPonto(&DadoPontos, &CorPeca);
	    CondRetTesteEsperado = TST_CompararInt(CondRetEsp , CondRetObtido ,"Erro ao Obter jogador dobra da partida.");

	    if(CondRetTesteEsperado != TST_CondRetOK || CondRetObtido != DPTS_Feito)
		return CondRetTesteEsperado;

	    return TST_CompararInt(ValorEsperado, CorPeca, "Erro ao Obter jogador dobra da partida");

         }/* fim ativa: Testar Obter jogador dobra partida */



	/* Testar Obter pontuação da partida */
	else if(strcmp(ComandoTeste , CMD_OBTER_PONTUACAO_PARTIDA) == 0){

            numLidos = LER_LerParametros("iii" , DadoPontos, &ValorEsperado, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;

	    CondRetObtido = DPTS_ObterPontuacaoPartida(&DadoPontos, &Pontuacao);
	    CondRetTesteEsperado = TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao Obter pontuação da partida.");

	    if(CondRetTesteEsperado != TST_CondRetOK || CondRetObtido != DPTS_Feito)
		return CondRetTesteEsperado;
	  
	    return TST_CompararInt(ValorEsperado , Pontuacao , "Erro ao Obter pontuação da partida - valor invalido.");
         } /* fim ativa: Testar Obter pontuação da partida */

		 
      return TST_CondRetNaoConhec;

   }/* fim função: TDPTS Realizar Testes Específicas para DadoPonto */
	
/********** Fim do módulo de implementação: TDPTS Teste dado pontos **********/
