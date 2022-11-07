#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"
#include "controle_clientes.h"

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
    if (strpbrk(text, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c") == NULL)
    {
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

void inputVehicleValues(char *modelo, char *marca, char *ano, char *placa, char *valor, char *cor)
{
    do
    {
        printf("Digite o modelo do veiculo:  \n");
        scanf("%s", modelo);
    } while (onlyTextInput(modelo) == False2);
    getchar();

    do
    {
        printf("Digite a marca do veiculo:  \n");
        scanf("%s", marca);
    } while (onlyNumberAndTextInput(marca) == False2);
    getchar();

    do
    {
        printf("Digite o ano do veiculo:  \n");
        scanf("%s", ano);
    } while (onlyNumberInput(ano) == False2);
    getchar();

    do
    {
        printf("Digite a placa do veiculo:  \n");
        scanf("%s", placa);
    } while (carPlateValidation(placa) == False2);
    getchar();

    do
    {
        printf("Digite o valor do veiculo:  \n");
        scanf("%s", valor);
    } while (onlyNumberInput(valor) == False2);
    getchar();

    do
    {
        printf("Digite a cor do veiculo:  \n");
        scanf("%s", cor);
    } while (onlyTextInput(cor) == False2);
    getchar();

    return;
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
        scanf("%s", cpf);
    } while (CPFValidation(cpf) == False2);
    getchar();

    do
    {
        printf(" Digite o endereco: \n");
        fgets(endereco, sizeof endereco, stdin);
    } while (onlyNumberAndTextInput(endereco) == False2);

    do
    {
        printf(" Digite o telefone: \n");
        scanf("%s", telefone);
    } while (onlyNumberInput(telefone) == False2);
    getchar();

    strcpy(cliente->nome, nome);
    strcpy(cliente->cpf, cpf);
    strcpy(cliente->endereco, endereco);
    strcpy(cliente->telefone, telefone);

    return cliente;
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