#include <stdio.h>
#include <math.h>
int main() {;

// Definição das variáveis iniciais
    float cateto_oposto = 0;
    float cateto_adjacente = 0;
    float hip;

// Inputs dos valores dos catetos trabalhados
    printf("Digite o tamanho do cateto oposto:");
    scanf("%f", &cateto_oposto);
    printf("Digite o tamanho do cateto adjacente:");
    scanf("%f", &cateto_adjacente);

// Calculo do valor da hipotenusa em relação aos valores de cateto informados
    hip = pow(pow(cateto_oposto, 2) + pow(cateto_adjacente, 2), 0.5);

// Primeiro output
    printf("O valor da hipotenusa e de: %.2f.\n", hip);

// Definição das variáveis compostas
    float seno = cateto_oposto/hip;
    float cosseno = cateto_adjacente/hip;
    float tangente = cateto_oposto/cateto_adjacente;

// Segundo, terceiro e quarto outputs
    printf("O valor do seno do angulo adjacente ao primeiro cateto: %.2f.\n", seno);
    printf("O valor do cosseno do angulo adjacente ao primeiro cateto: %.2f.\n", cosseno);
    printf("O valor do tangente do angulo adjacente ao primeiro cateto: %.2f.\n", tangente);


    return(0);

}