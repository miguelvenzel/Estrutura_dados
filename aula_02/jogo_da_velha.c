#include <stdio.h>
#include <ctype.h>

#define TAMANHO 3


void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void escolherSimbolos(char *jogador1, char *jogador2);
int  posicao_valida(int linha, int coluna);
int  posicaoOcupada(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna);
void realizarJogada(char tabuleiro[TAMANHO][TAMANHO], char jogadorAtual, int numeroJogador);
int  verifi_vitoria(char tabuleiro[TAMANHO][TAMANHO], char jogador);
int  tabuleiro_cheio(char tabuleiro[TAMANHO][TAMANHO]);


int main(void) {
    char tabuleiro[TAMANHO][TAMANHO];
    char jogador1, jogador2;
    int jogadaAtual = 1;   /* 1 = jogador1, 2 = jogador2 */
    int totalJogadas = 0;
    int vencedorEncontrado = 0;

    inicializarTabuleiro(tabuleiro);
    escolherSimbolos(&jogador1, &jogador2);

    exibirTabuleiro(tabuleiro);

    while (totalJogadas < TAMANHO * TAMANHO && !vencedorEncontrado) {
        char simboloAtual = (jogadaAtual == 1) ? jogador1 : jogador2;

        realizarJogada(tabuleiro, simboloAtual, jogadaAtual);
        totalJogadas++;

        exibirTabuleiro(tabuleiro);

        if (totalJogadas >= 5 && verifi_vitoria(tabuleiro, simboloAtual)) {
            printf("\nVencedor: Jogador %d ('%c')\n", jogadaAtual, simboloAtual);
            printf("Perdedor: Jogador %d ('%c')\n",
                   (jogadaAtual == 1) ? 2 : 1,
                   (jogadaAtual == 1) ? jogador2 : jogador1);
            vencedorEncontrado = 1;
        } else if (tabuleiro_cheio(tabuleiro)) {
            printf("\nEmpate!\n");
        } else {
            jogadaAtual = (jogadaAtual == 1) ? 2 : 1;
        }
    }

    return 0;
}


void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < TAMANHO - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

void escolherSimbolos(char *jogador1, char *jogador2) {
    char opcao[10];

    printf("Jogador 1, escolha com o que quer jogar (X ou O): ");
    scanf("%9s", opcao);

    if (toupper((unsigned char)opcao[0]) == 'X') {
        *jogador1 = 'X';
        *jogador2 = 'O';
    } else {
        *jogador1 = 'O';
        *jogador2 = 'X';
    }
}

int posicao_valida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO);
}

int posicaoOcupada(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O');
}

void realizarJogada(char tabuleiro[TAMANHO][TAMANHO], char jogadorAtual, int numeroJogador) {
    int posicao, linha, coluna;
    int jogadaValida = 0;

    while (!jogadaValida) {
        printf("Jogador %d ('%c'), digite o numero da posicao (1-9): ",
               numeroJogador, jogadorAtual);
        scanf("%d", &posicao);

        linha = (posicao - 1) / TAMANHO;
        coluna = (posicao - 1) % TAMANHO;

        if (posicao < 1 || posicao > 9 || !posicao_valida(linha, coluna)) {
            printf("Posicao invalida. Digite um numero de 1 a 9.\n");
        } else if (posicaoOcupada(tabuleiro, linha, coluna)) {
            printf("Posicao ja ocupada. Escolha outra.\n");
        } else {
            tabuleiro[linha][coluna] = jogadorAtual;
            jogadaValida = 1;
        }
    }
}

int verifi_vitoria(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    //Linhas e colunas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;
        }
    }

    // Diagonal
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0;
}

int tabuleiro_cheio(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
