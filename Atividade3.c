#include <stdio.h>
#include <math.h>

// Função para trocar dois elementos de lugar, utilizando uma variável z de apoio
void troca(int *a, int *b) {
    int z = *a;
    *a = *b;
    *b = z;
}

// Função para ordenar o array usando o algoritmo de ordenação por bolha (troca de termos em comparações 2 a 2)
// Uso de dois for's para poder fazer a comparação dois a dois.
// uso do tamanho-i-1 para o j para evitar que comparações ja feitas sejam realizadas de novo.
void ordenar(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                troca(&array[j], &array[j + 1]);
            }
        }
    }
}

// Função para imprimir o array
void imprimir(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// Aqui na main, iremos apenas puxar as funções ordenar e imprimir, além de definir o array previamente e seu tamanho também.
int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = 7;

    printf("Array antes da ordenacao:\n");
    imprimir(array, tamanho);

    ordenar(array, tamanho);

    printf("Array depois da ordenacao:\n");
    imprimir(array, tamanho);

    return 0;
}