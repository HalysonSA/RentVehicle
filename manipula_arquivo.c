#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controle_clientes.h"
#include "controle_veiculos.h"
#include "controle_locacoes.h"
#include "element_validation.h"

Cliente *buscaCliente(void)
{
    FILE *fp;
    Cliente *cliente;

    cliente = (Cliente *)malloc(sizeof(Cliente));

    char cpf_cliente[15];

    do
    {

        printf("Informe o CPF do Cliente: ");
        scanf("%s", cpf_cliente);
        getchar();

    } while (CPFValidation(cpf_cliente) == 0);

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_clientes();
    }
    while (!feof(fp))
    {
        fread(cliente, sizeof(Cliente), 1, fp);
        if (!strcmp(cliente->cpf, cpf_cliente))
        {
            fclose(fp);
            return cliente;
        }
    }
    fclose(fp);
    return NULL;
}

Veiculo *buscaVeiculo(void)
{
    FILE *fp = fopen("veiculos.dat", "rb");
    Veiculo *veiculo;

    veiculo = (Veiculo *)malloc(sizeof(Veiculo));

    char placa[8];

    do
    {

        printf("Informe a placa do veiculo: ");
        scanf("%s", placa);
        getchar();

    } while (carPlateValidation(placa) == 0);

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_veiculos();
    }
    while (!feof(fp))
    {
        fread(veiculo, sizeof(Veiculo), 1, fp);
        if (!strcmp(veiculo->placa, placa))
        {
            fclose(fp);
            return veiculo;
        }
    }

    fclose(fp);
    return NULL;
}

Locacao *buscaLocacao(void)
{
    FILE *fp = fopen("locacoes.dat", "rb");
    Locacao *locacao;

    locacao = (Locacao *)malloc(sizeof(Locacao));

    char placa[8];

    do
    {

        printf("Informe a placa do veiculo: ");
        scanf("%s", placa);
        getchar();

    } while (carPlateValidation(placa) == 0);

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_locacoes();
    }
    while (!feof(fp))
    {
        fread(locacao, sizeof(Locacao), 1, fp);
        if (!strcmp(locacao->placa, placa))
        {
            fclose(fp);
            return locacao;
        }
    }

    free(locacao);
    fclose(fp);
    return NULL;
}

void listaClientes(void)
{
    FILE *fp;
    Cliente *cliente;

    cliente = (Cliente *)malloc(sizeof(Cliente));

    fp = fopen("clientes.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_clientes();
    }
    while (fread(cliente, sizeof(Cliente), 1, fp))
    {

        menu_relatorio_cliente(cliente);
    }
    fclose(fp);
    free(cliente);
}

void listaClientesPorCidade(void)
{
    FILE *fp;
    Cliente *cliente;

    cliente = (Cliente *)malloc(sizeof(Cliente));

    char cidade[50];

    printf("Cidade dos clientes: ");
    fgets(cidade, sizeof cidade, stdin);

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_clientes();
    }
    int len = strlen(cidade);
    int posicao = 0;
    int espaco = 0;

    // https://pt.stackoverflow.com/questions/127177/como-retirar-espa%C3%A7os-de-uma-string-em-c#:~:text=O%20segredo%20%C3%A9%20varrer%20a,%2C%20caso%20contr%C3%A1rio%2C%20ser%C3%A1%20ignorado.

    for (int i = 0; i < len; i++)
    {
        if (cliente->cidade[i] == ' ')
        {
            espaco = 1;
        }
    }

    while (fread(cliente, sizeof(Cliente), 1, fp))
    {

        if (espaco == 1)
        {
            for (int i = 0; i < len; i++)
            {
                if (!(cidade[i] == ' ') || !(cliente->cidade[i] == ' '))
                {
                    cidade[posicao] = cidade[i];
                    cliente->cidade[posicao] = cliente->cidade[i];

                    posicao++;
                }
            }
        }
        size_t ln = strlen(cidade) - 1;

        if (cidade[ln] == '\n')
        {
            cidade[ln] = '\0';
            continue;
        }

        if (!strcmp(cliente->cidade, cidade))
        {

            menu_relatorio_cliente(cliente);
        }
    }
    fclose(fp);
    free(cliente);
}

void listaVeiculos(void)
{
    FILE *fp;
    Veiculo *veiculo;

    veiculo = (Veiculo *)malloc(sizeof(Veiculo));

    fp = fopen("veiculos.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_veiculos();
    }

    while (fread(veiculo, sizeof(Veiculo), 1, fp))
    {
        menu_relatorio_veiculo(veiculo);
    }
    fclose(fp);
    free(veiculo);
}

void listaLocacoes(void)
{
    FILE *fp;
    Locacao *locacao;

    locacao = (Locacao *)malloc(sizeof(Locacao));

    fp = fopen("locacoes.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        controle_locacoes();
    }
    while (fread(locacao, sizeof(Locacao), 1, fp))
    {
        menu_relatorio_locacao(locacao);
    }
    fclose(fp);
    free(locacao);
}

void gravaArquivoCliente(Cliente *cliente)
{
    FILE *fp;
    fp = fopen("clientes.dat", "ab");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        getchar();
        exit(1);
    }
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
}

void gravaArquivoVeiculo(Veiculo *veiculo)
{
    FILE *fp;
    fp = fopen("veiculos.dat", "ab");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        getchar();
        exit(1);
    }
    fwrite(veiculo, sizeof(Veiculo), 1, fp);
    fclose(fp);
}

void gravaArquivoLocacao(Locacao *locacao)
{
    FILE *fp;
    fp = fopen("locacoes.dat", "ab");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        getchar();
        exit(1);
    }
    fwrite(locacao, sizeof(Locacao), 1, fp);
    fclose(fp);
}
