#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"
#include "element_input.h"
#include "controle_locacoes.h"

Locacao *locacao;

void menu_cadastrar_locacao()
{
    locacao = (Locacao *)malloc(10 * sizeof(Locacao));

    char valor[15], data[10], cliente[11], placa[7];

    printf("=============================================\n");
    inputRentalValues(valor, data, cliente, placa);
    printf("=============================================\n");
    strcpy(locacao->valor, valor);
    strcpy(locacao->data, data);
    strcpy(locacao->cliente, cliente);
    strcpy(locacao->placa, placa);

    printf(" Cadastro realizado com sucesso! \n");

    
}

void menu_relatorio_locacao()
{
    printf("=============================================\n");
    printf("====  Relatorio de Locações cadastradas  ====\n");
    printf("=============================================\n");
    if (locacao[0].valor != NULL)
    {
        printf("Nome do cliente: %s \n", locacao->cliente);
        printf("Placa do Veiculo: %s \n", locacao->placa);
        printf("Data da Locação: %s \n", locacao->data);
        printf("Valor da Locação: %s \n", locacao->valor);
    }
    else
    {
        printf("Nenhuma locacao cadastrada! \n");
    }
    printf("=============================================\n");
}

void menu_editar_locacao(char *locacao)
{
    char valor[15], data[10], cliente[11], placa[7];

    printf("=============================================\n");
    inputRentalValues(valor, data, cliente, placa);
    printf("=============================================\n");

    printf(" Cadastro atualizado com sucesso! \n");
}

void menu_remover_locacao()
{
    char cpf[11];

    printf("=============================================\n");
    printf("Digite o CPF do cliente:  \n");
    scanf("%s", cpf);
    getchar();
    printf("=============================================\n");
    printf(" Locacao removida com sucesso! \n");
}

char menu_locacoes(void)
{
    printf("==========================================\n");
    printf("======     CONTROLE DE LOCACOES     ======\n");
    printf("======    1 - Cadastrar locacao     ======\n");
    printf("======    2 - Relatorio locacoes    ======\n");
    printf("======    3 - Editar locacao        ======\n");
    printf("======    4 - Remover locacao       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf(" %c", &choice);
    getchar();

    return choice;
}

void controle_locacoes()
{

    char choice = menu_locacoes();

    while (choice != '0')
    {
        switch (choice)
        {
        case '1':
            menu_cadastrar_locacao();
            break;
        case '2':
            menu_relatorio_locacao();
            break;
        case '3':
        {
            char cpf[11];

            printf("=============================================\n");
            printf("Qual o CPF do cliente que deseja editar? \n");
            scanf("%s", cpf);
            getchar();
            menu_editar_locacao(cpf);
        }

        break;
        case '4':
            menu_remover_locacao();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        system("cls||clear");

        choice = menu_locacoes();
    }
}
