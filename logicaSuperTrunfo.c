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

    // Escolha do atributo para comparação - Mudar aqui se necessário
    float atributo1 = pib1;
    float atributo2 = pib2;
    char atributoNome[] = "PIB";
    int carta1Vence = atributo1 > atributo2; // Para PIB, vence o maior valor

    // Exibição dos resultados da comparação
    printf("\nComparação de Cartas (Atributo: %s):\n", atributoNome);
    printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, atributo1);
    printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, atributo2);

    if (carta1Vence) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (atributo1 < atributo2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
