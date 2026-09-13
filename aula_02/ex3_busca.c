#include <stdio.h>

#define TAMANMHO 15

//Busca em Vetores

int main(void) {
    int vetor[TAMANMHO];
    int numero_buscado;
    int posicao = -1;

    for (int i = 0; i < TAMANMHO; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite o numero que deseja pesquisar: ");
    scanf("%d", &numero_buscado);

    for (int i = 0; i < TAMANMHO; i++) {
        if (vetor[i] == numero_buscado) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        printf("\nO numero %d foi encontrado na posicao %d do vetor.\n",
               numero_buscado, posicao);
    } else {
        printf("\nO numero %d NAO foi encontrado no vetor.\n", numero_buscado);
    }

    return 0;
}
