#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "element_validation.h"
#include "element_input.h"
#include "controle_clientes.h"

Cliente *cliente;

void menu_cadastro_cliente()
{

    cliente = (Cliente *)malloc(10 * sizeof(Cliente));

    char nome[50], cpf[15], endereco[50], telefone[15];

    printf("=============================================\n");
    inputClientValues(nome, cpf, endereco, telefone);
    printf("=============================================\n");
    strcpy(cliente->nome, nome);
    strcpy(cliente->cpf, cpf);
    strcpy(cliente->endereco, endereco);
    strcpy(cliente->telefone, telefone);

    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_cliente()
{

    printf("=============================================\n");
    printf("====  Relatorio de clientes cadastrados  ====\n");
    printf("=============================================\n");
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

void menu_editar_cliente(char *cpfCliente)
{

    char nome[50], cpf[11], endereco[50], telefone[15];

    printf("=============================================\n");
    inputClientValues(nome, cpf, endereco, telefone);
    printf("=============================================\n");
    /*
        strcpy(cliente->nome, nome);
        strcpy(cliente->cpf, cpf);
        strcpy(cliente->endereco, endereco);
        strcpy(cliente->telefone, telefone);
    */

    printf(" Cadastro atualizado com sucesso! \n");
}

void menu_remover_cliente()
{
    char cpf[15];

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
            menu_relatorio_cliente();
            break;
        case '3':
        {

            system("cls||clear");
            char cpf[15];

            printf("=============================================\n");
            printf("Qual o CPF do cliente que deseja editar? \n");
            scanf("%s", cpf);
            getchar();
            menu_editar_cliente(cpf);
        }
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