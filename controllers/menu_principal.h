
#include <stdio.h>

#include "controle_clientes.h"
#include "controle_funcionarios.h"
#include "controle_veiculos.h"
#include "controle_locacoes.h"
#include "controle_financeiro.h"

int menu_principal()
{

    printf("=============== MENU PRINCIPAL ===============\n");
    printf("======    0 - Encerrar Programa         ======\n");
    printf("======    1 - Controle de locacoes      ======\n");
    printf("======    2 - Controle de clientes      ======\n");
    printf("======    3 - Controle de funcionarios  ======\n");
    printf("======    4 - Controle de veiculos      ======\n");
    printf("======    5 - Controle do financeiro    ======\n");
    printf("======    0 - Encerrar Programa         ======\n");
    printf("==============================================\n");

    int choice;
    printf("Digite a opcao desejada: ");
    scanf("%d", &choice);

    return choice;
}