
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void menu_cadastrar_locacao(){
    char valor[15], data[10], cliente[50], veiculo[50];

    printf("=============================================\n");
    printf("Digite o valor da locacao  \n");
    scanf("%s", valor);
    getchar();
    printf("Digite o dia da locacao  \n");
    scanf("%s", data);
    getchar();
    printf("Digite o Cliente  \n");
    scanf("%s", cliente);
    getchar();
    printf("Digite o Veiculo  \n");
    scanf("%s", veiculo);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_locacao(){
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
    printf("Veiculo: Volkswagen Brasília\n");
    printf("dia: 10/09/2022\n");
    printf("valor: RS 100\n");
    printf("=============================================\n");
}

void menu_editar_locacao(char *locacao){
    char valor[15], data[10], cliente[50], veiculo[50];

    printf("=============================================\n");
    printf("Digite o novo valor da locacao:  \n");
    scanf("%s", valor);
    getchar();
    printf("Digite o novo dia da locacao:  \n");
    scanf("%s", data);
    getchar();
    printf("Digite o novo Cliente:  \n");
    scanf("%s", cliente);
    getchar();
    printf("Digite o novo Veiculo:  \n");
    scanf("%s", veiculo);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro editado com sucesso! \n");
}

void menu_remover_locacao(){
    char cliente[50];

    printf("=============================================\n");
    printf("Digite o cliente da locacao:  \n");
    scanf("%s", cliente);
    getchar();
    printf("=============================================\n");
    printf(" Locacao removida com sucesso! \n");
}

char menu_locacoes() { 
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

    while(choice != '0')
    {
        switch(choice)
        {
            case '1':
                menu_cadastrar_locacao();
                break;
            case '2':
                menu_relatorio_locacao();
                break;
            case '3':
                menu_editar_locacao();
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

        choice = menu_locacoes();
        
    }

}
