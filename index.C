///////////////////////////////////////////////
// Autores: Halyson Santos de Araújo
//          Pedro Henrique Ribeiro Alves
// Data: Agosto/2022.
// Tema do Projeto: Locadora de Veículos 
///////////////////////////////////////////////

#include <stdio.h>
#include "controllers/menu_principal.h"


int main(){

    int choice = menu_principal();

    while (choice != 0){
        
    if( choice == 1){
        controle_locacoes();
    }
    else if( choice == 2){
        controle_clientes();
    }
    else if( choice == 3){
        controle_funcionarios();
    }
    else if( choice == 4){
        controle_veiculos();
    }
    else if( choice == 5){
        controle_financeiro();
    }
    else{
        printf("\nEscolha Invalida!\n");
    }
    choice = menu_principal();
    
}
}
