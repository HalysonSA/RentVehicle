
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void menu_cadastrar_locacao(){
    printf("=============================================\n");
    printf("Digite o valor da locacao  \n");
    printf("Digite o dia da locacao  \n");
    printf("Digite o Cliente  \n");
    printf("Digite o Veiculo  \n");
    printf("=============================================\n");
}

void menu_relatorio_locacao(){
    printf("=============================================\n");
    printf("Locacoes: \n");
    printf("Cliente: Veiculo: dia: valor:\n");
    printf("=============================================\n");
}

void menu_editar_locacao(){
    printf("=============================================\n");
    printf("Digite a locacao:  \n");
    printf("Digite o novo valor da locacao  \n");
    printf("Digite o novo dia da locacao  \n");
    printf("Digite o novo Cliente  \n");
    printf("Digite o novo Veiculo  \n");
    printf("=============================================\n");
}

void menu_remover_locacao(){
    printf("=============================================\n");
    printf("Digite a locacao:  \n");
    printf("=============================================\n");
}

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

    while(choice != '0')
    {
        switch(choice)
        {
            case '1':
                menu_cadastrar_locacao();
                break;
            case '2':
                menu_relatorio_locacao();
                break;
            case '3':
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

        choice = menu_locacoes();
        
    }

}
