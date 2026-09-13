#include <stdio.h>

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int menor(int a, int b) {
    return (a < b) ? a : b;
}

float media(float a, float b) {
    return (a + b) / 2.0f;
}

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

int main(void) {
    int x, y, n;

    printf("=== Exercicio 8 - Funcoes ===\n\n");

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &x, &y);

    printf("Maior: %d\n", maior(x, y));
    printf("Menor: %d\n", menor(x, y));
    printf("Media: %.2f\n", media((float)x, (float)y));

    printf("\nDigite um numero para calcular o fatorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fatorial nao definido para numeros negativos.\n");
    } else {
        printf("Fatorial de %d: %d\n", n, fatorial(n));
    }

    return 0;
}
