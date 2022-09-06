
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

char menu_locacoes() { 
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

    while(isdigit(choice) && choice != '0')
    {
        switch(choice)
        {
            case '1':
                printf("Cadastrar locacao\n");
                break;
            case '2':
                printf("Relatorio locacoes\n");
                break;
            case '3':
                printf("Editar locacao\n");
                break;
            case '4':
                printf("Remover locacao\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

        printf("Pressione enter para continuar...");
        getchar();

        choice = menu_locacoes();
        
    }

}
