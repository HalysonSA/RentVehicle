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
#include "controle_funcionarios.h"
#include "controle_veiculos.h"
#include "controle_locacoes.h"
#include "controle_financeiro.h"

int main()
{
    char choice = menu_principal();

    system("cls");

    while (isdigit(choice) && choice != '0')
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
            controle_funcionarios();
        }

        else if (choice == '4')
        {
            controle_veiculos();
        }

        else if (choice == '5')
        {
            controle_financeiro();
        }

        else
        {
            printf("\nEscolha Invalida!\n");
            printf("Pressione qualquer tecla para continuar...");
            getchar();
        }

        choice = menu_principal();
    }

    return 0;
}
