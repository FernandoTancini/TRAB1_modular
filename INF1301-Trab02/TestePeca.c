/***************************************************************************
*  $MCI Módulo de implementação:  Teste Peca
*
*  Arquivo gerado:                TestePeca.c
*  Letras identificadoras:        TSTP
*
*  Projeto:                       INF 1301

*  Autores:                       jfr Júlia Affonso Figueiredo Rocha
*
* $HA Histórico e evolução:
*   Versão  Autor	Data		Observações
*   1.00	jfr		05/05/2019  Implementação do teste
*
/ ****************************************************************************
*  Comandos Específicos para testar o módulo	Peca.c
*       =criaPeca         chama a função  PEC_CriarPeca
*		=destruirPeca	  chama a função  PEC_DestruirPeca
*		=obtemCor		  chama a função  PEC_ObterCor
*
/***************************************************************************/


#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "LERPARM.H"
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "Peca.h"
extern "C" BOOL DeregisterEventSource ( HANDLE hEventLog );

/* Tabela dos nomes dos comandos de teste específicos */

static const char CMD_CRIAR_PECA       [] = "=criaPeca" ;
static const char CMD_DESTRUIR_PECA    [] = "=destruirPeca";
static const char CMD_OBTER_COR  [] = "=obtemCor";


/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPEC Efetuar operações de teste específicas para peca
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     peca sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste ) {

      PEC_tpCondRet CondRetObtido   = PEC_CondRetOK ;
      PEC_tpCondRet CondRetEsperada = PEC_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar PEC Criar Peca */

         if ( strcmp( ComandoTeste , CMD_CRIAR_PECA ) == 0 ) {

            NumLidos = LER_LerParametros( "ici" , &peca, &cor
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PEC_CriarPeca(&peca, cor) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar peca." );

         } /* fim ativa: Testar PEC Criar peca */

      /* Testar PEC Destruir peca */

         else if ( strcmp( ComandoTeste , CMD_DESTRUIR_PECA ) == 0 ) {

			NumLidos = LER_LerParametros( "i" , &peca) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            PEC_DestruirPeca(peca) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar PEC Destruir peca */

	  /* Testar PEC Obter Cor */

         if ( strcmp( ComandoTeste , CMD_OBTER_COR ) == 0 ) {

            NumLidos = LER_LerParametros( "ici" , &peca, &cor
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PEC_ObterCor(&peca, &cor) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter cor." );

         } /* fim ativa: Testar PEC Obter cor */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TSTP Efetuar operações de teste específicas para peca */

/********** Fim do módulo de implementação: Módulo de teste específico **********/


