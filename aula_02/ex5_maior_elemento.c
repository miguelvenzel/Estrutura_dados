#include <stdio.h>

#define LINHA 5
#define COLUNA 5

//Maior Elemento da Matriz

int main(void) {
    int matriz[LINHA][COLUNA];
    int maior, maior_linha = 0, maior_coluna = 0;

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maior = matriz[0][0];

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                maior_linha = i;
                maior_coluna = j;
            }
        }
    }

    printf("\nResultado:\n");
    printf("- Maior elemento: %d\n", maior);
    printf("- Linha: %d\n", maior_linha);
    printf("- Coluna: %d\n", maior_coluna);

    return 0;
}
