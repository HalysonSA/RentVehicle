#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controle_clientes.h"

void gravaCliente(Cliente *cliente)
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

Cliente *buscaCliente(void)
{
    FILE *fp;
    Cliente *cliente;

    char cpf_cliente[15];
    printf("Informe o CPF do Cliente: ");
    scanf("%s", cpf_cliente);

    cliente = (Cliente *)malloc(sizeof(Cliente));
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
        if (cliente->cpf == cpf_cliente)
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