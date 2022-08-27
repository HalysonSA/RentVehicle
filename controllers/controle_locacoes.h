
#include <stdio.h>

int controle_locacoes()
{
    printf("==========================================\n");
    printf("======     CONTROLE DE LOCACOES     ======\n");
    printf("======    1 - Cadastrar locacao     ======\n");
    printf("======    2 - Relatorio locacoes    ======\n");
    printf("======    3 - Editar locacao        ======\n");
    printf("======    4 - Remover locacao       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");

    int choice;

    printf("Digite a opcao desejada: ");
    scanf("%d", &choice);

    while (choice != 0)
    {
        if (choice == 1)
        {
            // cadastrar_locacao();
            printf("Cadastrar locacao\n");
        }
        else if (choice == 2)
        {
            // relatorio_locacoes();
            printf("Relatorio locacoes\n");
        }
        else if (choice == 3)
        {
            // editar_locacao();
            printf("Editar locacao\n");
        }
        else if (choice == 4)
        {
            // remover_locacao();
            printf("Remover locacao\n");
        }
        else
        {
            printf("Opcao invalida\n");
        }
        return choice;
    }
}
