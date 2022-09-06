#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char menu_clientes()
{

    printf("==========================================\n");
    printf("======     CONTROLE DE CLIENTES     ======\n");
    printf("======    1 - Cadastrar cliente     ======\n");
    printf("======    2 - Relatorio clientes    ======\n");
    printf("======    3 - Editar cliente        ======\n");
    printf("======    4 - Remover cliente       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf("%c", &choice);
    getchar();

    return choice;
}

void controle_clientes()
{
    char choice = menu_clientes();

    while (isdigit(choice) && choice != '0')
    {
        switch (choice)
        {
        case '1':
            printf("Cadastrar cliente\n");
            break;
        case '2':
            printf("Relatorio clientes\n");
            break;
        case '3':
            printf("Editar cliente\n");
            break;
        case '4':
            printf("Remover cliente\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...");
        getchar();

        choice = menu_clientes();
    }
}