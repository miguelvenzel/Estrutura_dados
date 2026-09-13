#include <stdio.h>

#define MAX_ALUNOS 30

void lerNotas(float notas[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

float calcularMedia(float notas[], int qtd) {
    float soma = 0;

    for (int i = 0; i < qtd; i++) {
        soma += notas[i];
    }

    return soma / qtd;
}

float encontrarMaiorNota(float notas[], int qtd) {
    float maior = notas[0];

    for (int i = 1; i < qtd; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }

    return maior;
}

float encontrarMenorNota(float notas[], int qtd) {
    float menor = notas[0];

    for (int i = 1; i < qtd; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    return menor;
}

void imprimirRelatorio(float notas[], int qtd, float media, float maior, float menor) {
    printf("\n=== Relatorio da Turma ===\n");

    printf("\nNotas cadastradas:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }

    printf("\nMedia da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
}

int main(void) {
    float notas[MAX_ALUNOS];
    int qtdAlunos;
    float media, maior, menor;

    printf("=== Exercicio 9 - Modularizando um Programa ===\n\n");
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &qtdAlunos);

    if (qtdAlunos <= 0 || qtdAlunos > MAX_ALUNOS) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    lerNotas(notas, qtdAlunos);
    media = calcularMedia(notas, qtdAlunos);
    maior = encontrarMaiorNota(notas, qtdAlunos);
    menor = encontrarMenorNota(notas, qtdAlunos);
    imprimirRelatorio(notas, qtdAlunos, media, maior, menor);

    return 0;
}
