
typedef struct
{
    char modelo[30];
    char marca[30];
    char ano[10];
    char placa[10];
    char valor[50];
    char cor[20];
    char status;

} Veiculo;
void controle_veiculos(void);
char menu_veiculos(void);
void menu_cadastrar_veiculo(void);
void menu_editar_veiculo(void);
void menu_remover_veiculo(void);
void menu_relatorio_veiculo(Veiculo *);