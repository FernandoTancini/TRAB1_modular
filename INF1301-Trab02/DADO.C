/***************************************************************************
*
*  $MCI Modulo de implementacao: PEC Implementacao Dado
*
*  Arquivo gerado:              PECA.C
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: INF 1301
*  Autor: jfr     Júlia Affonso Figueiredo Rocha

*
*  $HA Historico de evolucao:
*     Versao   Autor    Data       Observacoes
*       1.00   jfr   01/05/2019 Inicio do desenvolvimento
*
*  $ED Descricao do modulo
*     O módulo implementa as funcoes do dado para obter o resultado de um dado lancado.
*
***************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DADO_OWN
#include "DADO.h"
#include <assert.h>
#undef DADO_OWN
#define RAN_MAX 0x7fff

/***************************************************************************

/*****  Codigo das funcoes encapsuladas no modulo  *****/

int randint(int n);

/*****  Codigo das funcoes exportadas pelo modulo  *****/

/***************************************************************************
*
*  Funcao: DAD  Jogar o dado (gera numero randomico de 1 a 6)
*  ****/

DAD_tpCondRet DAD_Jogar(int *Numero) {
	*Numero = randint(6);
	return DAD_CondRetOK;
}

/* Funcao usada pelo modulo */
/* Returns an integer in the range [1, n]*/
int randint(int n) {
  int r;
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    long end = RAND_MAX / n; // truncate skew
    assert (end > 0L);
    end *= n;
    while ((r = rand()) >= end);
    r = (r|time(NULL));
    return (r % n) +1;
  }
}

/*********** Fim do modulo de implementacao: Modulo Dado **************/
