#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
//Função para o tabuleiro
void inicializaTabuleiro() {
    int i, j;
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}
 //Função para posicionar navio
void posicionaNavio(int linha, int coluna) {
    tabuleiro[linha][coluna] = 3;
}
//Habilidade de cone
void criaHabilidadeCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}
//Habilidade de cruz
void criaHabilidadeCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}
//Habilidade de octaedro
void criaHabilidadeOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}
//Função para aplicar habilidades
void aplicaHabilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (matriz[i][j] == 1 && linha + i >= 0 && linha + i < TAMANHO_TABULEIRO && coluna + j >= 0 && coluna + j < TAMANHO_TABULEIRO) {
                if (tabuleiro[linha + i][coluna + j] != 3) {
                    tabuleiro[linha + i][coluna + j] = 5;
                }
            }
        }
    }
}
//função para exibir no tabuleiro
void exibeTabuleiro() {
    int i, j;
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inicializaTabuleiro();

    // Posiciona navios
    posicionaNavio(2, 2);
    posicionaNavio(5, 5);

    // Cria habilidades
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    criaHabilidadeCone(habilidadeCone);

    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    criaHabilidadeCruz(habilidadeCruz);

    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    criaHabilidadeOctaedro(habilidadeOctaedro);

    // Aplica habilidades
    aplicaHabilidade(habilidadeCone, 0, 0);
    aplicaHabilidade(habilidadeCruz, 5, 0);
    aplicaHabilidade(habilidadeOctaedro, 8, 5);

    exibeTabuleiro();

    return 0;
}