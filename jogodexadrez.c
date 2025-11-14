#include <stdio.h>

#define TAM_TAB 10
#define HAB_LINHAS 3
#define HAB_COLUNAS 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }
    
    // Adicionar alguns navios
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[3][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][2] = 3;
}

// Função para criar habilidade em Cone (3x5)
void criarCone(int habilidade[HAB_LINHAS][HAB_COLUNAS]) {
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    
    for (int i = 0; i < HAB_LINHAS; i++) {
        for (int j = 0; j < HAB_COLUNAS; j++) {
            habilidade[i][j] = padrao[i][j];
        }
    }
}

// Função para criar habilidade em Cruz (3x5)
void criarCruz(int habilidade[HAB_LINHAS][HAB_COLUNAS]) {
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
    
    for (int i = 0; i < HAB_LINHAS; i++) {
        for (int j = 0; j < HAB_COLUNAS; j++) {
            habilidade[i][j] = padrao[i][j];
        }
    }
}

// Função para criar habilidade em Octaedro (3x5)
void criarOctaedro(int habilidade[HAB_LINHAS][HAB_COLUNAS]) {
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    for (int i = 0; i < HAB_LINHAS; i++) {
        for (int j = 0; j < HAB_COLUNAS; j++) {
            habilidade[i][j] = padrao[i][j];
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], 
                      int habilidade[HAB_LINHAS][HAB_COLUNAS], 
                      int linha, int coluna) {
    int inicio_i = linha - 1;  // Centralizar verticalmente
    int inicio_j = coluna - 2; // Centralizar horizontalmente (5 colunas)
    
    for (int i = 0; i < HAB_LINHAS; i++) {
        for (int j = 0; j < HAB_COLUNAS; j++) {
            int tab_i = inicio_i + i;
            int tab_j = inicio_j + j;
            
            // Verificar limites
            if (tab_i >= 0 && tab_i < TAM_TAB && tab_j >= 0 && tab_j < TAM_TAB) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[tab_i][tab_j] = 5; // Marcar área da habilidade
                }
            }
        }
    }
}

// Função para exibir uma habilidade
void exibirHabilidade(int habilidade[HAB_LINHAS][HAB_COLUNAS], char* nome) {
    printf("\n%s:\n", nome);
    for (int i = 0; i < HAB_LINHAS; i++) {
        for (int j = 0; j < HAB_COLUNAS; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("\nTabuleiro (0=Agua, 3=Navio, 5=Habilidade):\n");
    printf("  ");
    for (int j = 0; j < TAM_TAB; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAM_TAB; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[HAB_LINHAS][HAB_COLUNAS];
    int cruz[HAB_LINHAS][HAB_COLUNAS];
    int octaedro[HAB_LINHAS][HAB_COLUNAS];
    
    // Inicializar
    inicializarTabuleiro(tabuleiro);
    
    // Criar habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    printf("=== HABILIDADES ESPECIAIS (5x3) ===\n");
    
    // Mostrar os padrões das habilidades
    exibirHabilidade(cone, "Padrao Cone");
    exibirHabilidade(cruz, "Padrao Cruz");
    exibirHabilidade(octaedro, "Padrao Octaedro");
    
    // Mostrar tabuleiro original
    printf("\n=== TABULEIRO ORIGINAL ===");
    exibirTabuleiro(tabuleiro);
    
    // Aplicar habilidades em posições diferentes
    aplicarHabilidade(tabuleiro, cone, 3, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 3);
    
    // Mostrar resultado final
    printf("\n=== TABULEIRO COM HABILIDADES ===");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}