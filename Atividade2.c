#include <stdio.h>
#include <math.h>

// Definição da função Fibonacci, bem definida para n == 0, n == 1 e n >= 2.
unsigned long fibonacci(unsigned int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n >= 2) {
            return (fibonacci(n-1) + fibonacci(n-2));
        }
}


int main () {
    // Definição de até qual número n se deseja que o código rode, e definição de um contador para gerenciar a parada do programa.
    printf ("Digite ate qual termo da sequencia de Fibonacci deseja obter as divisoes pelo numero de ouro:");
    unsigned int n;
    scanf ("%d", &n);
    int contador = n;
    while (contador >= 0) {
        if (n >= 1) {
            double y = fibonacci (n);
            double z = fibonacci (n-1);
            // Print do valor de fibonacci para o número n atual em que se está iterando
            printf ("\n Fibonnaci em %d: %lf", n, y);
            if (z > 0) {
                double divisao = y/z;
                // Print do valor da divisão do fibonacci n atual da iteração pelo n-1 atual da iteração
                printf (" Divisao: %lf",divisao);
            }
        // Modificação dos valores do contador e n para gerenciamento de parada e calculo dos números de fibonacci.
        contador--;
        n--;
        }
    }
    return 0;
}