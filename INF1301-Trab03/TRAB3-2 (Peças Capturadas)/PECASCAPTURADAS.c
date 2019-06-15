/***************************************************************************
*  $MCI Módulo de implementação: Módulo peças capturadas
*
*  Arquivo gerado:              PECASCAPTURADAS.C
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: INF 1301
*  Autor: jfr     Júlia Affonso Figueiredo Rocha
*
*  $HA Historico de evolucao:
*     Versao   Autor    Data       Observacoes
*       1.00   jfr   07/06/2019 Inicio do desenvolvimento
*
*  $ED Descricao do modulo
*     O módulo implementa as funcoes de existencia e manutencao da Barra de Pecas Capturadas.
*
***************************************************************************/

#include   <stdlib.h>
#include   <stdio.h>

#define PECASCAPTURADAS_OWN
#include "pecasCapturadas.h"
#undef PECASCAPTURADAS_OWN
#include "PECA.h"
#include "LISTA.H"

/***********************************************************************
*
*  $TC Tipo de dados: BAR Descritor da barra de peça capturadas
*
***********************************************************************/

typedef struct BAR_tagPecasCapturadas {

	LIS_tppLista listaPecas;
	/* Lista de Peças Capturadas */
    
    int tamanho;
    /* Número de elementos na Barra*/

} BAR_tpPecasCapturadas;

/*****  Código das funções exportadas pelo módulo  *****/


/***************************************************************************
*
*  Função: BAR Criar lista de peças capturadas
*
*/
BAR_tpCondRet BAR_CriarPecasCapturadas(BAR_tpPecasCapturadas **pPecasCapturadas) {

	*pPecasCapturadas = (BAR_tpPecasCapturadas *) malloc(sizeof(BAR_tpPecasCapturadas));
    
	if(*pPecasCapturadas == NULL) {
        
		return BAR_CondRetFaltouMemoria ;
        
	} /* if */
    
	(*pPecasCapturadas)->listaPecas = LIS_CriarLista(PEC_DestruirPeca);
    (*pPecasCapturadas)->tamanho = 0;

	return BAR_CondRetOK ;

}

/***************************************************************************
*
*  Função: BAR Inserir peça
*
*/
BAR_tpCondRet BAR_AdicionarPeca(BAR_tpPecasCapturadas *pPecasCapturadas, tppPeca pPeca) {
    
    if(pPecasCapturadas->listaPecas == NULL) {
        
		return BAR_CondRetListaPecasCapturadasNaoExiste;
        
	} /* if */

    if (LIS_InserirElementoAntes(pPecasCapturadas->listaPecas, pPeca) != LIS_CondRetOK) {
        
        return BAR_CondRetErro;
    }

    pPecasCapturadas->tamanho++;
    
	return BAR_CondRetOK;

}

/***************************************************************************
*
*  Função: BAR Remover peça
*
*/
BAR_tpCondRet BAR_RemoverPeca(BAR_tpPecasCapturadas *pPecasCapturadas) {
    
    if (pPecasCapturadas->listaPecas == NULL) {
        return BAR_CondRetVazia;
    }
    
    if(LIS_ExcluirElemento(pPecasCapturadas->listaPecas) != LIS_CondRetOK) {
        
        return BAR_CondRetErro;
    }
    pPecasCapturadas->tamanho--;
    
    return BAR_CondRetOK;
}

/***************************************************************************
*
*  Função: BAR Conta peças
*
*/
BAR_tpCondRet BAR_ContarPecas(BAR_tpPecasCapturadas *pPecasCapturadas, int *pContagem) {


    if(pPecasCapturadas->listaPecas == NULL) {
		return BAR_CondRetListaPecasCapturadasNaoExiste;
	} /* if */

    *pContagem = pPecasCapturadas->tamanho;

	return BAR_CondRetOK ;

}

/***************************************************************************
*
*  Função: BAR Destruir lista de peças capturadas
*
*/
BAR_tpCondRet BAR_DestruirPecasCapturadas(BAR_tpPecasCapturadas *pPecasCapturadas) {
    
    LIS_DestruirLista(pPecasCapturadas->listaPecas);
    
	free(pPecasCapturadas);
    
	pPecasCapturadas = NULL;

	return BAR_CondRetOK ;

}

/********** Fim do módulo de implementação: Módulo Peças Capturadas **********/
