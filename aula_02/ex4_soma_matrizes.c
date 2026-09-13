#include <stdio.h>

#define LINHA 3
#define COLUNA 3

//Soma de Matrizes

void lerMatriz(int m[LINHA][COLUNA], const char *nome) {
    printf("\nDigite os elementos da matriz %s (%dx%d):\n", nome, LINHA, COLUNA);
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%s[%d][%d]: ", nome, i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void exibirMatriz(int m[LINHA][COLUNA], const char *titulo) {
    printf("\n%s:\n", titulo);
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int A[LINHA][COLUNA], B[LINHA][COLUNA], C[LINHA][COLUNA];

    printf("=== Exercicio 4 - Soma de Matrizes ===\n");

    lerMatriz(A, "A");
    lerMatriz(B, "B");

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    exibirMatriz(A, "Matriz A");
    exibirMatriz(B, "Matriz B");
    exibirMatriz(C, "Matriz C (A + B)");

    return 0;
}
