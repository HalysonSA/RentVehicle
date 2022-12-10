#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"
#include "element_input.h"
#include "manipula_arquivo.h"

Veiculo *veiculo;

void menu_cadastrar_veiculo()
{
    veiculo = (Veiculo *)malloc(10 * sizeof(Veiculo));

    printf("=============================================\n");

    veiculo = inputVehicleValues();

    if (veiculo)
    {
        gravaArquivoVeiculo(veiculo);
        printf(" Cadastro realizado com sucesso! \n");
    }

    printf("=============================================\n");
}

void menu_relatorio_veiculo(Veiculo *veiculo)
{

    if (veiculo[0].marca != NULL && veiculo[0].status != 0)
    {
        printf("Marca do veiculo: %s \n", veiculo->marca);
        printf("Modelo do veiculo: %s \n", veiculo->modelo);
        printf("Ano do veiculo: %s \n", veiculo->ano);
        printf("Placa do veiculo: %s \n", veiculo->placa);
        printf("Cor do veiculo: %s \n", veiculo->cor);
        printf("Valor do veiculo: %s \n", veiculo->valor);
    }
    else if (veiculo[0].status == 0)
    {
        printf("Veiculo inativo \n");
    }
    else
    {
        printf("Nenhum Veiculo cadastrado! \n");
    }
    printf("=============================================\n");
}

void menu_editar_veiculo(void)
{

    printf("=============================================\n");
    updateVehicleValues();
    printf("=============================================\n");
}

void menu_remover_veiculo()
{
    deleteVehicleValues();
}

char menu_veiculos(void)
{
    printf("=============================================\n");
    printf("======     CONTROLE DE VEICULOS      ========\n");
    printf("======    1 - Cadastrar veiculo      ========\n");
    printf("======    2 - Editar veiculo         ========\n");
    printf("======    3 - Remover veiculo        ========\n");
    printf("======    4 - Buscar veiculo         ========\n");
    printf("======    5 - Relatorio veiculos     ========\n");
    printf("======    6 - Relatorio por marca    ========\n");
    printf("======    0 - Voltar ao menu         ========\n");
    printf("=============================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf("%c", &choice);
    getchar();

    return choice;
}

void controle_veiculos()
{

    char choice = menu_veiculos();

    while (choice != '0')
    {
        switch (choice)
        {
        case '1':

            system("cls||clear");
            menu_cadastrar_veiculo();
            break;
        case '5':
            system("cls||clear");
            printf("=============================================\n");
            printf("====  Relatorio de veiculos cadastrados  ====\n");
            printf("=============================================\n");
            listaVeiculos();
            break;
        case '2':
        {
            system("cls||clear");
            menu_editar_veiculo();
        }
        break;
        case '3':

            system("cls||clear");
            menu_remover_veiculo();
            break;

        case '4':
            system("cls||clear");
            Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
            veiculo = buscaVeiculo();
            printf("=============================================\n");
            if (veiculo != NULL)
            {
                menu_relatorio_veiculo(veiculo);
            }
            else
            {
                printf("Veiculo nao encontrado! \n");
            }
            printf("=============================================\n");
            break;

        case '6':
            system("cls||clear");
            printf("=============================================\n");
            printf("====  Relatorio de veiculos por marca    ====\n");
            printf("=============================================\n");

            listaVeiculosPorMarca();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        system("cls||clear");

        choice = menu_veiculos();
    }
}
