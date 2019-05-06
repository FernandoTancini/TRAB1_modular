/***************************************************************************
*  $MCI Módulo de implementação:  Teste dado 
*
*  Arquivo gerado:                TestDado.c
*  Letras identificadoras:        TSTD
*
*  Projeto:                       INF 1301

*  Autores:                       jfr Júlia Affonso Figueiredo Rocha
*
* $HA Histórico e evolução:
*   Versão  Autor	Data		Observações
*   1.00	jfr		05/05/2019  Implementação do teste
*
***************************************************************************
*  Comandos Específicos para testar o módulo	Dado.c
*
*       =jogar         chama a função  DAD_Jogar
*
***************************************************************************/


#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "LERPARM.h"
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "Dado.h"
extern "C" BOOL DeregisterEventSource ( HANDLE hEventLog );

/* Tabela dos nomes dos comandos de teste específicos */

static const char CMD_JOGAR       [] = "=jogar" ;


/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPEC Efetuar operações de teste específicas para dado
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     dado sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste ) {

      PEC_tpCondRet CondRetObtido   = DAD_CondRetOK ;
      PEC_tpCondRet CondRetEsperada = DAD_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar DAD Jogar */

         if ( strcmp( ComandoTeste , CMD_JOGAR ) == 0 ) {

            NumLidos = LER_LerParametros( "ii" , &numero,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PEC_Jogar(&numero) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao jogar dado." );

         } /* fim ativa: Testar DAD jogar dado */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TSTP Efetuar operações de teste específicas para dado */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
