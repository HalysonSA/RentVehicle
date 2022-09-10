#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void menu_cadastrar_veiculo(){
    char modelo[50], marca[50], ano[10], placa[7], valor[50];

    printf("=============================================\n");
    printf("Digite o modelo do veiculo:  \n");
    scanf("%s", modelo);
    getchar();
    printf("Digite a marca do veiculo:  \n");
    scanf("%s", marca);
    getchar();
    printf("Digite o ano do veiculo:  \n");
    scanf("%s", ano);
    getchar();
    printf("Digite a placa do veiculo:  \n");
    scanf("%s", placa);
    getchar();
    printf("Digite o valor do veiculo:  \n");
    scanf("%s", valor);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro realizado com sucesso! \n");
}

void menu_relatorio_veiculo(){
    // Apenas um exemplo de como seria o relatorio
    printf("=============================================\n");
    printf("====  Relatorio de vaiculos cadastrados  ====\n");
    printf("=============================================\n");
    printf("Modelo: Uno Mille\n");
    printf("Marca: Fiat \n");
    printf("Ano: 1984\n");
    printf("Placa: MYQ7786\n");
    printf("Valor: RS 100\n");
    printf("=============================================\n");
    printf("Modelo: Brasília\n");
    printf("Marca: Volkswagen\n");
    printf("Ano: 1982\n");
    printf("Placa: HPG6912\n");
    printf("Valor: RS 100\n");
    printf("=============================================\n");
}

void menu_editar_veiculo(char *veiculo){
    char modelo[50], marca[50], ano[10], placa[7], valor[50];
    
    printf("=============================================\n");
    printf("Digite o modelo do veiculo:  \n");
    scanf("%s", modelo);
    getchar();
    printf("Digite a marca do veiculo:  \n");
    scanf("%s", marca);
    getchar();
    printf("Digite o ano do veiculo:  \n");
    scanf("%s", ano);
    getchar();
    printf("Digite a placa do veiculo:  \n");
    scanf("%s", placa);
    getchar();
    printf("Digite o valor do veiculo:  \n");
    scanf("%s", valor);
    getchar();
    printf("=============================================\n");
    printf(" Cadastro editado com sucesso! \n");
}

void menu_remover_veiculo(){
    char placa[7]
    printf("=============================================\n");
    printf("Digite a placa do veiculo:  \n");
    scanf("%s", placa);
    getchar();
    printf("=============================================\n");
    printf(" Veiculo removido com sucesso! \n");
}

char menu_veiculos(){
    printf("=============================================\n");
    printf("======     CONTROLE DE VEICULOS      ========\n");
    printf("======    1 - Cadastrar veiculo       ========\n");
    printf("======    2 - Relatorio veiculos      ========\n");
    printf("======    3 - Editar veiculo          ========\n");
    printf("======    4 - Remover veiculo         ========\n");
    printf("======    0 - Voltar ao menu          ========\n");
    printf("=============================================\n");

    char choice;
    printf("Digite a opcao desejada: ");
    scanf("%c", &choice);
    getchar();

    return choice;
}

void controle_veiculos()
{

    char choice = menu_veiculos();

    while( choice != '0')
    {
        switch(choice)
        {
            case '1':
                menu_cadastrar_veiculo();
                break;
            case '2':
                menu_relatorio_veiculo();
                break;
            case '3':
                menu_editar_veiculo();
                break;
            case '4':
                menu_remover_veiculo();
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

        printf("Pressione enter para continuar...\n");
        getchar();

        choice = menu_veiculos();
        
    }
}
