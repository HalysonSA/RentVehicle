typedef struct
{
    char valor[50];
    char data[10];
    char cliente[11];
    char placa[7];
} Locacao;

char menu_locacoes(void);
void controle_locacoes(void);
void menu_cadastrar_locacao(void);
void menu_editar_locacao(char *);
void menu_remover_locacao(void);
void menu_relatorio_locacao(void);