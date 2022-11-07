
gcc -c -Wall index.c element_validation.c element_input.c controle_clientes.c controle_financeiro.c controle_locacoes.c controle_veiculos.c menu_principal.c manipula_arquivo_cliente.c

gcc -o index element_validation.o element_input.o controle_financeiro.o controle_locacoes.o controle_clientes.o menu_principal.o controle_veiculos.o index.o manipula_arquivo_cliente.o

ASCII = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c"