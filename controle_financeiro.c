#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char menu_financeiro()
{
    printf("===========================================\n");
    printf("======     CONTROLE DE FINANCEIRO    ======\n");
    printf("======    1 - Cadastrar debito       ======\n");
    printf("======    2 - Cadastrar credito      ======\n");
    printf("======    3 - Relatorio financeiro   ======\n");
    printf("======    4 - Editar conta           ======\n");
    printf("======    0 - Voltar ao menu         ======\n");
    printf("===========================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf("%c", &choice);
    getchar();

    return choice;
}

void controle_financeiro()
{
    char choice = menu_financeiro();

    while (isdigit(choice) && choice != '0')
    {
        switch (choice)
        {
        case '1':
            printf("Cadastrar debito\n");
            break;
        case '2':
            printf("Cadastrar credito\n");
            break;
        case '3':
            printf("Relatorio financeiro\n");
            break;
        case '4':
            printf("Editar conta\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...");
        getchar();

        choice = menu_financeiro();
    }
}