
#include <stdio.h>

int controle_clientes()
{
    printf("==========================================\n");
    printf("======     CONTROLE DE CLIENTES     ======\n");
    printf("======    1 - Cadastrar cliente     ======\n");
    printf("======    2 - Relatorio clientes    ======\n");
    printf("======    3 - Editar cliente        ======\n");
    printf("======    4 - Remover cliente       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");

    int choice;
    printf("Digite a opcao desejada: ");
    scanf("%d", &choice);

    while (choice != 0)
    {

        if (choice == 1)
        {
            // cadastrar_cliente();
            printf("Cadastrar cliente\n");
        }
        else if (choice == 2)
        {
            // relatorio_clientes();
            printf("Relatorio clientes\n");
        }
        else if (choice == 3)
        {
            // editar_cliente();
            printf("Editar cliente\n");
        }
        else if (choice == 4)
        {
            // remover_cliente();
            printf("Remover cliente\n");
        }
        else
        {
            printf("Opcao invalida\n");
        }
        return choice;
    }
}