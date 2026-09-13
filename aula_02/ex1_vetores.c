#include <stdio.h>

#define TAMANHO 10

//Vetores

int main(void) {
    int vetor[TAMANHO];


    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nValores na ordem digitada:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\nValores na ordem inversa:\n");
    for (int i = TAMANHO - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
