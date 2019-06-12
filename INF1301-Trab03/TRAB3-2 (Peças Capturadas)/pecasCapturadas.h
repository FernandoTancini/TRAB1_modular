#if ! defined(PECASCAPTURADAS_)
#define PECASCAPTURADAS_

/***************************************************************************
 *
 *  $MCD Modulo de definicao: Módulo peças capturadas
 *
 *  Arquivo gerado:              PECASCAPTURADAS.H
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

#if defined(PECASCAPTURADAS_OWN)
    #define PECASCAPTURADAS_EXT
#else
    #define PECASCAPTURADAS_EXT extern
#endif

/* Tipo referência para a lista das Peças Capturadas */

typedef struct BAR_tagPecasCapturadas BAR_tpPecasCapturadas;

/***********************************************************************
 *
 *  $TC Tipo de dados: BAR Condições de retorno
 *
 ***********************************************************************/

typedef enum {
    
    BAR_CondRetOK = 0,
    /* Executou correto */
    
    BAR_CondRetErro = 1,
    /* Erro na execução */
    
    BAR_CondRetListaPecasCapturadasNaoExiste = 2,
    /* Lista de peças capturadas não existe */
    
    BAR_CondRetVazia = 3,
    /* Lista de peças capturadas não contém elementos */
    
    BAR_CondRetFaltouMemoria = 4
    /* Faltou memória ao alocar dados */
    
} BAR_tpCondRet;


/***********************************************************************
 *
 *  $FC Função: BAR Criar lista de peças capturadas
 *
 *  $ED Descrição da função
 *     Cria uma nova lista de peças capturadas.
 *
 *  $EP Parâmetros
 *     $P pPecasCapturadas - ponteiro para a lista de peças capturadas a ser criada.
 *
 *  $FV Valor retornado
 *     BAR_CondRetOK
 *     BAR_CondRetFaltouMemoria
 *
 *  Assertivas de Entrada: Deve existir um ponteiro para a lista a ser criada
 *  Assertivas de Saída:   Uma lista criada deve ser retornada pelo ponteiro recebido
 *                         no parâmetro
 *
 ***********************************************************************/

BAR_tpCondRet BAR_CriarListaPecasCapturadas(BAR_tpPecasCapturadas *pPecasCapturadas);

/***********************************************************************
 *
 *  $FC Função: BAR Inserir peça
 *
 *  $ED Descrição da função
 *     Insere uma peça na lista de peças capturadas (Barra).
 *
 *  $EP Parâmetros
 *     $P pPecasCapturadas - ponteiro para a lista de peças capturadas.
 *     $P pPeca - ponteiro para a peça a ser adicionada na Barra.
 *
 *  $FV Valor retornado
 *     BAR_CondRetOK
 *     BAR_CondRetListaPecasCapturadasNaoExiste
 *     BAR_CondRetErro
 *
 *  Assertivas de Entrada: Deve existir um ponteiro para a lista de Pecas Capturadas.
 *  Assertivas de Saída:   A barra contém uma nova peça.
 *
 ***********************************************************************/

BAR_tpCondRet BAR_InserirPeca(BAR_tpPecasCapturadas pPecasCapturadas, PCA_tpPeca *pPeca);

/***********************************************************************
 *
 *  $FC Função: BAR Remover peça
 *
 *  $ED Descrição da função
 *     Remove uma peça na lista da barra.
 *
 *  $EP Parâmetros
 *     $P pPecasCapturadas - ponteiro para a lista de peças capturadas a ser utilizada.
 *
 *  $FV Valor retornado
 *     BAR_CondRetOK
 *     BAR_CondRetListaPecasCapturadasNaoExiste
 *     BAR_CondRetFaltouMemoria
 *
 *  Assertivas de Entrada: Deve existir um ponteiro para a lista de Pecas Capturadas.
 *  Assertivas de Saída:   A barra tem uma peca a menos.
 *
 ***********************************************************************/

BAR_tpCondRet BAR_RemoverPeca(BAR_tpPecasCapturadas pPecasCapturadas);

/***********************************************************************
 *
 *  $FC Função: BAR Contar peças
 *
 *  $ED Descrição da função
 *     Conta as peças na barra.
 *
 *  $EP Parâmetros
 *     $P pPecasCapturadas - ponteiro para a lista de peças capturadas a ser utilizada.
 *     $P pContagem - ponteiro para o inteiro onde será armazenado o número de peças.
 *
 *  $FV Valor retornado
 *     BAR_CondRetOK
 *     BAR_CondRetListaPecasCapturadasNaoExiste
 *
 *  Assertivas de Entrada: Deve existir um ponteiro para a lista de Pecas Capturadas e um ponteiro para um inteiro onde será armazenado o numero de peças na barra.
 *  Assertivas de Saída:   O ponteiro de inteiro contém o número de peças na Barra.
 *
 ***********************************************************************/

BAR_tpCondRet BAR_ContarPecas(BAR_tpPecasCapturadas pPecasCapturadas, int *pContagem);

/***********************************************************************
 *
 *  $FC Função: BAR Destruir lista de peças capturadas
 *
 *  $ED Descrição da função
 *     Destrói a lista de peças capturadas.
 *
 *  $EP Parâmetros
 *     $P pPecasCapturadas - ponteiro para a lista de peças capturadas a ser destruida.
 *
 *  $FV Valor retornado
 *     BAR_CondRetOK
 *     BAR_CondRetListaPecasCapturadasNaoExiste
 *
 *  Assertivas de Entrada: Deve existir um ponteiro para a lista de Pecas Capturadas.
 *  Assertivas de Saída:   A barra foi destruida.
 *
 ***********************************************************************/

BAR_tpCondRet BAR_DestruirListaPecasCapturadas(BAR_tpPecasCapturadas pPecasCapturadas);

#undef BAR_EXT

/********** Fim do módulo de definição: Módulo peças capturadas **********/

#else
#endif
