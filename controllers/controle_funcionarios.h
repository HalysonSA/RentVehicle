#include <stdio.h>

int controle_funcionarios()
{
    printf("=============================================\n");
    printf("======     CONTROLE DE FUNCIONARIOS    ======\n");
    printf("======    1 - Cadastrar funcionario    ======\n");
    printf("======    2 - Relatorio funcionarios   ======\n");
    printf("======    3 - Editar funcionario       ======\n");
    printf("======    4 - Remover funcionario      ======\n");
    printf("======    0 - Voltar ao menu           ======\n");
    printf("=============================================\n");

    int choice;
    printf("Digite a opcao desejada: ");
    scanf("%d", &choice);

    while (choice != 0)
    {
        if (choice == 1)
        {
            // cadastrar_funcionario();
            printf("Cadastrar funcionario\n");
            char nome_funcionario[50];
            char cpf_funcionario[50];
        }
        else if (choice == 2)
        {
            // relatorio_funcionarios();
            printf("Relatorio funcionarios\n");
        }
        else if (choice == 3)
        {
            // editar_funcionario();
            printf("Editar funcionario\n");
        }
        else if (choice == 4)
        {
            // remover_funcionario();
            printf("Remover funcionario\n");
        }
        else
        {
            printf("Opcao invalida\n");
        }
        return choice;
    }
}