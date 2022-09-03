#include <stdio.h>

int controle_financeiro()
{
    printf("===========================================\n");
    printf("======     CONTROLE DE FINANCEIRO    ======\n");
    printf("======    1 - Cadastrar debito       ======\n");
    printf("======    2 - Cadastrar credito      ======\n");
    printf("======    3 - Relatorio financeiro   ======\n");
    printf("======    4 - Editar conta           ======\n");
    printf("======    0 - Voltar ao menu         ======\n");
    printf("===========================================\n");

    int choice;
    printf("Digite a opcao desejada: ");
    scanf("%d", &choice);

    while (choice != 0)
    {

        if (choice == 1)
        {
            // cadastrar_debito();
            printf("Cadastrar debito\n");
            char nome_debito[50];
            char numero_debito[16];
            char validade_debito[4];
            char cvv_debito[3];
            char bandeira_debito[50];
        }
        else if (choice == 2)
        {
            // cadastrar_credito();
            printf("Cadastrar credito\n");
            char nome_credito[50];
            char numero_credito[16];
            char validade_credito[4];
            char cvv_credito[3];
            char bandeira_credito[50];
        }
        else if (choice == 3)
        {
            // relatorio_financeiro();
            printf("Relatorio financeiro\n");
        }
        else if (choice == 4)
        {
            // editar_conta();
            printf("Editar conta\n");
        }
        else
        {
            printf("Opcao invalida\n");
        }
        return choice;
    }
}