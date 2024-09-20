#include <stdlib.h>

struct matriz_double_t {
    unsigned long colunas, linhas;
    double *m;
};
typedef struct matriz_double_t matriz_double_t;

// Essa função cria a matriz
matriz_double_t *criarMatriz(const unsigned long colunas, const unsigned long linhas) {
    matriz_double_t *matriz = malloc(sizeof(matriz_double_t));
    matriz->m = calloc(colunas * linhas, sizeof(double));
    return matriz;
}

// Essa função faz soma de matrizes
void somaMatrizes (const matriz_double_t * mat1, const matriz_double_t * mat2, matriz_double_t * resultado) {
    if (mat1->colunas != mat2->colunas || mat1->linhas != mat2->linhas) {
        return;
    }

    resultado = criarMatriz(mat1->colunas, mat1->linhas);

    for (unsigned long i = 0; i < mat1->linhas; ++i) {
        for (unsigned long j = 0; j < mat1->colunas; ++j) {
            resultado->m[mat1->linhas * i + j] = mat1->m[mat1->linhas * i + j] + mat2->m[mat2->linhas * i + j];
        }
    }
}