#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void menu_cadastro_cliente()
{
    printf("=============================================\n");
    printf(" Digite o nome: \n");
    printf(" Digite o CPF: \n");
    printf(" Digite o endereco: \n");
    printf(" Digite o telefone: \n");
    printf("=============================================\n");
}

void menu_relatorio_cliente()
{
    printf("=============================================\n");
    printf(" Relatorio de clientes cadastrados: \n");
    printf("Nome: Joao da Silva\n");
    printf("CPF: 123.456.789-00\n");
    printf("Endereco: Rua das Flores, 123\n");
    printf("Telefone: (11) 1234-5678\n");
    printf("Nome: Maria da Silva\n");
    printf("CPF: 987.654.321-00\n");
    printf("Endereco: Rua das Flores, 123\n");
    printf("Telefone: (11) 1234-5678\n");
    printf("=============================================\n");
}

void menu_editar_cliente()
{
    printf("=============================================\n");
    printf(" Digite o nome: \n");
    printf(" Digite o CPF: \n");
    printf(" Digite o endereco: \n");
    printf(" Digite o telefone: \n");
    printf("=============================================\n");
}

void menu_remover_cliente()
{
    printf("=============================================\n");
    printf(" Digite o CPF do cliente: \n");
    printf("=============================================\n");
}


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

    while (choice != '0')
    {
        switch (choice)
        {
        case '1':
            menu_cadastro_cliente();
            break;
        case '2':
            menu_relatorio_cliente();
            break;
        case '3':
            menu_editar_cliente();
            break;
        case '4':
            menu_remover_cliente();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        choice = menu_clientes();
    }
}