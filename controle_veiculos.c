#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"
#include "element_input.h"
#include "controle_veiculos.h"

Veiculo *veiculo;

void menu_cadastrar_veiculo()
{

    veiculo = (Veiculo *)malloc(10 * sizeof(Veiculo));

    char modelo[30], marca[30], ano[10], placa[8], valor[50], cor[20];

    printf("=============================================\n");
    inputVehicleValues(modelo, marca, ano, placa, valor, cor);
    printf("=============================================\n");
    strcpy(veiculo->modelo, modelo);
    strcpy(veiculo->marca, marca);
    strcpy(veiculo->ano, ano);
    strcpy(veiculo->placa, placa);
    strcpy(veiculo->valor, valor);
    strcpy(veiculo->cor, cor);

    printf(" Cadastro realizado com sucesso! \n");
    printf("=============================================\n");
    printf("Pressione enter para continuar...\n");
    getchar();
}

void menu_relatorio_veiculo()
{
    // Apenas um exemplo de como seria o relatorio
    printf("=============================================\n");
    printf("====  Relatorio de vaiculos cadastrados  ====\n");
    printf("=============================================\n");
    if (veiculo->modelo != NULL)
    {

        printf("Modelo: %s \n", veiculo->modelo);
        printf("Marca: %s \n", veiculo->marca);
        printf("Ano: %s \n", veiculo->ano);
        printf("Placa: %s \n", veiculo->placa);
        printf("Valor: %s \n", veiculo->valor);
        printf("Cor: %s \n", veiculo->cor);
    }
    else
    {
        printf("Nenhum veiculo cadastrado! \n");
    }
    printf("=============================================\n");
}

void menu_editar_veiculo(char *veiculo)
{
    char modelo[50], marca[50], ano[10], placa[7], valor[50], cor[20];

    printf("=============================================\n");
    inputVehicleValues(modelo, marca, ano, placa, valor, cor);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro atualizado com sucesso! \n");
}

void menu_remover_veiculo()
{
    char placa[7];
    printf("=============================================\n");
    printf("Digite a placa do veiculo:  \n");
    scanf("%s", placa);
    getchar();
    printf("=============================================\n");
    printf(" Veiculo removido com sucesso! \n");
}

char menu_veiculos(void)
{
    printf("=============================================\n");
    printf("======     CONTROLE DE VEICULOS      ========\n");
    printf("======    1 - Cadastrar veiculo       ========\n");
    printf("======    2 - Relatorio veiculos      ========\n");
    printf("======    3 - Editar veiculo          ========\n");
    printf("======    4 - Remover veiculo         ========\n");
    printf("======    0 - Voltar ao menu          ========\n");
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
        case '2':

            system("cls||clear");
            menu_relatorio_veiculo();
            break;
        case '3':
        {

            system("cls||clear");
            char veiculo[7];

            printf("Digite a placa do veiculo:  \n");
            scanf("%s", veiculo);
            getchar();
            menu_editar_veiculo(veiculo);
        }
        break;
        case '4':

            system("cls||clear");
            menu_remover_veiculo();
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
