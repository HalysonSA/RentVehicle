#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char menu_funcionarios()
{

    printf("=============================================\n");
    printf("======     CONTROLE DE FUNCIONARIOS    ======\n");
    printf("======    1 - Cadastrar funcionario    ======\n");
    printf("======    2 - Relatorio funcionarios   ======\n");
    printf("======    3 - Editar funcionario       ======\n");
    printf("======    4 - Remover funcionario      ======\n");
    printf("======    0 - Voltar ao menu           ======\n");
    printf("=============================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf("%c", &choice);
    getchar();

    return choice;
}

void controle_funcionarios()
{
    char choice = menu_funcionarios();

    while (isdigit(choice) && choice != '0')
    {
        switch (choice)
        {
        case '1':
            printf("Cadastrar funcionario\n");
            break;
        case '2':
            printf("Relatorio funcionarios\n");
            break;
        case '3':
            printf("Editar funcionario\n");
            break;
        case '4':
            printf("Remover funcionario\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...");
        getchar();

        choice = menu_funcionarios();
    }

}