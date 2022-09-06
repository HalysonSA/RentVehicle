#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void menu_cadastrar_veiculo(){
    printf("=============================================\n");
    printf("Digite o modelo do veiculo  \n");
    printf("Digite a marca do veiculo  \n");
    printf("Digite o ano do veiculo  \n");
    printf("Digite a placa do veiculo  \n");
    printf("Digite o valor do veiculo  \n");
    printf("=============================================\n");
}

void menu_relatorio_veiculo(){
    printf("=============================================\n");
    printf("Veiculos: \n");
    printf("Modelo: Marca: Ano: Placa: Valor:\n");
    printf("=============================================\n");
}

void menu_editar_veiculo(){
    printf("=============================================\n");
    printf("Digite o veiculo:  \n");
    printf("Digite o novo modelo do veiculo  \n");
    printf("Digite a nova marca do veiculo  \n");
    printf("Digite o novo ano do veiculo  \n");
    printf("Digite a nova placa do veiculo  \n");
    printf("Digite o novo valor do veiculo  \n");
    printf("=============================================\n");
}

void menu_remover_veiculo(){
    printf("=============================================\n");
    printf("Digite o veiculo:  \n");
    printf("=============================================\n");
}

char menu_veiculos(){
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

    while( choice != '0')
    {
        switch(choice)
        {
            case '1':
                menu_cadastrar_veiculo();
                break;
            case '2':
                menu_relatorio_veiculo();
                break;
            case '3':
                menu_editar_veiculo();
                break;
            case '4':
                menu_remover_veiculo();
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        choice = menu_veiculos();
        
    }
}
