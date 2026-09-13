#include <stdio.h>

//Criando Macros

#define MAX_ALUNOS 40
#define MAX_ESTOQUE 500
#define PI 3.1415926535
#define ANO_ATUAL 2026

int main(void) {
    
    printf("Numero maximo de alunos por sala: %d\n", MAX_ALUNOS);
    printf("Quantidade maxima de produtos em estoque: %d\n", MAX_ESTOQUE);
    printf("Valor de PI: %.10f\n", PI);
    printf("Ano atual: %d\n", ANO_ATUAL);

    return 0;
}
