typedef struct
{
    char valor[50];
    char data_locacao[10];
    char data_devolucao[10];
    char cliente[15];
    char placa[8];
    char status;
} Locacao;

char menu_locacoes(void);
void controle_locacoes(void);
void menu_cadastrar_locacao(void);
void menu_editar_locacao(void);
void menu_remover_locacao(void);
void menu_relatorio_locacao(Locacao *locacao);