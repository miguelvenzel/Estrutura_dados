#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_NOME 100

//Manipulacao de Strings

int ehVogal(char c) {
    c = tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
    char nome[TAMANHO_NOME];
    int quant_caracteres, quant_vogais = 0, quant_consoantes = 0, quant_espacos = 0;

    printf("Digite o nome completo: ");
    fgets(nome, TAMANHO_NOME, stdin);

    /* Remove o '\n' deixado pelo fgets, se existir */
    nome[strcspn(nome, "\n")] = '\0';

    quant_caracteres = strlen(nome);

    for (int i = 0; i < quant_caracteres; i++) {
        char c = nome[i];

        if (isalpha((unsigned char)c)) {
            if (ehVogal(c)) {
                quant_vogais++;
            } else {
                quant_consoantes++;
            }
        } else if (isspace((unsigned char)c)) {
            quant_espacos++;
        }
    }

    printf("\nResultado:\n");
    printf("- Quantidade de caracteres: %d\n", quant_caracteres);
    printf("- Quantidade de vogais: %d\n", quant_vogais);
    printf("- Quantidade de consoantes: %d\n", quant_consoantes);
    printf("- Quantidade de espacos em branco: %d\n", quant_espacos);

    return 0;
}
