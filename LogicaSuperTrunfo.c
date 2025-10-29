#include <stdio.h>

int main() {
    // Dados das cartas (pré-cadastrados)
    char cidade1[] = "Sao Paulo";
    int populacao1 = 12325000;
    float area1 = 1521.11;
    float pib1 = 699.28;
    int pontos1 = 50;
    float densidade1 = 8102.47;
    float pib_capita1 = 56724.32;
    
    char cidade2[] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50;
    int pontos2 = 30;
    float densidade2 = 5622.24;
    float pib_capita2 = 44532.91;
    
    int atributo1, atributo2;
    float valor1_atrib1, valor2_atrib1;
    float valor1_atrib2, valor2_atrib2;
    int vence_atrib1, vence_atrib2;
    float soma1, soma2;
    
    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");
    
    // Mostrando os dados das cartas
    printf("CARTA 1: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos1);
    printf("Densidade: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais\n\n", pib_capita1);
    
    printf("CARTA 2: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    printf("Densidade: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais\n\n", pib_capita2);
    
    // Escolha do primeiro atributo
    printf("ESCOLHA O PRIMEIRO ATRIBUTO:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade\n");
    printf("6 - PIB per capita\n");
    printf("Digite sua escolha (1-6): ");
    scanf("%d", &atributo1);
    
    // Escolha do segundo atributo (menu dinâmico)
    printf("\nESCOLHA O SEGUNDO ATRIBUTO:\n");
    
    // Mostra apenas as opções que não foram escolhidas
    if(atributo1 != 1) printf("1 - Populacao\n");
    if(atributo1 != 2) printf("2 - Area\n");
    if(atributo1 != 3) printf("3 - PIB\n");
    if(atributo1 != 4) printf("4 - Pontos Turisticos\n");
    if(atributo1 != 5) printf("5 - Densidade\n");
    if(atributo1 != 6) printf("6 - PIB per capita\n");
    
    printf("Digite sua escolha (1-6, diferente de %d): ", atributo1);
    scanf("%d", &atributo2);
    
    // Verifica se escolheu o mesmo atributo
    if(atributo1 == atributo2) {
        printf("ERRO: Voce escolheu o mesmo atributo duas vezes!\n");
        return 1;
    }
    
    printf("\n=== RESULTADO DA COMPARACAO ===\n\n");
    
    // PRIMEIRO ATRIBUTO - Comparação
    printf("PRIMEIRO ATRIBUTO: ");
    switch(atributo1) {
        case 1:
            printf("Populacao\n");
            valor1_atrib1 = populacao1;
            valor2_atrib1 = populacao2;
            vence_atrib1 = (populacao1 > populacao2) ? 1 : 2;
            break;
        case 2:
            printf("Area\n");
            valor1_atrib1 = area1;
            valor2_atrib1 = area2;
            vence_atrib1 = (area1 > area2) ? 1 : 2;
            break;
        case 3:
            printf("PIB\n");
            valor1_atrib1 = pib1;
            valor2_atrib1 = pib2;
            vence_atrib1 = (pib1 > pib2) ? 1 : 2;
            break;
        case 4:
            printf("Pontos Turisticos\n");
            valor1_atrib1 = pontos1;
            valor2_atrib1 = pontos2;
            vence_atrib1 = (pontos1 > pontos2) ? 1 : 2;
            break;
        case 5:
            printf("Densidade\n");
            valor1_atrib1 = densidade1;
            valor2_atrib1 = densidade2;
            // Densidade: menor valor vence
            vence_atrib1 = (densidade1 < densidade2) ? 1 : 2;
            break;
        case 6:
            printf("PIB per capita\n");
            valor1_atrib1 = pib_capita1;
            valor2_atrib1 = pib_capita2;
            vence_atrib1 = (pib_capita1 > pib_capita2) ? 1 : 2;
            break;
        default:
            printf("Atributo invalido!\n");
            return 1;
    }
    
    printf("%s: %.2f\n", cidade1, valor1_atrib1);
    printf("%s: %.2f\n", cidade2, valor2_atrib1);
    printf("Vencedor do primeiro atributo: Carta %d\n\n", vence_atrib1);
    
    // SEGUNDO ATRIBUTO - Comparação
    printf("SEGUNDO ATRIBUTO: ");
    switch(atributo2) {
        case 1:
            printf("Populacao\n");
            valor1_atrib2 = populacao1;
            valor2_atrib2 = populacao2;
            vence_atrib2 = (populacao1 > populacao2) ? 1 : 2;
            break;
        case 2:
            printf("Area\n");
            valor1_atrib2 = area1;
            valor2_atrib2 = area2;
            vence_atrib2 = (area1 > area2) ? 1 : 2;
            break;
        case 3:
            printf("PIB\n");
            valor1_atrib2 = pib1;
            valor2_atrib2 = pib2;
            vence_atrib2 = (pib1 > pib2) ? 1 : 2;
            break;
        case 4:
            printf("Pontos Turisticos\n");
            valor1_atrib2 = pontos1;
            valor2_atrib2 = pontos2;
            vence_atrib2 = (pontos1 > pontos2) ? 1 : 2;
            break;
        case 5:
            printf("Densidade\n");
            valor1_atrib2 = densidade1;
            valor2_atrib2 = densidade2;
            // Densidade: menor valor vence
            vence_atrib2 = (densidade1 < densidade2) ? 1 : 2;
            break;
        case 6:
            printf("PIB per capita\n");
            valor1_atrib2 = pib_capita1;
            valor2_atrib2 = pib_capita2;
            vence_atrib2 = (pib_capita1 > pib_capita2) ? 1 : 2;
            break;
        default:
            printf("Atributo invalido!\n");
            return 1;
    }
    
    printf("%s: %.2f\n", cidade1, valor1_atrib2);
    printf("%s: %.2f\n", cidade2, valor2_atrib2);
    printf("Vencedor do segundo atributo: Carta %d\n\n", vence_atrib2);
    
    // SOMA DOS ATRIBUTOS
    soma1 = valor1_atrib1 + valor1_atrib2;
    soma2 = valor2_atrib1 + valor2_atrib2;
    
    printf("SOMA DOS DOIS ATRIBUTOS:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);
    
    // RESULTADO FINAL
    printf("\n=== RESULTADO FINAL ===\n");
    if(soma1 > soma2) {
        printf("VENCEDOR: %s (Carta 1)\n", cidade1);
    } else if(soma2 > soma1) {
        printf("VENCEDOR: %s (Carta 2)\n", cidade2);
    } else {
        printf("EMPATE!\n");
    }
    
    return 0;
}