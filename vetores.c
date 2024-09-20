// Estruturas de dados

// ARRAY: Série de elementos armazenada em sequência na memória, de tamanho constante. 

// VETOR: Array que pode ter tamanho variável, inserir elementos e removê-los

#include <stdlib.h>
struct vetor_int_t {
    int *array;
    unsigned long tamanho;
};
typedef struct vetor_int_t vetor_int_t;

// Essa função cria um vetor vazio de tamanho 0 inicial
vetor_int_t *criarVetor() {
    vetor_int_t *vetor = (vetor_int_t*)malloc(sizeof(vetor_int_t));
    vetor->array = NULL;
    vetor->tamanho = 0;
    return vetor;

}

// Essa função adiciona elementos à um vetor, seja ele vazio ou que já contenha elementos, ao fim dele
void adicionarElemento(vetor_int_t * const vetor, const int elemento) {
    if (vetor->array == NULL) {
        vetor->array = (int*)malloc(sizeof(int));
        vetor->array[0] = elemento;
        vetor->tamanho++;
        return;
    }
    vetor->array = realloc(vetor->array, (++vetor->tamanho)*sizeof(int));
    vetor->array[vetor->tamanho - 1] = elemento;
}

// Essa função permite adicionar elementos no meio de um vetor
void inserirElemento(vetor_int_t * const vetor, const unsigned long posicao, const int elemento) {
    if (vetor->array == NULL) {
        vetor->array = (int*)malloc(sizeof(int));
        vetor->array[0] = elemento;
        vetor->tamanho++;
        return;
    }
    if (posicao > vetor->tamanho) {
        return;
    }
    vetor->array = realloc(vetor->array, (++vetor->tamanho)*sizeof(int));
    for (unsigned long i = vetor->tamanho - 1; i > posicao; --i) {
        vetor->array[i] = vetor->array[i-1];
    }

    vetor->array[posicao] = elemento;
}

// Essa função remove um elemento do vetor
void removerElemento(vetor_int_t *const vetor, const unsigned long posicao) {
    if (vetor->array == NULL) {
        return;
    }
    if (posicao > vetor->tamanho) {
        return;
    }
    for (unsigned long i = posicao; i < vetor->tamanho - 1; ++i) {
        vetor->array[i] = vetor->array[i+1];
    }
}