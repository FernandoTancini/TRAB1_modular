#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
 *
 *  $MCD Módulo de definição: LIS  Lista duplamente encadeada
 *
 *  Arquivo gerado:              LISTA.h
 *  Letras identificadoras:      LIS
 *
 *  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
 *  Arquivo da base de software: Arcabouco
 *
 *  Projeto: INF 1301
 *  Gestor:  DI- PUC-Rio
 *  Autores: jfr
 *
 *  $HA Histórico de evolução:
 *     Versão  Autor    Data     Observaçıes
 *     1       jfr   01/jul/2019 início desenvolvimento
 *
 *  $ED Descrição do módulo
 *     Implementa listas genéricas duplamente encadeadas.
 *     Podem existir n listas em operação simultaneamente.
 *     As listas possuem uma cabeça encapsulando o seu estado.
 *
 *     Cada lista é homogÍnea quanto ao tipo dos dados que armazena.
 *     Cada elemento da lista referencia o valor que contém.
 *
 *     Os ponteiros para os dados são copiados para elementos da lista.
 *        Não é copiado o valor apontado por estes ponteiros.
 *
 *     O controle da destruição do valor de um elemento a ser excluÌdo
 *        é realizado por uma função fornecida pelo usu·rio.
 *
 *     Cada lista referencia uma função que determina como devem ser
 *        desalocados os dados nela contidos.
 *
 *     A função de liberação dos valores contidos nos elementos deve
 *        assegurar a liberação de todos os espaços referÍnciados pelo
 *        valor contido em um elemento.
 *        Esta função é chamada antes de se desalocar um elemento
 *        de uma lista.
 *        Caso não seja necess·rio desalocar o valor referenciado pelo
 *        elemento, o ponteiro para a função de liberação poder· ser NULL .
 *        Caso o elemento da lista seja a ˙nica ‚ncora do valor referenciado,
 *        esta função deve promover a destruição (free) desse valor e
 *        de todos os dados nele ancorados.
 *
 ***************************************************************************/

#if defined( LISTA_OWN )
#define LISTA_EXT
#else
#define LISTA_EXT extern
#endif

#ifdef _DEBUG
#include   "CONTA.H"
#include   "CESPDIN.H"
#include   "GENERICO.H"
#endif
/***** Declaraçıes exportadas pelo módulo *****/

/* Tipo referÍncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;


/***********************************************************************
 *
 *  $TC Tipo de dados: LIS Condiçıes de retorno
 *
 *
 pLista->pElemCorr = NULL ;
 pLista->numElem   = 0 ;

 } /* fim função: lis  -limpar a cabeça da lista */

/***********************************************************************
 *  $ED Descrição do tipo
 *     Condiçıes de retorno das funçıes da lista
 *
 ***********************************************************************/

typedef enum {

    LIS_CondRetOK ,
    /* Concluiu corretamente */

    LIS_CondRetListaVazia ,
    /* A lista não contém elementos */

    LIS_CondRetFimLista ,
    /* Foi atingido o fim de lista */

    LIS_CondRetNaoAchou ,
    /* Não encontrou o valor procurado */

    LIS_CondRetFaltouMemoria,
    /* Faltou memória ao tentar criar um elemento de lista */

    LIS_CondRetElementoCorrenteIndefinido

} LIS_tpCondRet ;

/***********************************************************************
 *
 *  $TC Tipo de dados: LIS Verifica Lista
 *
 *
 *  $ED Descrição do tipo
 *     Condiçıes de retorno das funçıes de VericaLista
 *
 ***********************************************************************/
#ifdef _DEBUG
typedef enum {
    LIS_Inexistente,
    /* A lista é inexistente */

    LIS_pCabeca,
    /*  h· uma inconsistencia em pCabeca*/

    LIS_ElemCorr,
    /* ElemCorr inconsistente */

    LIS_FimLista,
    /*Fim Lista inconsistente */

    LIS_NumeroElementosInvalidoOuPonteiros,
    /* inconsistencia entre o numero de elementos ou ponteiros */

    LIS_NumeroElementosInvalido,
    /* numero de elementos invalido */

    LIS_EncadeamentoNo,
    /* a lista não est· completamente encadeada*/

    LIS_NumeroElementos,
    /*numero de elementos incorreto*/

    LIS_Correta,
    /*lista funcionando corretamente */

    LIS_VazamentoDeMemoria
    /* lista tem vazamento de memoria */

} LIS_Verificar;
#endif

/***********************************************************************
 *
 *  $TC Tipo de dados: LIS Deturpa Lista
 *
 *
 *  $ED Descrição do tipo
 *     Condiçıes de retorno das funçıes de DeturpaLista
 *
 ***********************************************************************/

#ifdef _DEBUG
typedef enum {

    LIS_EliminaElementoCorrente,
    /* elimina o elemento corrente da lista */

    LIS_NULLpNoProximoNo,
    /* atribui NULL ao ponteiro para o próximo nó */

    LIS_NULLpNoAnt,
    /* atribui NULL ao ponteiro para o nó anterior */

    LIS_LixopNoProx,
    /* atribui lixo ao ponteiro para o próximo nó */

    LIS_LixopNoAnt,
    /* atribui lixo ao ponteiro o nó anterior */

    LIS_NULLpValorNo,
    /* atribui NULL ao ponteiro para o conte˙do do nó */

    LIS_AlteraTipoEstruturaNo,
    /* altera o tipo de estrutura apontado no nó */

    LIS_DesencadeiaNoSemFree,
    /* desencadeia nó sem liber·-lo com free */

    LIS_NULLpCorrente,
    /* atribui NULL ao ponteiro corrente */

    LIS_NULLpOrigem
    /* atribui NULL ao ponteiro de origem */

} LIS_Deturpar;
#endif
/***********************************************************************
 *
 *  $FC Função: LIS  &Criar lista
 *
 *  $ED Descrição da função
 *     Cria uma lista genérica duplamente encadeada.
 *     Os possÌveis tipos são desconhecidos a priori.
 *     A tipagem é implicita.
 *     Não existe identificador de tipo associado ‡ lista.
 *
 *  $EP Par‚metros
 *     ExcluirValor  - ponteiro para a função que processa a
 *                     exclusão do valor referenciado pelo elemento
 *                     a ser excluÌdo.
 *                     Ver descrição do módulo.
 *
 *  $FV Valor retornado
 *     Se executou corretamente retorna o ponteiro para a lista.
 *     Este ponteiro ser· utilizado pelas funçıes que manipulem esta lista.
 *
 *     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
 *     a função retornar· NULL.
 *     Não ser· dada mais informação quanto ao problema ocorrido.
 *
 ***********************************************************************/

LIS_tppLista LIS_CriarLista(
                            void   ( * ExcluirValor ) ( void * pDado ) ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Destruir lista
 *
 *  $ED Descrição da função
 *     Destrói a lista fornecida.
 *     O par‚metro ponteiro para a lista não é modificado.
 *     Se ocorrer algum erro durante a destruição, a lista resultar·
 *     estruturalmente incorreta.
 *     OBS. não existe previsão para possÌveis falhas de execução.
 *
 *  $FV Valor retornado
 *     LIS_CondRetOK    - destruiu sem problemas
 *
 ***********************************************************************/

void LIS_DestruirLista( LIS_tppLista pLista ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Esvaziar lista
 *
 *  $ED Descrição da função
 *     Elimina todos os elementos, sem contudo eliminar a lista
 *
 *  $EP Par‚metros
 *     pLista - ponteiro para a lista a ser esvaziada
 *
 ***********************************************************************/

void LIS_EsvaziarLista( LIS_tppLista pLista ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Inserir elemento antes
 *
 *  $ED Descrição da função
 *     Insere novo elemento antes do elemento corrente.
 *     Caso a lista esteja vazia, insere o primeiro elemento da lista.
 *
 *  $EP Par‚metros
 *     pLista - ponteiro para a lista onde deve ser inserido o elemento
 *     pValor - ponteiro para o valor do novo elemento
 *              Pode ser NULL
 *
 *  $FV Valor retornado
 *     LIS_CondRetOK
 *     LIS_CondRetFaltouMemoria
 *
 ***********************************************************************/

LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista ,
                                       void * pValor        ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Inserir elemento após
 *
 *  $ED Descrição da função
 *     Insere novo elemento ap·s o elemento corrente.
 *     Caso a lista esteja vazia, insere o primeiro elemento da lista.
 *
 *  $EP Par‚metros
 *     Par‚metros
 *        pLista - ponteiro para a lista onde deve ser inserido o elemento
 *        pValor - ponteiro para o valor do novo elemento
 *                 Pode ser NULL
 *
 *
 *  $FV Valor retornado
 *     Valor retornado
 *        LIS_CondRetOK
 *        LIS_CondRetFaltouMemoria
 *
 ***********************************************************************/

LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista ,
                                      void * pValor        )
;


/***********************************************************************
 *
 *  $FC Função: LIS  &Excluir elemento
 *
 *  $ED Descrição da função
 *     Exclui o elemento corrente da lista dada.
 *     Se existir o elemento aa esquerda do corrente ser· o novo corrente.
 *     Se não existir e existir o elemento ‡ direita, este se tornar· corrente.
 *     Se este também não existir a lista tornou-se vazia.
 *
 *  $EP Par‚metros
 *     pLista    - ponteiro para a lista na qual deve excluir.
 *
 *  $FV Valor retornado
 *     LIS_CondRetOK
 *     LIS_CondRetListaVazia
 *
 ***********************************************************************/

LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Obter referÍncia para o valor contido no elemento
 *
 *  $ED Descrição da função
 *     Obtem a referÍncia para o valor contido no elemento corrente da lista
 *
 *  $EP Par‚metros
 *     pLista - ponteiro para a lista de onde se quer o valor
 *
 *  $FV Valor retornado
 *     não NULL - se o elemento corrente existe
 *     NULL     - se a lista estiver vazia
 *                Pode retornar NULL se o valor inserido no elemento for NULL.
 *
 ***********************************************************************/

void * LIS_ObterValor( LIS_tppLista pLista ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Ir para o elemento inicial
 *
 *  $ED Descrição da função
 *     Torna corrente o primeiro elemento da lista.
 *     Faz nada se a lista est· vazia.
 *
 *  $EP Par‚metros
 *     pLista - ponteiro para a lista a manipular
 *
 ***********************************************************************/

void IrInicioLista( LIS_tppLista pLista ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Ir para o elemento final
 *
 *  $ED Descrição da função
 *     Torna corrente o elemento final da lista.
 *     Faz nada se a lista est· vazia.
 *
 *  $EP Par‚metros
 *     pLista - ponteiro para a lista a manipular
 *
 ***********************************************************************/

void IrFinalLista( LIS_tppLista pLista ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Avançar elemento
 *
 *  $ED Descrição da função
 *     Avança o elemento corrente numElem elementos na lista
 *     Se numElem for positivo avança em direção ao final
 *     Se numElem for negativo avança em direção ao inÌcio
 *     numElem pode ser maior do que o n˙mro de elementos existentes na
 *               direção desejada
 *     Se numElem for zero somente verifica se a lista est· vazia
 *
 *  $EP Par‚metros
 *     pLista  - ponteiro para a lista a ser manipulada
 *     numElem - o n˙mero de elementos a andar
 *
 *  $FV Valor retornado
 *     CondRetOK         - se numElem elementos tiverem sido andados
 *     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
 *                         elementos
 *     CondRetListaVazia - se a lista est· vazia
 *
 ***********************************************************************/

LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                          int numElem ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  &Procurar elemento contendo valor
 *
 *  $ED Descrição da função
 *     Procura o elemento que referencia o valor dado.
 *     A função compara ponteiro e não conte˙do apontado.
 *
 *  $EP Par‚metros
 *     pLista  - ponteiro para a lista onde procura
 *     pValor  - ponteiro para o valor procurado
 *               Pode ser NULL
 *
 *  $FV Valor retornado
 *     LIS_CondRetOK  - se encontrou.
 *                      O elemento corrente é o primeiro elemento do
 *                      elemento corrente inclusive para o fim da lista
 *                      e que contém o ponteiro procurado
 *
 *     LIS_CondRetNaoEncontrou - se o ponteiro não foi encontrado
 *                      O elemento corrente continua o mesmo
 *     LIS_CondRetListaVazia   - se a lista estiver vazia
 *
 ***********************************************************************/

LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                void * pValor        ) ;


/***********************************************************************
 *
 *  $FC Função: LIS  VerificaLista
 *
 *  $ED Descrição da função
 *     Verifica se a lista esta funcionando corretamente
 *     Retorna um erro encontrado
 *
 *  $EP Par‚metros
 *     pLista  - ponteiro para a lista onde procura
 *
 *  $FV Valor retornado
 * Erro encontrado na lista
 * Velores especificados em LIS_Verificar
 *
 ***********************************************************************/
#ifdef _DEBUG
LIS_tpCondRet LIS_DeturparLista (LIS_tppLista pLista, LIS_Deturpar acao);
#endif

/***********************************************************************
 *
 *  $FC Função: LIS  DeturparLista
 *
 *  $ED Descrição da função
 *     Produz um erro proposital na lista
 *
 *  $EP Par‚metros
 *     pLista  - ponteiro para a lista onde procura
 *     acao  - acao de deturpacao definida pelo enunciado do trabalho
 *
 *  $FV Valor retornado
 *     LIS_CondRetListaVazia - se a lista estiver vazia
 *     LIS_CondRetElementoCorrenteIndefinido - se o elemento corrente nao estiver definido
 *
 *
 ***********************************************************************/
#ifdef _DEBUG
LIS_Verificar LIS_VerificaLista (LIS_tppLista pLista);
#endif

#undef LISTA_EXT

/********** Fim do módulo de definição: LIS  Lista duplamente encadeada **********/

#else
#endif
