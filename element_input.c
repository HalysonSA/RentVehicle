#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"
#include "controle_clientes.h"
#include "controle_veiculos.h"
#include "manipula_arquivo.h"

const int True2 = 1;
const int False2 = 0;

int onlyNumberAndTextInput(char *text)
{
    if (strpbrk(text, "0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\x0b\x0c") == NULL)
    {

        size_t ln = strlen(text) - 1;

        if (text[ln] == '\n')
        {
            text[ln] = '\0';
        }
        system("cls||clear");
        return True2;
    }
    else
    {
        system("cls||clear");
        printf("Digite apenas Letras e Números \n");
        return False2;
    }
}

int onlyNumberInput(char *text)
{
    if (strpbrk(text, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\x0b\x0c") == NULL)
    {

        size_t ln = strlen(text) - 1;

        if (text[ln] == '\n')
        {
            text[ln] = '\0';
        }
        system("cls||clear");
        return True2;
    }
    else
    {
        system("cls||clear");
        printf("Digite apenas Números \n");
        return False2;
    }
}

int onlyTextInput(char *text)
{
    if (strpbrk(text, "0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\x0b\x0c") == NULL)
    {

        size_t ln = strlen(text) - 1;

        if (text[ln] == '\n')
        {
            text[ln] = '\0';
        }
        system("cls||clear");
        return True2;
    }
    else
    {
        system("cls||clear");
        printf("Digite apenas Letras \n");
        return False2;
    }
}

Veiculo *inputVehicleValues(void)
{
    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));

    char placa[10];
    char modelo[20];
    char marca[20];
    char ano[5];
    char cor[20];
    char valor[10];

    do
    {
        printf("Digite o modelo do veiculo:  \n");
        fgets(modelo, sizeof modelo, stdin);
    } while (onlyTextInput(modelo) == False2);

    do
    {
        printf("Digite a marca do veiculo:  \n");
        fgets(marca, sizeof marca, stdin);
    } while (onlyNumberAndTextInput(marca) == False2);

    do
    {
        printf("Digite o ano do veiculo:  \n");
        fgets(ano, sizeof ano, stdin);
    } while (onlyNumberInput(ano) == False2);

    do
    {
        printf("Digite a placa do veiculo:  \n");
        scanf("%s", placa);
        getchar();
    } while (carPlateValidation(placa) == False2);

    do
    {
        printf("Digite o valor do veiculo:  \n");
        fgets(valor, sizeof valor, stdin);
    } while (onlyNumberInput(valor) == False2);

    do
    {
        printf("Digite a cor do veiculo:  \n");
        fgets(cor, sizeof cor, stdin);
    } while (onlyTextInput(cor) == False2);

    strcpy(veiculo->modelo, modelo);
    strcpy(veiculo->marca, marca);
    strcpy(veiculo->ano, ano);
    strcpy(veiculo->placa, placa);
    strcpy(veiculo->valor, valor);
    strcpy(veiculo->cor, cor);
    veiculo->status = 'v';

    return veiculo;
}

Cliente *inputClientValues(void)
{
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));

    char nome[50];
    char cpf[15];
    char telefone[15];
    char endereco[50];

    do
    {
        printf(" Digite o nome: \n");
        fgets(nome, sizeof nome, stdin);

    } while (onlyTextInput(nome) == False2);

    do
    {
        printf(" Digite o CPF: \n");
        fgets(cpf, sizeof cpf, stdin);
    } while (CPFValidation(cpf) == False2);

    do
    {
        printf(" Digite o endereco: \n");
        fgets(endereco, sizeof endereco, stdin);
    } while (onlyNumberAndTextInput(endereco) == False2);

    do
    {
        printf(" Digite o telefone: \n");
        fgets(telefone, sizeof telefone, stdin);
    } while (onlyNumberInput(telefone) == False2);

    strcpy(cliente->nome, nome);
    strcpy(cliente->cpf, cpf);
    strcpy(cliente->endereco, endereco);
    strcpy(cliente->telefone, telefone);
    cliente->status = 'v';

    return cliente;
}

//WIP
void updateClientValues(void)
{
    FILE * file = fopen("clientes.dat", "r+b");
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));

    char nome[50];
    char telefone[20];
    char endereco[50];
    
    cliente = buscaCliente();

    if(file){

        if(cliente->nome == NULL){
            printf("Cliente nao existe");
        }
            
        do
        {
            printf(" Digite o nome: \n");
            fgets(nome, sizeof nome, stdin);

        } while (onlyTextInput(nome) == False2);

        do
        {
            printf(" Digite o endereco: \n");
            fgets(endereco, sizeof endereco, stdin);
        } while (onlyNumberAndTextInput(endereco) == False2);

        do
        {
            printf(" Digite o telefone: \n");
            fgets(telefone, sizeof telefone, stdin);
        } while (onlyNumberInput(telefone) == False2);
    
        strcpy(cliente->nome, nome);
        strcpy(cliente->endereco, endereco);
        strcpy(cliente->telefone, telefone);


        long int menos_um = -1;
        fseek(file,menos_um *sizeof(Cliente ), SEEK_CUR);
        fwrite(cliente, sizeof(Cliente), 1, file);

        fclose(file);
        free(cliente);
    }
    else{
        printf("Erro ao abrir o arquivo");
    }

}

void inputRentalValues(char *valor, char *data, char *cliente, char *placa)
{
    do
    {
        printf("Digite o valor da locacao:  \n");
        scanf("%s", valor);
    } while (onlyNumberInput(valor) == False2);
    getchar();

    do
    {
        printf("Digite a data da locacao(dd/mm/aaaa):  \n");
        scanf("%s", data);
    } while (onlyNumberAndTextInput(data) == False2);
    getchar(); // Ou pegar a data do sistema // Aplicar o mesmo modelo do cpf

    do
    {
        printf("Digite o CPF do cliente:  \n");
        scanf("%s", cliente);
    } while (CPFValidation(cliente) == False2);
    getchar();

    do
    {
        printf("Digite a placa do veiculo:  \n");
        scanf("%s", placa);
    } while (carPlateValidation(placa) == False2);
    getchar();
}