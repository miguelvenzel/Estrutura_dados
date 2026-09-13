#include <stdio.h>
#include <string.h>

#define TAM_NOME 100

int main(void) {
    char nome1[TAM_NOME], nome2[TAM_NOME];
    int resultado;

    printf("=== Exercicio 7 - Comparacao de Strings ===\n\n");

    printf("Digite o primeiro nome: ");
    fgets(nome1, TAM_NOME, stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("Digite o segundo nome: ");
    fgets(nome2, TAM_NOME, stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    /* strncmp compara ate 'n' caracteres. Usamos o tamanho do maior nome
       para garantir que a comparacao considere as strings inteiras. */
    int n = strlen(nome1) > strlen(nome2) ? strlen(nome1) : strlen(nome2);
    resultado = strncmp(nome1, nome2, n);

    printf("\n--- Resultado ---\n");
    if (resultado == 0) {
        printf("Os nomes sao iguais.\n");
    } else if (resultado < 0) {
        printf("Os nomes sao diferentes.\n");
        printf("\"%s\" e alfabeticamente maior que \"%s\".\n", nome2, nome1);
    } else {
        printf("Os nomes sao diferentes.\n");
        printf("\"%s\" e alfabeticamente maior que \"%s\".\n", nome1, nome2);
    }

    return 0;
}
