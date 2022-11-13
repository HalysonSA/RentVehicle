#include "controle_clientes.h"
#include "controle_veiculos.h"
#include "controle_locacoes.h"

int onlyNumberAndTextInput(char *);
int onlyNumberInput(char *);
int onlyTextInput(char *);
Veiculo *inputVehicleValues(void);
Cliente *inputClientValues(void);
Locacao *inputRentalValues(void);
void updateClientValues(void);
void updateVehicleValues(void);
void updateRentalValues(void);