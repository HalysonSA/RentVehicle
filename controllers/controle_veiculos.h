#include <stdio.h>

int controle_veiculos()
{
    printf("===========================================\n");
    printf("======     CONTROLE DE VEICULOS      ======\n");
    printf("======    1 - Cadastrar veiculo      ======\n");
    printf("======    2 - Relatorio veiculos     ======\n");
    printf("======    3 - Editar veiculo         ======\n");
    printf("======    4 - Remover veiculo        ======\n");
    printf("======    0 - Voltar ao menu         ======\n");
    printf("===========================================\n");

    int choice;
    printf("Digite a opcao desejada: ");
    scanf("%d", &choice);

    while (choice != 0)
    {

        if (choice == 1)
        {
            // cadastrar_veiculo();
            printf("Cadastrar veiculo\n");
        }
        else if (choice == 2)
        {
            // relatorio_veiculos();
            printf("Relatorio veiculos\n");
        }
        else if (choice == 3)
        {
            // editar_veiculo();
            printf("Editar veiculo\n");
        }
        else if (choice == 4)
        {
            // remover_veiculo();
            printf("Remover veiculo\n");
        }
        else
        {
            printf("Opcao invalida\n");
        }
        return choice;
    }
}
