#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Aqui, é definida a função variância, que calcula o valor da variancia quando essa função é chamada na main
double variancia(double media, double *dados, int tamanho) {
    double var = 0;
    for(int i = 0; i < tamanho; i++) {
        var += pow((media - dados[i]), 2);
    }
    var = var/(tamanho-1);

    return var;
}

int main() {
    // Primeiramente, aqui são definidos os datatypes das variáveis que serão trabalhadas para tanto a leitura do arquivo, extração dos dados e também para os calculos solicitados
    FILE *data;
    double tamanho;
    double *dados;
    double numero;
    int i;
    double soma;

// Aqui, é realizada a abertura do arquivo data.txt em modo de leitura, assim como a extração dos dados do arquivo e também o calculo da soma entre eles, para facilitar o calculo da média
    data = fopen("data.txt", "r");
    if (data != NULL) {
        fscanf (data, "%lf", &tamanho);
        dados = malloc(tamanho * sizeof(double));
        for (int i = 0; i < tamanho; i++) {
            fscanf(data, "%lf", &numero);
            dados[i] = numero;
            soma += numero;

        }
// Aqui, essa condição de if e else surgem para, caso a leitura do arquivo dê errado (retornar null), o programa para.
    } else {
        printf("deu ruim");
    }

// Aqui, novamente são definidos os datatypes e nomes das variáveis que serão utilizadas para realizar os cálculos de média, variância e desvio padrão solicitados.
    double media;
    media = soma/tamanho;
    double varian;
    varian = variancia(media,dados,tamanho);
    double desvio;
    desvio = pow(varian, 0.5);

// Aqui, há 3 prints responsáveis por imprimir no terminal as respostas solicitadas.
    printf ("A media e: %lf.\n", media);
    printf ("A variancia e: %lf.\n", varian);
    printf ("O desvio e: %lf.\n", desvio);

// Aqui, após o cálculo e a utilização dos dados extraidos, é necessários dar "free" no ponteiro para liberar a memória alocada, garantindo que o código seja dinâmico e seguro
    free(dados);
    return 0;

}