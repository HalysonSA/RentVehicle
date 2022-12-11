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

    if (cliente)
    {
        gravaArquivoCliente(cliente);
        printf(" Cadastro realizado com sucesso! \n");
    }

    printf("=============================================\n");
}

void menu_relatorio_cliente(Cliente *cliente)
{

    if (cliente[0].nome != NULL)
    {

        printf("=============================================\n");
        if (cliente->status == 1)
        {
            printf("Status: Ativo \n");
        }
        else
        {
            printf("Status: Inativo \n");
        }
        printf("Nome: %s \n", cliente->nome);
        printf("CPF: %s \n", cliente->cpf);
        printf("Telefone %s \n", cliente->telefone);
        printf("Rua: %s \n", cliente->rua);
        printf("Bairro: %s \n", cliente->bairro);
        printf("Cidade: %s \n", cliente->cidade);
        printf("Estado: %s \n", cliente->estado);
    }
    else if (cliente[0].status == 0)
    {
        printf("Cliente inativo \n");
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
}

void menu_remover_cliente()
{
    deleteClientValues();
}

char menu_clientes(void)
{

    printf("==========================================\n");
    printf("======     CONTROLE DE CLIENTES     ======\n");
    printf("======    1 - Cadastrar cliente     ======\n");
    printf("======    2 - Editar cliente        ======\n");
    printf("======    3 - Remover cliente       ======\n");
    printf("======    4 - Buscar cliente        ======\n");
    printf("======    5 - Relatorios            ======\n");
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
            menu_editar_cliente();
            break;
        case '3':

            system("cls||clear");
            menu_remover_cliente();
            break;

        case '4':
            system("cls||clear");

            Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
            cliente = buscaCliente();
            printf("=============================================\n");
            if (cliente != NULL)
            {
                menu_relatorio_cliente(cliente);
            }
            else
            {
                printf("Cliente nao encontrado! \n");
            }
            printf("=============================================\n");
            break;
        case '5':
            system("cls||clear");
            printf("==========================================\n");
            printf("======    1 - Relatorio clientes    ======\n");
            printf("======    2 - Relatorio por cidade  ======\n");
            printf("======    0 - Voltar ao menu        ======\n");
            printf("==========================================\n");
            char opc;

            printf("Digite a opcao desejada: ");
            scanf("%c", &opc);
            getchar();
            switch (opc)
            {
            case '1':
                system("cls||clear");
                printf("=============================================\n");
                printf("====  Relatorio de clientes cadastrados  ====\n");
                printf("=============================================\n");

                listaClientes();
                break;
            case '2':
                system("cls||clear");
                printf("=============================================\n");
                printf("====  Relatorio de clientes por cidade  ====\n");
                printf("=============================================\n");

                listaClientesPorCidade();
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }

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