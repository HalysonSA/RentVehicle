#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

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

    while(isdigit(choice) && choice != '0')
    {
        switch(choice)
        {
            case '1':
                printf("Cadastrar veiculo\n");
                break;
            case '2':
                printf("Relatorio veiculos\n");
                break;
            case '3':
                printf("Editar veiculo\n");
                break;
            case '4':
                printf("Remover veiculo\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

        printf("Pressione enter para continuar...");
        getchar();

        choice = menu_veiculos();
        
    }
}
