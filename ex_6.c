#include <stdio.h>

// Utilizando `typedef`

typedef unsigned char byte;    
typedef int inteiro;           
typedef double real;

int main(void) {

    byte idade = 25;
    inteiro quantidade = 1500;
    real preco = 19.99;

    printf("byte (idade): %u\n", idade);
    printf("inteiro (quantidade): %d\n", quantidade);
    printf("real (preco): %.2f\n", preco);

    return 0;
}
