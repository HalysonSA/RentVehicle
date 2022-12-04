///////////////////////////////////////////////
// Autores: Halyson Santos de Araújo
//          Pedro Henrique Ribeiro Alves
// Data: Agosto/2022.
// Tema do Projeto: Locadora de Veículos
///////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu_principal.h"
#include "controle_clientes.h"
#include "controle_veiculos.h"
#include "controle_locacoes.h"

int main()
{
    char choice = menu_principal();

    system("cls||clear");

    while (choice != '0')
    {
        if (choice == '1')
        {
            controle_locacoes();
        }

        else if (choice == '2')
        {
            controle_clientes();
        }

        else if (choice == '3')
        {
            controle_veiculos();
        }

        else
        {
            printf("\nEscolha Invalida!\n");
            printf("Pressione enter para continuar... \n");
            getchar();
        }

        choice = menu_principal();
    }

    return 0;
}
