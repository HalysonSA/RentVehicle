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
    locacao = (Locacao *)malloc(10 * sizeof(Locacao));

    printf("=============================================\n");
    locacao = inputRentalValues();
    gravaArquivoLocacao(locacao);
    printf("=============================================\n");
    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_locacao(Locacao *locacao)
{
    if (locacao[0].valor != NULL && locacao[0].status != 0)
    {
        printf("Cliente: %s \n", locacao->cliente);
        printf("Veiculo: %s \n", locacao->placa);
        printf("Data de inicio da locacao: %s \n", locacao->data_locacao);
        printf("Data de fim da locacao: %s \n", locacao->data_devolucao);
        printf("Valor da locacao: %s \n", locacao->valor);
    }
    else
    {
        printf("Nenhuma locacao cadastrada! \n");
    }

    printf("=============================================\n");
}

void menu_editar_locacao(void)
{

    printf("=============================================\n");
    updateRentalValues();
    printf("=============================================\n");

    printf(" Cadastro atualizado com sucesso! \n");
}

void menu_remover_locacao()
{
    deleteRentalValues();
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

            printf("=============================================\n");
            printf("====  Relatorio de Locacoes cadastradas  ====\n");
            printf("=============================================\n");
            listaLocacoes();
            break;
        case '3':

            system("cls||clear");
            menu_editar_locacao();

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
