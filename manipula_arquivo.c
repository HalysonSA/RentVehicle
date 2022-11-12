#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controle_clientes.h"
#include "controle_veiculos.h"

Cliente *buscaCliente(void)
{
    FILE *fp;
    Cliente *cliente;

    cliente = (Cliente *)malloc(sizeof(Cliente));
    
    char cpf_cliente[15];

    printf("Informe o CPF do Cliente: ");
    scanf("%s", cpf_cliente);
    getchar();

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        getchar();
        exit(1);
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

void listaClientes(void)
{
    FILE *fp;
    Cliente *cliente;

    cliente = (Cliente *)malloc(sizeof(Cliente));

    fp = fopen("clientes.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    while (fread(cliente, sizeof(Cliente), 1, fp))
    {

        menu_relatorio_cliente(cliente);
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
        exit(1);
    }

    while (fread(veiculo, sizeof(Veiculo), 1, fp))
    {
        menu_relatorio_veiculo(veiculo);
    }
    fclose(fp);
    free(veiculo);
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
