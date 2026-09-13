#include <stdio.h>

#define TAMANHO 20

//Estatisticas de um Vetor

int main(void) {
    int vetor[TAMANHO];
    int maior, menor;
    int pares = 0, impares = 0;
    float media = 1, soma = 0;


    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (int i = 0; i < TAMANHO; i++) {
        soma += vetor[i];

        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }

        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    media = soma / TAMANHO;

    printf("\nResultados:\n");
    printf("- Maior valor: %d\n", maior);
    printf("- Menor valor: %d\n", menor);
    printf("- Media dos elementos: %.2f\n", media);
    printf("- Quantidade de numeros pares: %d\n", pares);
    printf("- Quantidade de numeros impares: %d\n", impares);

    return 0;
}
