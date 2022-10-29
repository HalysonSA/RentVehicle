

typedef struct
{
    char nome[50];
    char cpf[15];
    char endereco[100];
    char telefone[15];
} Cliente;

char menu_clientes(void);
void controle_clientes(void);
void menu_cadastro_cliente(void);
void menu_editar_cliente(char *);
void menu_remover_cliente(void);
void menu_relatorio_cliente(void);
