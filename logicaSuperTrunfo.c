#include <stdio.h>
#include <string.h>

int main() {
    char nomePais1[50], nomePais2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Leitura dos dados da primeira carta
    printf("Digite o nome do país da Carta 1: ");
    scanf(" %[^\n]", nomePais1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura dos dados da segunda carta
    printf("\nDigite o nome do país da Carta 2: ");
    getchar(); // limpa o \n anterior
    scanf(" %[^\n]", nomePais2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo de densidade demográfica e PIB per capita
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    int opcao1, opcao2;

    // Menu para escolher o primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n6. PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Menu para escolher o segundo atributo (dinâmico)
    do {
        printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != opcao1) {
                switch (i) {
                    case 1: printf("1. População\n"); break;
                    case 2: printf("2. Área\n"); break;
                    case 3: printf("3. PIB\n"); break;
                    case 4: printf("4. Pontos Turísticos\n"); break;
                    case 5: printf("5. Densidade Demográfica\n"); break;
                    case 6: printf("6. PIB per Capita\n"); break;
                }
            }
        }
        printf("Opção: ");
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) printf("\nVocê já escolheu esse atributo. Escolha outro.\n");
    } while (opcao2 == opcao1);

    // Função auxiliar simulada usando macro (não pode declarar função dentro de main)
    #define GET_VAL(opcao, p, a, pib, pt, d, ppc) \
        (opcao == 1 ? p : \
        (opcao == 2 ? a : \
        (opcao == 3 ? pib : \
        (opcao == 4 ? pt : \
        (opcao == 5 ? d : ppc)))))

    float valor1_attr1 = GET_VAL(opcao1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
    float valor2_attr1 = GET_VAL(opcao1, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);

    float valor1_attr2 = GET_VAL(opcao2, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
    float valor2_attr2 = GET_VAL(opcao2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);

    // Lógica de comparação
    int venceu_attr1 = (opcao1 == 5) ? (valor1_attr1 < valor2_attr1 ? 1 : (valor1_attr1 > valor2_attr1 ? 2 : 0))
                                     : (valor1_attr1 > valor2_attr1 ? 1 : (valor1_attr1 < valor2_attr1 ? 2 : 0));

    int venceu_attr2 = (opcao2 == 5) ? (valor1_attr2 < valor2_attr2 ? 1 : (valor1_attr2 > valor2_attr2 ? 2 : 0))
                                     : (valor1_attr2 > valor2_attr2 ? 1 : (valor1_attr2 < valor2_attr2 ? 2 : 0));

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);

    // Exibição dos resultados
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s:\n", nomePais1);
    printf("Atributo 1: %.2f\nAtributo 2: %.2f\nSoma: %.2f\n", valor1_attr1, valor1_attr2, soma1);

    printf("\nCarta 2 - %s:\n", nomePais2);
    printf("Atributo 1: %.2f\nAtributo 2: %.2f\nSoma: %.2f\n", valor2_attr1, valor2_attr2, soma2);

    if (vencedorFinal == 1)
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomePais1);
    else if (vencedorFinal == 2)
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomePais2);
    else
        printf("\nResultado: Empate!\n");

    return 0;
}
