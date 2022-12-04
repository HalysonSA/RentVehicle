#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "element_validation.h"
#include "controle_clientes.h"
#include "controle_veiculos.h"
#include "controle_locacoes.h"
#include "manipula_arquivo.h"

const int True2 = 1;
const int False2 = 0;

int onlyNumberAndTextInput(char *text)
{
    if (strpbrk(text, "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\x0b\x0c") == NULL)
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

int verifyPlateInFile(char *placa)
{
    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    FILE *fp = fopen("veiculos.dat", "rb");

    if (access("veiculos.dat", F_OK) != -1)
    {
        if (fp == NULL)
        {
            printf("Ocorreu um erro na abertura do arquivo!\n");
            exit(1);
        }

        while (!feof(fp))
        {
            fread(veiculo, sizeof(Veiculo), 1, fp);

            placa[strcspn(placa, "\n")] = 0;
            veiculo->placa[strcspn(veiculo->placa, "\n")] = 0;

            if (!strcmp(veiculo->placa, placa))
            {
                printf("Veiculo existe! \n");
                return 1;
            }
        }
        printf("Veiculo inexistente \n");
        return 0;
    }
    else
    {
        return 0;
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
    } while (carPlateValidation(placa) == False2 || verifyPlateInFile(placa) == 1);

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
    veiculo->status = 1;

    return veiculo;
}

int verifyCPFInFile(char *cpf)
{
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    FILE *fp = fopen("clientes.dat", "rb");

    if (access("clientes.dat", F_OK) != -1)
    {
        if (fp == NULL)
        {
            printf("Ocorreu um erro na abertura do arquivo!\n");
            exit(1);
        }

        while (!feof(fp))
        {
            fread(cliente, sizeof(Cliente), 1, fp);

            cpf[strcspn(cpf, "\n")] = 0;
            cliente->cpf[strcspn(cliente->cpf, "\n")] = 0;

            if (!strcmp(cliente->cpf, cpf))
            {
                printf("Cliente existe! \n");
                return 1;
            }
        }
        printf("Cliente inexistente! \n");
        return 0;
    }
    else
    {
        return 0;
    }
}

Cliente *inputClientValues(void)
{
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));

    char nome[50];
    char cpf[15];
    char telefone[15];
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[50];

    do
    {
        printf(" Digite o nome: \n");
        fgets(nome, sizeof nome, stdin);

    } while (onlyTextInput(nome) == False2);

    do
    {
        printf(" Digite o CPF: \n");
        fgets(cpf, sizeof cpf, stdin);

    } while (CPFValidation(cpf) == False2 || verifyCPFInFile(cpf) == 1);

    do
    {
        printf(" Digite o telefone: \n");
        fgets(telefone, sizeof telefone, stdin);
    } while (onlyNumberInput(telefone) == False2);

    do
    {
        printf(" Digite a rua: \n");
        fgets(rua, sizeof rua, stdin);
    } while (onlyTextInput(rua) == False2);

    do
    {
        printf(" Digite o bairro: \n");
        fgets(bairro, sizeof bairro, stdin);
    } while (onlyTextInput(bairro) == False2);

    do
    {
        printf(" Digite a cidade: \n");
        fgets(cidade, sizeof cidade, stdin);
    } while (onlyTextInput(cidade) == False2);

    do
    {
        printf(" Digite o estado: \n");
        fgets(estado, sizeof estado, stdin);
    } while (onlyTextInput(estado) == False2);

    strcpy(cliente->nome, nome);
    strcpy(cliente->cpf, cpf);
    strcpy(cliente->telefone, telefone);
    strcpy(cliente->rua, rua);
    strcpy(cliente->bairro, bairro);
    strcpy(cliente->cidade, cidade);
    strcpy(cliente->estado, estado);

    cliente->status = 1;

    return cliente;
}

void updateClientValues(void)
{
    FILE *file = fopen("clientes.dat", "r+b");
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    Cliente *aux_cliente = (Cliente *)malloc(sizeof(Cliente));

    int found = 0;
    long int menos_um = -1;

    char nome[50];
    char telefone[20];
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[50];

    cliente = buscaCliente();

    if (file)
    {

        if (!cliente)
        {
            printf("Cliente nao existe");
        }

        else if (cliente->status == 0)
        {
            printf("Cliente inativo, deseja reativar? (s/n) \n");
            char opcao;
            scanf("%c", &opcao);
            getchar();
            if (opcao == 's')
            {

                cliente->status = 1;

                // https://github.com/CharlesEdu07/SIG-Customer/blob/main/customer.c

                while (!feof(file) && !found)
                {
                    fread(aux_cliente, sizeof(Cliente), 1, file);

                    if (strcmp(aux_cliente->cpf, cliente->cpf) == 0)
                    {
                        found = 1;

                        fseek(file, (menos_um) * sizeof(Cliente), SEEK_CUR);

                        fwrite(cliente, sizeof(Cliente), 1, file);
                    }
                }
                //////////////////////////////////

                fclose(file);
                free(cliente);
                free(aux_cliente);

                printf("Cliente reativado com sucesso! \n");
            }
        }
        else
        {
            do
            {
                printf(" Digite o nome: \n");
                fgets(nome, sizeof nome, stdin);

            } while (onlyTextInput(nome) == False2);

            do
            {
                printf(" Digite o telefone: \n");
                fgets(telefone, sizeof telefone, stdin);
            } while (onlyNumberInput(telefone) == False2);

            do
            {
                printf(" Digite a rua: \n");
                fgets(rua, sizeof rua, stdin);
            } while (onlyTextInput(rua) == False2);

            do
            {
                printf(" Digite o bairro: \n");
                fgets(bairro, sizeof bairro, stdin);
            } while (onlyTextInput(bairro) == False2);

            do
            {
                printf(" Digite a cidade: \n");
                fgets(cidade, sizeof cidade, stdin);
            } while (onlyTextInput(cidade) == False2);

            do
            {
                printf(" Digite o estado: \n");
                fgets(estado, sizeof estado, stdin);
            } while (onlyTextInput(estado) == False2);

            strcpy(cliente->nome, nome);
            strcpy(cliente->telefone, telefone);
            strcpy(cliente->rua, rua);
            strcpy(cliente->bairro, bairro);
            strcpy(cliente->cidade, cidade);
            strcpy(cliente->estado, estado);

            // https://github.com/CharlesEdu07/SIG-Customer/blob/main/customer.c

            while (!feof(file) && !found)
            {
                fread(aux_cliente, sizeof(Cliente), 1, file);

                if (strcmp(aux_cliente->cpf, cliente->cpf) == 0)
                {
                    found = 1;

                    fseek(file, (menos_um) * sizeof(Cliente), SEEK_CUR);

                    fwrite(cliente, sizeof(Cliente), 1, file);
                }
            }
            //////////////////////////////////

            fclose(file);
            free(cliente);
            free(aux_cliente);
        }
    }
    else
    {
        printf("Erro ao abrir o arquivo");
    }
}

void deleteClientValues(void)
{
    FILE *file = fopen("clientes.dat", "r+b");
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    Cliente *aux_cliente = (Cliente *)malloc(sizeof(Cliente));

    int found = 0;

    cliente = buscaCliente();

    if (file)
    {

        cliente->status = 0;

        long int menos_um = -1;

        // https://github.com/CharlesEdu07/SIG-Customer/blob/main/customer.c

        while (!feof(file) && !found)
        {
            fread(aux_cliente, sizeof(Cliente), 1, file);

            if (strcmp(aux_cliente->cpf, cliente->cpf) == 0)
            {
                found = 1;

                fseek(file, (menos_um) * sizeof(Cliente), SEEK_CUR);

                fwrite(cliente, sizeof(Cliente), 1, file);
            }
        }
        //////////////////////////////////

        fclose(file);
        free(cliente);
        free(aux_cliente);
    }
    else
    {
        printf("Erro ao abrir o arquivo");
    }
}

void updateVehicleValues(void)
{
    FILE *file = fopen("veiculos.dat", "r+b");
    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    Veiculo *aux_veiculo = (Veiculo *)malloc(sizeof(Veiculo));

    int found = 0;
    long int menos_um = -1;

    char modelo[30];
    char marca[30];
    char ano[10];
    char valor[50];
    char cor[20];

    veiculo = buscaVeiculo();

    if (file)
    {

        if (!veiculo)
        {
            printf("Veiculo nao existe \n");
        }
        else if (veiculo->status == 0)
        {
            printf("Veiculo inativo, deseja reativar? (s/n) \n");
            char opcao;
            scanf("%c", &opcao);
            getchar();

            if (opcao == 's')
            {
                veiculo->status = 1;

                while (!feof(file) && !found)
                {
                    fread(aux_veiculo, sizeof(Veiculo), 1, file);

                    if (strcmp(aux_veiculo->placa, veiculo->placa) == 0)
                    {
                        found = 1;

                        fseek(file, menos_um * sizeof(Veiculo), SEEK_CUR);
                        fwrite(veiculo, sizeof(Veiculo), 1, file);
                    }
                }

                fclose(file);
                free(veiculo);
                free(aux_veiculo);

                printf("Veiculo reativado com sucesso! \n");
            }
        }
        else
        {
            do
            {
                printf(" Digite a marca: \n");
                fgets(marca, sizeof marca, stdin);

            } while (onlyTextInput(marca) == False2);

            do
            {
                printf(" Digite o modelo: \n");
                fgets(modelo, sizeof modelo, stdin);

            } while (onlyTextInput(modelo) == False2);

            do
            {
                printf(" Digite o ano: \n");
                fgets(ano, sizeof ano, stdin);
            } while (onlyNumberInput(ano) == False2);

            do
            {
                printf(" Digite o valor: \n");
                fgets(valor, sizeof valor, stdin);
            } while (onlyNumberInput(valor) == False2);

            do
            {
                printf(" Digite a cor: \n");
                fgets(cor, sizeof cor, stdin);
            } while (onlyTextInput(cor) == False2);

            strcpy(veiculo->marca, marca);
            strcpy(veiculo->modelo, modelo);
            strcpy(veiculo->ano, ano);
            strcpy(veiculo->valor, valor);
            strcpy(veiculo->cor, cor);

            while (!feof(file) && !found)
            {
                fread(aux_veiculo, sizeof(Veiculo), 1, file);

                if (strcmp(aux_veiculo->placa, veiculo->placa) == 0)
                {
                    found = 1;

                    fseek(file, menos_um * sizeof(Veiculo), SEEK_CUR);
                    fwrite(veiculo, sizeof(Veiculo), 1, file);
                }
            }

            fclose(file);
            free(veiculo);
            free(aux_veiculo);
        }
    }
    else
    {
        printf("Erro ao abrir o arquivo");
    }
}

void deleteVehicleValues(void)
{
    FILE *file = fopen("veiculos.dat", "r+b");
    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    Veiculo *aux_veiculo = (Veiculo *)malloc(sizeof(Veiculo));

    int found = 0;

    veiculo = buscaVeiculo();
    if (file)
    {

        veiculo->status = 0;

        long int menos_um = -1;

        // https://github.com/CharlesEdu07/SIG-Customer/blob/main/customer.c

        while (!feof(file) && !found)
        {
            fread(aux_veiculo, sizeof(Veiculo), 1, file);

            if (strcmp(aux_veiculo->placa, veiculo->placa) == 0)
            {
                found = 1;

                fseek(file, (menos_um) * sizeof(Veiculo), SEEK_CUR);

                fwrite(veiculo, sizeof(Veiculo), 1, file);
            }
        }
        //////////////////////////////////

        fclose(file);
        free(veiculo);
        free(aux_veiculo);
    }
    else
    {
        printf("Erro ao abrir o arquivo");
    }
}

void updateRentalValues(void)
{
    FILE *file = fopen("locacoes.dat", "r+b");
    Locacao *locacao = (Locacao *)malloc(sizeof(Locacao));
    Locacao *aux_locacao = (Locacao *)malloc(sizeof(Locacao));

    int found = 0;

    char data_locacao[20];
    char data_devolucao[20];

    locacao = buscaLocacao();

    if (file)
    {

        if (locacao->cliente == NULL)
        {
            printf("Cliente nao existe");
        }
        else
        {

            do
            {
                printf(" Digite a data de locacao: \n");
                fgets(data_locacao, sizeof data_locacao, stdin);

            } while (onlyNumberInput(data_locacao) == 0);

            do
            {
                printf(" Digite a data de devolucao: \n");
                fgets(data_devolucao, sizeof data_devolucao, stdin);
            } while (onlyNumberInput(data_devolucao) == 0);

            strcpy(locacao->data_locacao, data_locacao);
            strcpy(locacao->data_devolucao, data_devolucao);

            long int menos_um = -1;

            // https://github.com/CharlesEdu07/SIG-Customer/blob/main/customer.c

            while (!feof(file) && !found)
            {
                fread(aux_locacao, sizeof(Locacao), 1, file);

                if (strcmp(aux_locacao->cliente, locacao->cliente) == 0)
                {
                    found = 1;

                    fseek(file, (menos_um) * sizeof(Locacao), SEEK_CUR);

                    fwrite(locacao, sizeof(Locacao), 1, file);
                }
            }
            //////////////////////////////////

            fclose(file);
            free(locacao);
            free(aux_locacao);
        }
    }
    else
    {
        printf("Erro ao abrir o arquivo");
    }
}

void deleteRentalValues(void)
{
    FILE *file = fopen("locacoes.dat", "r+b");
    Locacao *locacao = (Locacao *)malloc(sizeof(Locacao));
    Locacao *aux_locacao = (Locacao *)malloc(sizeof(Locacao));

    int found = 0;

    locacao = buscaLocacao();
    if (file)
    {

        locacao->status = 0;

        long int menos_um = -1;

        // https://github.com/CharlesEdu07/SIG-Customer/blob/main/customer.c

        while (!feof(file) && !found)
        {
            fread(aux_locacao, sizeof(Locacao), 1, file);

            if (strcmp(aux_locacao->cliente, locacao->cliente) == 0)
            {
                found = 1;

                fseek(file, (menos_um) * sizeof(Locacao), SEEK_CUR);

                fwrite(locacao, sizeof(Locacao), 1, file);
            }
        }
        //////////////////////////////////

        fclose(file);
        free(locacao);
        free(aux_locacao);
    }
    else
    {
        printf("Erro ao abrir o arquivo");
    }
}

Locacao *inputRentalValues(void)
{
    Locacao *locacao = (Locacao *)malloc(sizeof(Locacao));

    char placa[10];
    char data[15];
    char valor[50];
    char cliente[15];

    do
    {
        printf("Digite o CPF do cliente: \n");
        fgets(cliente, sizeof cliente, stdin);

    } while (CPFValidation(cliente) == False2 || verifyCPFInFile(cliente) == 0);

    do
    {
        printf("Digite a placa do veiculo: \n");
        fgets(placa, sizeof placa, stdin);
    } while (carPlateValidation(placa) == False2 || verifyPlateInFile(placa) == 0);

    do
    {
        printf("Data da locacao: \n");
        fgets(data, sizeof data, stdin);
    } while (onlyNumberAndTextInput(data) == 0);

    do
    {
        printf("Valor combinado: \n");
        fgets(valor, sizeof valor, stdin);
    } while (onlyNumberInput(valor) == 0);

    strcpy(locacao->cliente, cliente);
    strcpy(locacao->placa, placa);
    strcpy(locacao->data_locacao, data);
    strcpy(locacao->valor, valor);
    strcpy(locacao->data_devolucao, "Aberto");
    locacao->status = 1;

    return locacao;
}