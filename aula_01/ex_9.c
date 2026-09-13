#include <stdio.h>
#include <stdint.h>

//Organizando um Programa

#define NOTA_CORTE 7.5
#define MAX_FALTAS 20
#define ESCOLA_NOME "Escola Saleciana São José"


typedef struct {
    uint16_t matricula; 
    uint8_t nota_final; 
    uint8_t faltas; 
} Aluno;

int main(void) {
    
    Aluno aluno1;

    aluno1.matricula = 2024;
    aluno1.nota_final = 8.5;
    aluno1.faltas = 12;

    printf("Sistema de notas da escola - %s \n", ESCOLA_NOME);
    printf("Matricula: %u\n", aluno1.matricula);
    printf("Nota Final: %.1f (Corte: %.1f)\n", aluno1.nota_final, NOTA_CORTE);
    printf("Faltas: %u (Maximo permitido: %d)\n\n", aluno1.faltas, MAX_FALTAS);

    
    if (aluno1.faltas > MAX_FALTAS) {
        printf("Situacao: Reprovado por falta\n");
    } else if (aluno1.nota_final >= NOTA_CORTE) {
        printf("Situacao: Aprovado\n");
    } else {
        printf("Situacao: Reprovado por nota\n");
    }

    return 0;
}