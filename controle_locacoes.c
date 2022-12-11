#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"
#include "element_input.h"
#include "manipula_arquivo.h"

Locacao *locacao;

void menu_cadastrar_locacao()
{
    locacao = (Locacao *)malloc(sizeof(Locacao));

    printf("=============================================\n");
    locacao = inputRentalValues();

    if (locacao)
    {
        printf(" Cadastro realizado com sucesso! \n");
        gravaArquivoLocacao(locacao);
    }

    printf("=============================================\n");
}

void menu_relatorio_locacao(Locacao *locacao)
{
    if (locacao[0].valor != NULL)
    {
        if (locacao->status == 1)
        {
            printf("Status: Ativo \n");
        }
        else
        {
            printf("Status: Inativo \n");
        }
        printf("Cliente: %s \n", locacao->cliente);
        printf("Veiculo: %s \n", locacao->placa);
        printf("Data de inicio da locacao: %s \n", locacao->data_locacao);
        printf("Data de fim da locacao: %s \n", locacao->data_devolucao);
        printf("Valor da locacao: %s \n", locacao->valor);
    }
    else if (locacao[0].status == 0)
    {
        printf("Locacao removida ou inativa \n");
    }
    else
    {
        printf("Nenhuma locacao encontrada! \n");
    }

    printf("=============================================\n");
}

void menu_editar_locacao(void)
{

    printf("=============================================\n");
    updateRentalValues();
    printf("=============================================\n");
}

void menu_remover_locacao()
{
    deleteRentalValues();
}

char menu_locacoes(void)
{
    printf("==========================================\n");
    printf("======     CONTROLE DE LOCACOES     ======\n");
    printf("======    1 - Cadastrar locacao     ======\n");
    printf("======    2 - Editar locacao        ======\n");
    printf("======    3 - Remover locacao       ======\n");
    printf("======    4 - Buscar locacao        ======\n");
    printf("======    5 - Relatorios            ======\n");
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
            system("cls||clear");
            menu_cadastrar_locacao();
            break;
        case '2':

            system("cls||clear");
            menu_editar_locacao();

            break;
        case '3':
            system("cls||clear");
            menu_remover_locacao();
            break;

        case '4':
            system("clear||cls");
            Locacao *locacao = (Locacao *)malloc(sizeof(Locacao));
            locacao = buscaLocacao();
            printf("=============================================\n");
            if (locacao != NULL)
            {
                menu_relatorio_locacao(locacao);
            }
            else
            {
                printf("Nenhuma locacao encontrada! \n");
            }
            printf("=============================================\n");
            break;
        case '5':
            system("cls||clear");
            printf("=============================================\n");
            printf("====  Relatorio de Locacoes cadastradas  ====\n");
            printf("=============================================\n");
            listaLocacoes();
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        system("clear||cls");

        choice = menu_locacoes();
    }
}
