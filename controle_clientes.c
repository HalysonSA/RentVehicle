#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "element_validation.h"
#include "element_input.h"
#include "manipula_arquivo.h"

Cliente *cliente;

void menu_cadastro_cliente()
{

    cliente = (Cliente *)malloc(sizeof(Cliente));
    printf("=============================================\n");
    cliente = inputClientValues();
    gravaArquivoCliente(cliente);
    printf("=============================================\n");
    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_cliente(Cliente *cliente)
{

    if (cliente[0].nome != NULL)
    {
        printf("Nome do cliente: %s \n", cliente->nome);
        printf("CPF do cliente: %s \n", cliente->cpf);
        printf("Endereco do cliente: %s \n", cliente->endereco);
        printf("Telefone do cliente: %s \n", cliente->telefone);
    }
    else
    {
        printf("Nenhum cliente cadastrado! \n");
    }
    printf("=============================================\n");
}

void menu_editar_cliente()
{
    printf("=============================================\n");
    updateClientValues();
    printf("=============================================\n");

    printf(" Cadastro atualizado com sucesso! \n");
}

void menu_remover_cliente()
{
    char cpf[11];
    printf("=============================================\n");
    printf(" Digite o CPF do cliente: \n");
    scanf("%s", cpf);
    getchar();
    printf("=============================================\n");
    printf(" Cliente removido com sucesso! \n");
}

char menu_clientes(void)
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

            system("cls||clear");
            menu_cadastro_cliente();
            break;
        case '2':

            system("cls||clear");
            printf("=============================================\n");
            printf("====  Relatorio de clientes cadastrados  ====\n");
            printf("=============================================\n");

            listaClientes();
            break;
        case '3':
            system("cls||clear");
            menu_editar_cliente();
            break;
        case '4':

            system("cls||clear");
            menu_remover_cliente();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        system("cls||clear");

        choice = menu_clientes();
    }
}