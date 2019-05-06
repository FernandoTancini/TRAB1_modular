/***************************************************************************
*  $MCI Módulo de implementação:  Teste dado pontos
*
*  Arquivo gerado:                TestDadoPontos.c
*  Letras identificadoras:        TDPTS
*
*  Projeto:                       Disciplina INF 1301

*  Autores:                       sipf - Suemy Inagaki Pinheiro Fagundes
*
* $HA Histórico e evolução:
*   Versão  Autor Data    Observações
*   1.00  sipf  05/05/2019  Implementação do teste
*
*
*  Comandos Específicos para testar o módulo DadoPontos.c
*       =criardadopontos         chama a função  DPTS_CriarDadoPontos
*	=destruirdadopontos      chama a função  DPTS_DestruirDadoPontos
*	=jogadordobraatualiza    chama a função  DPTS_JogadorDobraAtualiza
*	=dobrarpontuacao         chama a função  DPTS_DobrarPontuacaoAtual
*	=obterjogadordobrapts    chama a função  DPTS_ObterJogadorDobraPonto
*	=obterpontuacaopartida   chama a função  DPTS_ObterPontuacaoPartida
*	=apagateste              apaga o vetor com os dados criados
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "LERPARM.H"
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "DadoPontos.h"

static const char CMD_CRIAR_DADO_PONTOS       [] = "=criardadopontos" ;
static const char CMD_DESTRUIR_DADO_PONTOS    [] = "=destruirdadopontos";
static const char CMD_JOGADOR_DOBRA_ATUALIZA  [] = "=jogadordobraatualiza";
static const char CMD_DOBRAR_PONTUACAO        [] = "=dobrarpontuacao";
static const char CMD_OBTER_JOGADOR_DOBRA_PTS [] = "=obterjogadordobrapts";
static const char CMD_OBTER_PONTUACAO_PARTIDA [] = "=obterpontuacaopartida";
static const char RESET_DADOPONTOS_CMD        [] = "=apagateste";

#define VERMELHA  0
#define PRETA     1

#define CERTO     1
#define ERRADO    0

#define EMPTY     0
#define N_EMPTY   1

#define TAM       10
#define TAM_VAL   100

DPTS_tpDadoPontos  *vDadoPontos[TAM];

/************************* Protótipos das funções ************************/

   static void DestruirValor(void * pVal);

   static int ValidarQtdDadoPontos(int iDadoPontos , int mod);

/***********************************************************************
*
*  $FC Função: TDPTS - Validar quantidade de dado de pontos
* 
*  Podem ser criados até TAM dados pontos
*
***********************************************************************/

   int ValidarQtdDadoPontos(int iDadoPontos , int mod){
      if((iDadoPontos <  0)|| (iDadoPontos >= TAM))
         return ERRADO;
      if(mod == EMPTY)
         if(vDadoPontos[iDadoPontos] != 0)
            return ERRADO;
      else
         if(vDadoPontos[iDadoPontos] == 0)
            return ERRADO;       
      return CERTO;

   } /* Fim função: TDPTS - Validar quantidade de dado de pontos */


/***********************************************************************
*
*  $FC Função: TDPTS Realizar Testes Específicas para DadoPonto
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste){
      
       int iDadoPontos  = -1 ,
           numLidos   = -1 ,
           CondRetEsp = -1,	  
           Pontuacao = -1,
           ValEsp = -1;
       int  ValorEsperado;
       int i;
       char CorPeca;

      DPTS_CondRet CondRetObtido   = DPTS_Feito;
      DPTS_CondRet CondRetEsperado = DPTS_Feito;
      TST_tpCondRet CondRetTesteEsperado;


      /* Apaga o vetor de dados de pontos desalocando*/

         if(strcmp(ComandoTeste , RESET_DADOPONTOS_CMD) == 0){
            for(i = 0; i < TAM; i++){
	       CondRetObtido = DPTS_DestruirDadoPontos(&vDadoPontos[i]);
               vDadoPontos[i] = NULL;
            }
	    return TST_CompararInt(CondRetEsperado , CondRetObtido , "Retorno errado ao destruir dado de pontos.");
         } /* fim ativa: Apagar o vetor de dados de pontos desalocando*/



      /* Testar Criar Dado de Pontos */
         else if(strcmp(ComandoTeste , CMD_CRIAR_DADO_PONTOS) == 0){

              numLidos = LER_LerParametros("ii", &iDadoPontos, &CondRetEsp);
            
	      if((numLidos != 2) || (! ValidarQtdDadoPontos(iDadoPontos , EMPTY)))
                  return TST_CondRetParm;
              
              CondRetObtido = DPTS_CriarDadoPontos(&vDadoPontos[iDadoPontos]);

              return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro na criação de um novo dado de pontos");
         } /* fim ativa: Testar Criar Dado de Pontos */



      /* Testar Destruir Dado de Pontos */
         else if(strcmp(ComandoTeste , CMD_DESTRUIR_DADO_PONTOS) == 0){

            numLidos = LER_LerParametros("ii" ,&iDadoPontos, &CondRetEsp);

            if(numLidos != 2)
               return TST_CondRetParm;
            
	    CondRetObtido = DPTS_DestruirDadoPontos(&vDadoPontos[iDadoPontos]);

            return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao destruir Dado de Pontos.");
         } /* fim ativa: Testar Destruir Dado de Pontos */



       /* Testar Atualizar jogador de dobra */
         else if(strcmp(ComandoTeste ,CMD_JOGADOR_DOBRA_ATUALIZA) == 0){

            numLidos = LER_LerParametros("iii" , &iDadoPontos, &CorPeca, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;
            
            CondRetObtido = DPTS_JogadorDobraAtualiza(vDadoPontos[iDadoPontos], CorPeca);

            return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao atualizar jogador de dobra.");
         } /* fim ativa: Testar Atualizar jogador de dobra */



       /* Testar Dobrar pontuação da partida */
         else if(strcmp(ComandoTeste , CMD_DOBRAR_PONTUACAO) == 0){

            numLidos = LER_LerParametros("iii" , &iDadoPontos, &CorPeca, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;

	    CondRetObtido = DPTS_DobrarPontuacaoAtual(vDadoPontos[iDadoPontos], CorPeca);

            return TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao dobrar pontuacao da partida.");
         } /* fim ativa: Dobrar pontuação da partida */



         /* Testar Obter jogador dobra partida */
         else if(strcmp(ComandoTeste , CMD_OBTER_JOGADOR_DOBRA_PTS) == 0){

            numLidos = LER_LerParametros("iii", &iDadoPontos, &ValorEsperado, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;

            CondRetObtido = DPTS_ObterJogadorDobraPonto(vDadoPontos[iDadoPontos], &CorPeca);
	    CondRetTesteEsperado = TST_CompararInt(CondRetEsp , CondRetObtido ,"Erro ao Obter jogador dobra da partida.");

	    if(CondRetTesteEsperado != TST_CondRetOK || CondRetObtido != DPTS_Feito)
		return CondRetTesteEsperado;

	    return TST_CompararInt(ValorEsperado, CorPeca, "Erro ao Obter jogador dobra da partida");

         }/* fim ativa: Testar Obter jogador dobra partida */



	/* Testar Obter pontuação da partida */
	else if(strcmp(ComandoTeste , CMD_OBTER_PONTUACAO_PARTIDA) == 0){

            numLidos = LER_LerParametros("iii" , &iDadoPontos, &ValorEsperado, &CondRetEsp);

            if(numLidos != 3)
               return TST_CondRetParm;

	    CondRetObtido = DPTS_ObterPontuacaoPartida(vDadoPontos[iDadoPontos], &Pontuacao);
	    CondRetTesteEsperado = TST_CompararInt(CondRetEsp , CondRetObtido, "Erro ao Obter pontuação da partida.");

	    if(CondRetTesteEsperado != TST_CondRetOK || CondRetObtido != DPTS_Feito)
		return CondRetTesteEsperado;
	  
	    return TST_CompararInt(ValorEsperado , Pontuacao , "Erro ao Obter pontuação da partida - valor invalido.");
         } /* fim ativa: Testar Obter pontuação da partida */

		 
      return TST_CondRetNaoConhec;

   }/* fim função: TDPTS Realizar Testes Específicas para DadoPonto */
	
/********** Fim do módulo de implementação: TDPTS Teste dado pontos **********/
