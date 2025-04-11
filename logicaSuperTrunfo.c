#include <stdio.h>
#include <string.h>

int main() {
    // Definição das variáveis para a primeira carta
    char estado1[3], codigo1[4], nomeCidade1[30];
    int populacao1, numPontosTuristicos1;
    float area1, pib1, densidadePopulacional1, pibPerCapita1;

    // Definição das variáveis para a segunda carta
    char estado2[3], codigo2[4], nomeCidade2[30];
    int populacao2, numPontosTuristicos2;
    float area2, pib2, densidadePopulacional2, pibPerCapita2;

    // Entrada de dados para a primeira carta
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf("%s", estado1);
    printf("Código da Carta: ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    getchar(); // Limpa buffer
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0'; // Remove o \n lido pelo fgets
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &numPontosTuristicos1);

    // Cálculo dos valores derivados da primeira carta
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Entrada de dados para a segunda carta
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf("%s", estado2);
    printf("Código da Carta: ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    getchar(); // Limpa buffer
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0'; // Remove o \n lido pelo fgets
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &numPontosTuristicos2);

    // Cálculo dos valores derivados da segunda carta
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Menu interativo para escolha do atributo de comparação
    int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("6. PIB per Capita\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s:\n", nomeCidade1, nomeCidade2);

    switch(opcao) {
        case 1:
            printf("População: %d x %d\n", populacao1, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2:
            printf("Área: %.2f km² x %.2f km²\n", area1, area2);
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3:
            printf("PIB: %.2f bilhões x %.2f bilhões\n", pib1, pib2);
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4:
            printf("Pontos Turísticos: %d x %d\n", numPontosTuristicos1, numPontosTuristicos2);
            if (numPontosTuristicos1 > numPontosTuristicos2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (numPontosTuristicos2 > numPontosTuristicos1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5:
            printf("Densidade Demográfica: %.2f hab/km² x %.2f hab/km²\n", densidadePopulacional1, densidadePopulacional2);
            if (densidadePopulacional1 < densidadePopulacional2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (densidadePopulacional2 < densidadePopulacional1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 6:
            printf("PIB per Capita: %.2f x %.2f\n", pibPerCapita1, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pibPerCapita2 > pibPerCapita1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
