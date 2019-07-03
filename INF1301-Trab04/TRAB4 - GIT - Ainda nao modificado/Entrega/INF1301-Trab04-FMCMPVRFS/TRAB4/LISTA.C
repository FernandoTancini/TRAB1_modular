/***************************************************************************
 *  $MCI Módulo de implementação: LIS  Lista duplamente encadeada
 *
 *  Arquivo gerado:              LISTA.c
 *  Letras identificadoras:      LIS
 *
 *  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
 *  Arquivo da base de software: Arcabouço
 *
 *  Projeto: INF 1301
 *  Gestor:  DI - PUC-Rio
 *  Autores: jfr
 *
 *  $HA Histórico de evolução:
 *     Versão  Autor    Data           Observações
 *     5       jfr      01/jul/2019    Início desenvolvimento
 *
 ***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#define LISTA_OWN
#include "LISTA.h"
#undef LISTA_OWN

/***********************************************************************
 *
 *  $TC Tipo de dados: LIS Elemento da lista
 *
 *
 ***********************************************************************/

typedef struct tagElemLista {

    void * pValor ;
    /* Ponteiro para o valor contido no elemento */

    struct tagElemLista * pAnt ;
    /* Ponteiro para o elemento predecessor */

    struct tagElemLista * pProx ;
    /* Ponteiro para o elemento sucessor */

#ifdef _DEBUG

    LIS_tppLista * pCabeca;
    /*ponteiro para a cabeça da lista */

    int tipo;
    /* tipo do dado */

    int tam;
    /* quantidade de nos na cabeça da estrutura */
#endif


} tpElemLista ;

/***********************************************************************
 *
 *  $TC Tipo de dados: LIS Descritor da cabeça de lista
 *
 *
 ***********************************************************************/

typedef struct LIS_tagLista {

    tpElemLista * pOrigemLista ;
    /* Ponteiro para a origem da lista */

    tpElemLista * pFimLista ;
    /* Ponteiro para o final da lista */

    tpElemLista * pElemCorr ;
    /* Ponteiro para o elemento corrente da lista */

    int numElem ;
    /* N˙mero de elementos da lista */

    void ( * ExcluirValor ) ( void * pValor ) ;
    /* Ponteiro para a função de destruição do valor contido em um elemento */

#ifdef _DEBUG
    int tipo;
    /* tipo do dado */
#endif

} LIS_tpLista ;

#ifdef _DEBUG
char lixo[2] = "xxx" ;
/* Espaço de dados lixo usado ao testar */

#endif
/***** Protótipos das funções encapuladas no módulo *****/

static void LiberarElemento( LIS_tppLista   pLista ,
                            tpElemLista  * pElem   ) ;

static tpElemLista * CriarElemento( LIS_tppLista pLista ,
                                   void *       pValor  ) ;

static void LimparCabeca( LIS_tppLista pLista ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
 *
 *  Função: LIS  & Criar lista
 *  ****/

LIS_tppLista LIS_CriarLista( void   ( * ExcluirValor ) ( void * pDado ) ) {
    LIS_tpLista * pLista = NULL ;

    pLista = ( LIS_tpLista * ) malloc( sizeof( LIS_tpLista )) ;
    if ( pLista == NULL )
    {
        return NULL ;
    } /* if */

    LimparCabeca( pLista ) ;

#ifdef _DEBUG
    //    CED_MarcarEspacoAtivo(pLista);
    //    pLista->tam = 0;

#endif

    pLista->ExcluirValor = ExcluirValor ;
    return pLista ;

} /* Fim função: LIS  & Criar lista */

/***************************************************************************
 *
 *  Função: LIS  & Destruir lista
 *  ****/

void LIS_DestruirLista( LIS_tppLista pLista ){

#ifdef _DEBUG
    assert( pLista != NULL ) ;

#endif

    LIS_EsvaziarLista( pLista ) ;

    free( pLista ) ;

} /* Fim função: LIS  & Destruir lista */

/***************************************************************************
 *
 *  Função: LIS  & Esvaziar lista
 *  ****/

void LIS_EsvaziarLista( LIS_tppLista pLista ){

    tpElemLista * pElem ;
    tpElemLista * pProx ;

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    pElem = pLista->pOrigemLista ;
    while ( pElem != NULL )
    {
#ifdef _DEBUG
        CED_MarcarEspacoNaoAtivo(pElem);
#endif
        pProx = pElem->pProx ;
        LiberarElemento( pLista , pElem ) ;
        pElem = pProx ;
    } /* while */

    LimparCabeca( pLista ) ;

} /* Fim função: LIS  & Esvaziar lista */

/***************************************************************************
 *
 *  Função: LIS  & Inserir elemento antes
 *  ****/

LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista ,
                                       void * pValor        ){

    tpElemLista * pElem ;

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    /* Criar elemento a inerir antes */

    pElem = CriarElemento( pLista , pValor ) ;
    if ( pElem == NULL ){
        return LIS_CondRetFaltoumemória ;
    } /* if */

#ifdef _DEBUG
    pElem->pCabeca = pLista;
    CED_DefinirTipoEspaco(pElem, pElem->tipo); //ou
    pElem->tipo = CED_ObterTipoEspaco(pElem);
    pElem->tam = CED_ObterTamanhoValor(pElem);
    CED_MarcarEspacoAtivo(pElem);
    CED_MarcarEspacoAtivo(pValor);

    pLista->numElem = pLista->numElem + pElem->tam;
#endif

    /* Encadear o elemento antes do elemento corrente */

    if ( pLista->pElemCorr == NULL ) {
        pLista->pOrigemLista = pElem ;
        pLista->pFimLista = pElem ;
    } else {
        if ( pLista->pElemCorr->pAnt != NULL ) {
            pElem->pAnt  = pLista->pElemCorr->pAnt ;
            pLista->pElemCorr->pAnt->pProx = pElem ;
        } else {
            pLista->pOrigemLista = pElem ;
        } /* if */

        pElem->pProx = pLista->pElemCorr ;
        pLista->pElemCorr->pAnt = pElem ;
    } /* if */

    pLista->pElemCorr = pElem ;

    return LIS_CondRetOK ;

} /* Fim função: LIS  & Inserir elemento antes */

/***************************************************************************
 *
 *  Função: LIS  & Inserir elemento após
 *  ****/

LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista ,
                                      void * pValor        ){

    tpElemLista * pElem ;

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    /* Criar elemento a inserir após */

    pElem = CriarElemento( pLista , pValor ) ;
    if ( pElem == NULL ){
        return LIS_CondRetFaltoumemória ;
    } /* if */

#ifdef _DEBUG
    pElem->pCabeca = pLista;
    CED_DefinirTipoEspaco(pElem, pElem->tipo); //ou
    pElem->tipo = CED_ObterTipoEspaco(pElem);
    pElem->tam = CED_ObterTamanhoValor(pElem);
    CED_MarcarEspacoAtivo(pElem);
    CED_MarcarEspacoAtivo(pValor);

    pLista->numElem = pLista->numElem + pElem->tam;
#endif

    /* Encadear o elemento após o elemento */

    if ( pLista->pElemCorr == NULL ) {
        pLista->pOrigemLista = pElem ;
        pLista->pFimLista = pElem ;
    } else {
        if ( pLista->pElemCorr->pProx != NULL ) {
            pElem->pProx  = pLista->pElemCorr->pProx ;
            pLista->pElemCorr->pProx->pAnt = pElem ;
        } else {
            pLista->pFimLista = pElem ;
        } /* if */

        pElem->pAnt = pLista->pElemCorr ;
        pLista->pElemCorr->pProx = pElem ;

    } /* if */

    pLista->pElemCorr = pElem ;

    return LIS_CondRetOK ;

} /* Fim função: LIS  & Inserir elemento após */

/***************************************************************************
 *
 *  Função: LIS  & Excluir elemento
 *  ****/

LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ){

    tpElemLista * pElem ;

#ifdef _DEBUG
    assert( pLista  != NULL ) ;
#endif

    if ( pLista->pElemCorr == NULL ) {
        return LIS_CondRetListaVazia ;
    } /* if */

    pElem = pLista->pElemCorr ;

    /* Desencadeia ‡ esquerda */

    if ( pElem->pAnt != NULL ) {
        pElem->pAnt->pProx   = pElem->pProx ;
        pLista->pElemCorr    = pElem->pAnt ;
    } else {
        pLista->pElemCorr    = pElem->pProx ;
        pLista->pOrigemLista = pLista->pElemCorr ;
    } /* if */

    /* Desencadeia ‡ direita */

    if ( pElem->pProx != NULL ) {
        pElem->pProx->pAnt = pElem->pAnt ;
    } else {
        pLista->pFimLista = pElem->pAnt ;
    } /* if */

    LiberarElemento( pLista , pElem ) ;

    return LIS_CondRetOK ;

} /* Fim função: LIS  & Excluir elemento */

/***************************************************************************
 *
 *  Função: LIS  & Obter referÍncia para o valor contido no elemento
 *  ****/

void * LIS_ObterValor( LIS_tppLista pLista ){

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    if ( pLista->pElemCorr == NULL ) {
        return NULL ;
    } /* if */

    return pLista->pElemCorr->pValor ;

} /* Fim função: LIS  & Obter referÍncia para o valor contido no elemento */

/***************************************************************************
 *
 *  Função: LIS  & Ir para o elemento inicial
 *  ****/

void IrInicioLista( LIS_tppLista pLista ){

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    pLista->pElemCorr = pLista->pOrigemLista ;

} /* Fim função: LIS  & Ir para o elemento inicial */

/***************************************************************************
 *
 *  Função: LIS  & Ir para o elemento final
 *  ****/

void IrFinalLista( LIS_tppLista pLista ){

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    pLista->pElemCorr = pLista->pFimLista ;

} /* Fim função: LIS  & Ir para o elemento final */

/***************************************************************************
 *
 *  Função: LIS  & Avançar elemento
 *  ****/

LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                          int numElem ){

    int i ;

    tpElemLista * pElem ;

#ifdef _DEBUG
    assert( pLista != NULL ) ;
#endif

    /* Tratar lista vazia */

    if ( pLista->pElemCorr == NULL ) {

        return LIS_CondRetListaVazia ;

    } /* fim ativa: Tratar lista vazia */

    /* Tratar avançar para frente */

    if ( numElem > 0 ) {

        pElem = pLista->pElemCorr ;
        for( i = numElem ; i > 0 ; i-- ) {
            if ( pElem == NULL ) {
                break ;
            } /* if */
            pElem    = pElem->pProx ;
        } /* for */

        if ( pElem != NULL ) {
            pLista->pElemCorr = pElem ;
            return LIS_CondRetOK ;
        } /* if */

        pLista->pElemCorr = pLista->pFimLista ;
        return LIS_CondRetFimLista ;

    } /* fim ativa: Tratar avançar para frente */

    /* Tratar avançar para trás */

    else if ( numElem < 0 ) {

        pElem = pLista->pElemCorr ;
        for( i = numElem ; i < 0 ; i++ ) {
            if ( pElem == NULL ) {
                break ;
            } /* if */
            pElem    = pElem->pAnt ;
        } /* for */

        if ( pElem != NULL ) {
            pLista->pElemCorr = pElem ;
            return LIS_CondRetOK ;
        } /* if */

        pLista->pElemCorr = pLista->pOrigemLista ;
        return LIS_CondRetFimLista ;

    } /* fim ativa: Tratar avançar para tr·s */

    /* Tratar não avançar */

    return LIS_CondRetOK ;

} /* Fim função: LIS  & Avançar elemento */

/***************************************************************************
 *
 *  Função: LIS  & Procurar elemento contendo valor
 *  ****/

LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                void * pValor        ){

    tpElemLista * pElem ;

#ifdef _DEBUG
    assert( pLista  != NULL ) ;
#endif

    if ( pLista->pElemCorr == NULL ) {
        return LIS_CondRetListaVazia ;
    } /* if */

    for ( pElem  = pLista->pElemCorr ;
         pElem != NULL ;
         pElem  = pElem->pProx ) {
        if ( pElem->pValor == pValor ) {
            pLista->pElemCorr = pElem ;
            return LIS_CondRetOK ;
        } /* if */
    } /* for */

    return LIS_CondRetNaoAchou ;

} /* Fim função: LIS  & Procurar elemento contendo valor */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
 *
 *  $FC Função: LIS  -Liberar elemento da lista
 *
 *  $ED Descrição da função
 *     Elimina os espaços apontados pelo valor do elemento e o
 *     próprio elemento.
 *
 ***********************************************************************/

void LiberarElemento( LIS_tppLista   pLista ,
                     tpElemLista  * pElem   ){

    if ( ( pLista->ExcluirValor != NULL )
        && ( pElem->pValor != NULL        )) {
        pLista->ExcluirValor( pElem->pValor ) ;
    } /* if */

    free( pElem ) ;

    pLista->numElem-- ;

} /* Fim função: LIS  - Liberar elemento da lista */


/***********************************************************************
 *
 *  $FC Função: LIS  - Criar o elemento
 *
 ***********************************************************************/

tpElemLista * CriarElemento( LIS_tppLista pLista ,
                            void *       pValor  ){

    tpElemLista * pElem ;

    pElem = ( tpElemLista * ) malloc( sizeof( tpElemLista )) ;
    if ( pElem == NULL ){
        return NULL ;
    } /* if */

#ifdef _DEBUG
    CED_MarcarEspacoAtivo(pElem);
#endif
    pElem->pValor = pValor ;
    pElem->pAnt   = NULL  ;
    pElem->pProx  = NULL  ;

    pLista->numElem ++ ;

    return pElem ;

} /* Fim função: LIS  - Criar o elemento */


/***********************************************************************
 *
 *  $FC Função: LIS  - Limpar a cabeça da lista
 *
 ***********************************************************************/

void LimparCabeca( LIS_tppLista pLista ){

    pLista->pOrigemLista = NULL ;
    pLista->pFimLista = NULL ;
    pLista->pElemCorr = NULL ;
    pLista->numElem   = 0 ;

} /* Fim fun¡Ño: LIS  - Limpar a cabe¡a da lista */
/***********************************************************************
 *
 *  $FC Função: LIS  - Verifica Lista
 *
 ***********************************************************************/

#ifdef _DEBUG
LIS_Verificar LIS_VerificaLista (LIS_tppLista pLista){

    tpElemLista *pElem = NULL;
    int contaElementos = 0;
    int iterador = 1;
    void * ponteiroAux;
    // checar se a cabeça está ligada no primeiro nó, se o corrente também está, se o nó está ligado no próximo e etc.
    //se pLista == null a lista é inexistente

    // se a lista não existe
    if(pLista->pOrigemLista == NULL) {
        CNT_CONTAR("LIS_Inexistente");
        return LIS_Inexistente;

    }/* if */

    //checar se o a cabeça ta ligada no primeiro nó (pCabeca é ou não correto)
    if ((pLista->pOrigemLista == NULL && pLista->pElemCorr != NULL) || (pLista->pOrigemLista == NULL && pLista->pFimLista != NULL) || (pLista->pOrigemLista == NULL && pLista->numElem != 0) || (pLista->pOrigemLista->pAnt != NULL))
    {
        CNT_CONTAR("LIS_pCabeca");
        return LIS_pCabeca;
    } /* if */

    //checar elemento corrente existe e se esta de acordo com a lista
    if((pLista->pElemCorr == NULL && pLista->pFimLista != NULL) || (pLista->pElemCorr == NULL && pLista->pOrigemLista != NULL)){
        CNT_CONTAR("LIS_ElemCorr" );
        return LIS_ElemCorr;
    }/* if */

    //checar fimLista existe e se esta de acordo com a lista
    if((pLista->pFimLista == NULL && pLista->pElemCorr != NULL) || (pLista->pFimLista == NULL && pLista->pOrigemLista != NULL) || (pLista->pFimLista->pProx != NULL)){
        CNT_CONTAR("LIS_FimLista");
        return LIS_FimLista;
    }/* if */

    //verifica se quando só tem um elemento o numElem ta certo
    if(pLista->pOrigemLista == pLista->pFimLista && pLista->numElem != 1)
    {
        CNT_CONTAR("LIS_númeroElementosInvalidoOuPonteiros");
        return LIS_númeroElementosInvalidoOuPonteiros;
    }/*if*/

    //checar se número de elementos é > 1
    if (pLista->numElem < 1) {
        CNT_CONTAR("LIS_númeroElementosInvalido");
        return LIS_númeroElementosInvalido;
    } /* if */

    //verificar elementos da lista
    for (pElem = pLista->pOrigemLista; pElem != NULL; pElem = pElem->pProx)
    {
        CED_MarcarEspacoAtivo(pElem);

        // verificar se o elemento é o primeiro da lista ou não
        if ((pElem->pAnt != NULL && pElem != pElem->pAnt->pProx) || (pElem->pAnt == NULL && pElem != pLista->pOrigemLista))
        {
            CNT_CONTAR("LIS_EncadeamentoNo");
            return LIS_EncadeamentoNo;
        }/* if */

        // se o elemento é o ˙ltimo da lista ou não
        if ((pElem->pProx != NULL && pElem->pProx->pAnt != pElem) || (pElem->pProx != NULL && pElem != pLista->pFimLista))
        {
            CNT_CONTAR("LIS_EncadeamentoNo");
            return LIS_EncadeamentoNo;
        }/* if */
        contaElementos++;
    } /* for */

    //verifica se número de elementos esta correto
    if(pLista->numElem != contaElementos)
    {
        CNT_CONTAR("LIS_númeroElementos");
        return LIS_númeroElementos;
    }/* if */

    //verificar tipo para vazamento de memória
    CED_InicializarIteradorEspacos();
    while (iterador)
    {
        ponteiroAux = CED_ObterPonteiroEspacoCorrente();
        if(CED_EhEspacoAtivo(ponteiroAux))
        {
            CNT_CONTAR("LIS_VazamentoDememória");
            CED_TerminarIteradorEspacos() ;
            return LIS_VazamentoDememória;
        }
        iterador = CED_AvancarProximoEspaco();
    }/* while */
    CED_TerminarIteradorEspacos();

    return LIS_Correta;
}

#endif

/***********************************************************************
 *
 *  $FC Função: LIS  -  Deturpar Lista
 *
 ***********************************************************************/
#ifdef _DEBUG
LIS_tpCondRet LIS_DeturparLista (LIS_tppLista pLista, LIS_Deturpar acao){
    tpElemLista * pAuxiliar = NULL;
    tpElemLista *pAuxiliar2 = NULL;
    /*
     1 elimina o elemento corrente da lista.
     2 atribui NULL ao ponteiro para o próximo nó.
     3 atribui NULL ao ponteiro para o nó anterior.
     4 atribui lixo ao ponteiro para o próximo nó
     5 atribui lixo ao ponteiro o nó anterior.
     6 atribui NULL ao ponteiro para o conte˙do do nó.
     7 altera o tipo de estrutura apontado no nó.
     8 desencadeia nó sem liber·-lo com free
     9 atribui NULL ao ponteiro corrente
     10 atribui NULL ao ponteiro de origem.*/

    if (pLista == NULL) {
        return LIS_CondRetListaVazia;
    }
    if (pLista->pElemCorr == NULL) {
        return LIS_CondRetElementoCorrenteIndefinido ;
    }  /* if */

    switch (acao) {
            //        case LIS_NaoDeturpa :
            //            break ;
        case LIS_EliminaElementoCorrente :
            free(pLista->pElemCorr) ;
            pLista->pElemCorr = NULL ;
            pLista->numElem = pLista->numElem - 1;
            break ;

        case LIS_NULLpNoProximoNo :
            pLista->pElemCorr->pProx = NULL ;
            break ;

        case LIS_NULLpNoAnt :
            pLista->pElemCorr->pAnt = NULL ;
            break ;

        case LIS_LixopNoProx :
            pLista->pElemCorr->pProx = (tpElemLista *) lixo ;
            break ;

        case LIS_LixopNoAnt :
            pLista->pElemCorr->pAnt = (tpElemLista *) lixo ;
            break ;

        case LIS_NULLpValorNo :
            pLista->pElemCorr->pValor = NULL ;
            break ;

        case LIS_AlteraTipoEstruturaNo :
            pLista->tipo;
            break ;

        case LIS_DesencadeiaNoSemFree :
            /* Se for o ˙nico da lista*/
            if (pLista->pElemCorr->pAnt == NULL && pLista->pElemCorr->pProx == NULL) {
                pLista->pElemCorr = NULL;
                pLista->pOrigemLista = NULL;
                pLista->pFimLista = NULL;
            }/* if */

            /*se for o primeiro da lista*/
            else if (pLista->pElemCorr->pAnt == NULL) {
                pAuxiliar = pLista->pElemCorr->pProx;
                pLista->pOrigemLista = pAuxiliar;
                pLista->pElemCorr = pAuxiliar;
            }/* else if */

            /* se for o ˙ltimo elemento */
            else if (pLista->pElemCorr->pProx == NULL) {
                pAuxiliar = pLista->pElemCorr->pAnt;
                pAuxiliar->pProx = NULL;
                pLista->pFimLista = pAuxiliar;
                pLista->pElemCorr = pAuxiliar;
            } /* else if */
            /* se for no meio da lista */
            else {
                pAuxiliar = pLista->pElemCorr->pAnt;
                pAuxiliar2 = pLista->pElemCorr->pProx;

                pAuxiliar->pProx = pAuxiliar2;
                pAuxiliar2->pAnt = pAuxiliar;
                pLista->pElemCorr = pAuxiliar;
            }

            pLista->numElem-- ;
            break ;

        case LIS_NULLpCorrente :
            pLista->pElemCorr = NULL ;
            break ;

        case LIS_NULLpOrigem :
            pLista->pOrigemLista = NULL ;
            break ;

    } /* switch */
    return LIS_CondRetOK;
}
#endif


/********** Fim do módulo de implementação: LIS  Lista duplamente encadeada **********/
