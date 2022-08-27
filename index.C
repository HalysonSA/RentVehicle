///////////////////////////////////////////////
// Autores: Halyson Santos de Araújo
//          Pedro Henrique Ribeiro
// Data: Agosto/2022.
// Tema do Projeto: Locadora de Veículos 
///////////////////////////////////////////////

#include <stdio.h>

void menu();

void controle_locacoes();
void controle_clientes();
void controle_veiculos();
void controle_funcionarios();
void controle_financeiro();

int main(){
    menu();
    return 0;
}

void menu(){
   
    printf("=============== MENU PRINCIPAL ===============\n");
    printf("======    1 - Controle de locacoes      ======\n");
    printf("======    2 - Controle de clientes      ======\n");
    printf("======    3 - Controle de funcionarios  ======\n");
    printf("======    4 - Controle de veiculos      ======\n");
    printf("======    5 - Controle do financeiro    ======\n");
    printf("==============================================\n");
}


void controle_locacoes(){
    printf("==========================================\n");
    printf("======     CONTROLE DE LOCACOES     ======\n");
    printf("======    1 - Cadastrar locacao     ======\n");
    printf("======    2 - Relatorio locacoes    ======\n");
    printf("======    3 - Editar locacao        ======\n");
    printf("======    4 - Remover locacao       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");
}

void controle_clientes(){
    printf("==========================================\n");
    printf("======     CONTROLE DE CLIENTES     ======\n");
    printf("======    1 - Cadastrar cliente     ======\n");
    printf("======    2 - Relatorio clientes    ======\n");
    printf("======    3 - Editar cliente        ======\n");
    printf("======    4 - Remover cliente       ======\n");
    printf("======    0 - Voltar ao menu        ======\n");
    printf("==========================================\n");
}

void controle_funcionarios(){
    printf("=============================================\n");
    printf("======     CONTROLE DE FUNCIONARIOS    ======\n");
    printf("======    1 - Cadastrar funcionario    ======\n");
    printf("======    2 - Relatorio funcionarios   ======\n");
    printf("======    3 - Editar funcionario       ======\n");
    printf("======    4 - Remover funcionario      ======\n");
    printf("======    0 - Voltar ao menu           ======\n");
    printf("=============================================\n");
}

void controle_veiculos(){
    printf("===========================================\n");
    printf("======     CONTROLE DE VEICULOS      ======\n");
    printf("======    1 - Cadastrar veiculo      ======\n");
    printf("======    2 - Relatorio veiculos     ======\n");
    printf("======    3 - Editar veiculo         ======\n");
    printf("======    4 - Remover veiculo        ======\n");
    printf("======    0 - Voltar ao menu         ======\n");
    printf("===========================================\n");
}

void controle_financeiro(){
    printf("===========================================\n");
    printf("======     CONTROLE DE FINANCEIRO    ======\n");
    printf("======    1 - Cadastrar debito       ======\n");
    printf("======    2 - Cadastrar credito      ======\n");
    printf("======    2 - Relatorio financeiro   ======\n");
    printf("======    3 - Editar conta           ======\n");
    printf("======    0 - Voltar ao menu         ======\n");
    printf("===========================================\n");
}