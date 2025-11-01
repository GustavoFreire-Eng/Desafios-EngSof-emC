#include <stdio.h>

/*
===============================================================
    PROGRAMA: Movimentos Complexos de Peças de Xadrez
    Desafio Nível Mestre - Recursividade e Loops Aninhados
===============================================================
*/

// Função recursiva para a Torre
void moverTorre(int casas) {
    if (casas <= 0) return;  // Caso base da recursão
    printf("Direita\n");
    moverTorre(casas - 1);   // Chamada recursiva reduzindo uma casa
}

// Função recursiva + loops aninhados para o Bispo
void moverBispo(int casas) {
    if (casas <= 0) return; // Caso base

    // Loop externo: movimento vertical
    for (int i = 0; i < casas; i++) {
        printf("Cima\n");
        // Loop interno: movimento horizontal
        for (int j = 0; j < casas; j++) {
            printf("Direita\n");
        }
    }

    // Chamada recursiva para continuar o movimento diagonal
    moverBispo(casas - 1);
}

// Função recursiva para a Rainha (combina Torre + Bispo)
void moverRainha(int casas) {
    if (casas <= 0) return;

    // Movimento vertical
    printf("Cima\n");

    // Movimento horizontal
    printf("Direita\n");

    // Movimento diagonal (simbolicamente)
    printf("Diagonal Cima-Direita\n");

    moverRainha(casas - 1); // Chamada recursiva reduzindo uma casa
}

// Função com loops complexos para o Cavalo
void moverCavalo(int movimentos) {
    int movVertical = 2; // Duas casas para cima
    int movHorizontal = 1; // Uma casa para a direita

    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movVertical + movHorizontal; j++) {
            if (j < movVertical) {
                printf("Cima\n");
                continue; // Continua o movimento vertical
            }
            if (j >= movVertical && j < movVertical + movHorizontal) {
                printf("Direita\n");
                break; // Interrompe após o movimento horizontal
            }
        }
    }
}

// Função principal
int main() {
    int casasTorre = 3;
    int casasBispo = 2;
    int casasRainha = 3;
    int movimentosCavalo = 2;

    printf("===== Movimento da TORRE =====\n");
    moverTorre(casasTorre);
    printf("\n");

    printf("===== Movimento do BISPO =====\n");
    moverBispo(casasBispo);
    printf("\n");

    printf("===== Movimento da RAINHA =====\n");
    moverRainha(casasRainha);
    printf("\n");

    printf("===== Movimento do CAVALO =====\n");
    moverCavalo(movimentosCavalo);
    printf("\n");

    return 0;
}
