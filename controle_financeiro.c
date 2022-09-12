#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void menu_cadastrar_despesa()
{
    char saida[15];

    printf("=============================================\n");
    printf(" Digite o valor da Saida:  \n");
    scanf("%s", saida);
    getchar();
    printf("=============================================\n");
    printf(" Saida realizada com sucesso! \n");
}

void menu_cadastrar_receita()
{
    char entrada[15];

    printf("=============================================\n");
    printf(" Digite o valor da Entrada:  \n");
    scanf("%s", entrada);
    getchar();
    printf("=============================================\n");
    printf(" Entrada realizada com sucesso! \n");
}

void menu_relatorio()
{
    // Apenas um exemplo de como seria o relatorio
    printf("=============================================\n");
    printf("====  Relatorio de entrada e saida  ====\n");
    printf("=============================================\n");
    printf("Despesas: \n");
    printf("R$ 0,00 \n");
    printf("Receitas: \n");
    printf("R$ 0,00 \n");
    printf("=============================================\n");
}

char menu_financeiro()
{
    printf("===========================================\n");
    printf("======     CONTROLE DE FINANCEIRO    ======\n");
    printf("======    1 - Cadastrar Despesa      ======\n");
    printf("======    2 - Cadastrar Receita      ======\n");
    printf("======    3 - Relatorio financeiro   ======\n");
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

    while (choice != '0')
    {
        switch (choice)
        {
        case '1':
            menu_cadastrar_despesa();
            break;
        case '2':
            menu_cadastrar_receita();
            break;
        case '3':
            menu_relatorio();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        system("cls||clear");

        choice = menu_financeiro();
    }
}