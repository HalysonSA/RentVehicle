
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char menu_principal()
{

    system("cls||clear");

    printf("=============== MENU PRINCIPAL ===============\n");
    printf("======    1 - Controle de locacoes      ======\n");
    printf("======    2 - Controle de clientes      ======\n");
    printf("======    3 - Controle de veiculos      ======\n");
    printf("======    4 - Controle do financeiro    ======\n");
    printf("======    0 - Encerrar Programa         ======\n");
    printf("==============================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf("%c", &choice);
    getchar();

    system("cls||clear");

    return choice;
}