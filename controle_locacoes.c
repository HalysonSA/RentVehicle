
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void menu_cadastrar_locacao()
{
    char valor[15], data[10], cliente[11], veiculo[7];

    printf("=============================================\n");
    printf("Digite o valor da locacao:  \n");
    scanf("%s", valor);
    getchar();
    printf("Digite a data da locacao(dd/mm/aaaa):  \n");
    scanf("%s", data);
    getchar(); // Ou pegar a data do sistema
    printf("Digite o CPF do cliente:  \n");
    scanf("%s", cliente);
    getchar();
    printf("Digite a placa do veiculo:  \n");
    scanf("%s", veiculo);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_locacao()
{
    // Apenas um exemplo de como seria o relatorio
    printf("=============================================\n");
    printf("====  Relatorio de clientes cadastrados  ====\n");
    printf("=============================================\n");
    printf("Cliente: Joao da Silva\n");
    printf("Veiculo: Fiat Uno Mille\n");
    printf("dia: 10/09/2022\n");
    printf("valor: RS 100\n");
    printf("=============================================\n");
    printf("Cliente: Maria da Silva\n");
    printf("Veiculo: Volkswagen Brasilia\n");
    printf("dia: 10/09/2022\n");
    printf("valor: RS 100\n");
    printf("=============================================\n");
}

void menu_editar_locacao(char *locacao)
{
    char valor[15], data[10], veiculo[7];

    printf("=============================================\n");
    printf("Digite o valor da locacao:  \n");
    scanf("%s", valor);
    getchar();
    printf("Digite a data da locacao(dd/mm/aaaa):  \n");
    scanf("%s", data);
    getchar();
    printf("Digite a placa do Veiculo:  \n");
    scanf("%s", veiculo);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro editado com sucesso! \n");
}

void menu_remover_locacao()
{
    char cpf[11];

    printf("=============================================\n");
    printf("Digite o CPF do cliente:  \n");
    scanf("%s", cpf);
    getchar();
    printf("=============================================\n");
    printf(" Locacao removida com sucesso! \n");
}

char menu_locacoes()
{
    printf("==========================================\n");
    printf("======     CONTROLE DE LOCACOES     ======\n");
    printf("======    1 - Cadastrar locacao     ======\n");
    printf("======    2 - Relatorio locacoes    ======\n");
    printf("======    3 - Editar locacao        ======\n");
    printf("======    4 - Remover locacao       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf(" %c", &choice);
    getchar();

    return choice;
}

void controle_locacoes()
{

    char choice = menu_locacoes();

    while (choice != '0')
    {
        switch (choice)
        {
        case '1':
            menu_cadastrar_locacao();
            break;
        case '2':
            menu_relatorio_locacao();
            break;
        case '3':
        {
            char cpf[11];

            printf("Digite o CPF do cliente:  \n");
            scanf("%s", cpf);
            getchar();
            menu_editar_locacao(cpf);
        }

        break;
        case '4':
            menu_remover_locacao();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        system("cls||clear");

        choice = menu_locacoes();
    }
}
