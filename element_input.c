#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "element_validation.h"

const int True2 = 1;
const int False2 = 0;

int onlyNumberAndTextInput(char *text)
{
    if (strpbrk(text, "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c") == NULL)
    {
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
    if (strpbrk(text, "0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c") == NULL)
    {
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

void inputVehicleValues(char *modelo, char *marca, char *ano, char *placa, char *valor)
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

    return;
}

void inputClientValues(char *nome, char *cpf, char *endereco, char *telefone)
{
    do
    {
        printf(" Digite o nome: \n");
        scanf("%s", nome);
    } while (onlyTextInput(nome) == False2);
    getchar();

    do
    {
        printf(" Digite o CPF: \n");
        scanf("%s", cpf);
    } while (CPFValidation(cpf) == False2);
    getchar();

    do
    {
        printf(" Digite o endereco: \n");
        scanf("%s", endereco);
    } while (onlyNumberAndTextInput(endereco) == False2);
    getchar();

    do
    {
        printf(" Digite o telefone: \n");
        scanf("%s", telefone);
    } while (onlyNumberInput(telefone) == False2);
    getchar();
}