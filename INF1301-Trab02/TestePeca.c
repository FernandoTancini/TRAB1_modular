/***************************************************************************
*  $MCI M�dulo de implementa��o:  Teste Peca
*
*  Arquivo gerado:                TestePeca.c
*  Letras identificadoras:        TSTP
*
*  Projeto:                       INF 1301

*  Autores:                       jfr J�lia Affonso Figueiredo Rocha
*
* $HA Hist�rico e evolu��o:
*   Vers�o  Autor	Data		Observa��es
*   1.00	jfr		05/05/2019  Implementa��o do teste
*
/ ****************************************************************************
*  Comandos Espec�ficos para testar o m�dulo	Peca.c
*       =criaPeca         chama a fun��o  PEC_CriarPeca
*		=destruirPeca	  chama a fun��o  PEC_DestruirPeca
*		=obtemCor		  chama a fun��o  PEC_ObterCor
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

/* Tabela dos nomes dos comandos de teste espec�ficos */

static const char CMD_CRIAR_PECA       [] = "=criaPeca" ;
static const char CMD_DESTRUIR_PECA    [] = "=destruirPeca";
static const char CMD_OBTER_COR  [] = "=obtemCor";


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TPEC Efetuar opera��es de teste espec�ficas para peca
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     peca sendo testado.
*
*  $EP Par�metros
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

   } /* Fim fun��o: TSTP Efetuar opera��es de teste espec�ficas para peca */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/


