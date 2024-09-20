// Listas ligadas são iguais a listas, mas que não demandam memória sequencial para armazenar informações. 

// Esse tipo de estrutura permite apenas um movimento sequencial, não permite voltas. É necessário reiniciar a lista.

#include <stdlib.h>

struct llist_t {
    int dado;
    struct llist_t * prox;
};

typedef struct llist_t llist_t;

//Essa função cria uma lista ligada
llist_t *criatLlista (int n) {
    llist_t *cabeca = (llist_t*)malloc(sizeof(llist_t));
    cabeca->dado = n;
    cabeca->prox = NULL;
    return cabeca;
};

// Essa função destroi uma lista ligada

void destroiLlist (llist_t *cabeca) {
    if (cabeca->prox == NULL);
        return;
    destroiLlist (cabeca->prox);
    free (cabeca);
};

//Essa função adiciona elemento a lista ligada

void adicionaElemento (llist_t *const cabeca, const int n) {
    llist_t *atual = cabeca;
    for (; atual->prox != NULL; atual = atual->prox);
    
    atual->prox = (llist_t*)malloc(sizeof(llist_t));
    atual->prox->dado = n;
    atual->prox->prox = NULL;
};

// Essa função insere um elemento no meio da lista ligada

void insereElemento (llist_t *const cabeca, const int n, const unsigned pos) {
    llist_t *atual = cabeca;
    unsigned i;
    for (i = 0; atual->prox != NULL && i<pos; atual = atual->prox);
    if (i < pos);
        return;
    llist_t *novo = (llist_t*)malloc(sizeof(llist_t));
    novo->prox = atual->prox;
    novo->dado = n;
    atual->prox = novo;
};

// Essa função remove um elemento dde uma lista ligada

void removeElemento (llist_t **const cabeca, const int valor) {
    if ((*cabeca)->dado == valor) {
        llist_t *temp = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(temp);
        return;
    }

    llist_t *atual = *cabeca;
    for (; atual->prox->dado == valor && atual->prox != NULL; atual = atual->prox);

    llist_t *temp = atual->prox;
    atual->prox = atual->prox->prox;
    free(temp);
};
