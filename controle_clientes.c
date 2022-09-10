#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void menu_cadastro_cliente()
{
    char nome[50], cpf[15], endereco[50], telefone[15];

    printf("=============================================\n");
    printf(" Digite o nome: \n");
    scanf("%s", nome);
    getchar();
    printf(" Digite o CPF: \n");
    scanf("%s", cpf);
    getchar();
    printf(" Digite o endereco: \n");
    scanf("%s", endereco);
    getchar();
    printf(" Digite o telefone: \n");
    scanf("%s", telefone);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_cliente()
{
    // Apenas um exemplo de como seria o relatorio
    printf("=============================================\n");
    printf("====  Relatorio de clientes cadastrados  ====\n");
    printf("=============================================\n");
    printf("Nome: Joao da Silva\n");
    printf("CPF: 123.456.789-00\n");
    printf("Endereco: Rua das Flores, 123\n");
    printf("Telefone: (11) 1234-5678\n");
    printf("=============================================\n");
    printf("Nome: Maria da Silva\n");
    printf("CPF: 987.654.321-00\n");
    printf("Endereco: Rua das Flores, 123\n");
    printf("Telefone: (11) 1234-5678\n");
    printf("=============================================\n");
}

void menu_editar_cliente(char *cliente)
{
    char nome[50], cpf[15], endereco[50], telefone[15];

    printf("=============================================\n");
    printf(" Digite o nome: \n");
    scanf("%s", nome);
    getchar();
    printf(" Digite o CPF: \n");
    scanf("%s", cpf);
    getchar();
    printf(" Digite o endereco: \n");
    scanf("%s", endereco);
    getchar();
    printf(" Digite o telefone: \n");
    scanf("%s", telefone);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro editado com sucesso! \n");
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
        {
            char cpf[15];

            printf("=============================================\n");
            printf("Qual o CPF do cliente que deseja editar? \n");
            scanf("%s", cpf);
            getchar();
            menu_editar_cliente(cpf);
        }
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