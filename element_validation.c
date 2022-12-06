#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int True1 = 1;
const int False1 = 0;

int CPFValidation(char cpf[11])
{
    int i, firstDigit, secondDigit;
    int checkFirstDigit = 0;
    int checkSecondDigit = 0;
    for (i = 0; i < 9; i++)
    {
        checkFirstDigit += (cpf[i] - '0') * (i + 1);
    }
    firstDigit = checkFirstDigit % 11;
    if (firstDigit >= 10)
    {
        firstDigit = 0;
    }

    for (i = 0; i < 10; i++)
    {
        checkSecondDigit += (cpf[i] - '0') * i;
    }
    secondDigit = checkSecondDigit % 11;
    if (secondDigit >= 10)
    {
        secondDigit = 0;
    }

    if (firstDigit == (cpf[9] - '0') && secondDigit == (cpf[10] - '0'))
    {

        size_t ln = strlen(cpf) - 1;

        if (cpf[ln] == '\n')
        {
            cpf[ln] = '\0';
        }
        system("cls||clear");
        return True1;
    }
    else
    {
        system("cls||clear");
        printf("CPF Inválido \n");
        return False1;
    }
}

/*int DateValidation(char data[10]){
    int i, firstDigit, secondDigit;
    int checkFirstDigit = 0;
    for(i = 0; i < 9;i++){
        if (i == 3 || i == 6)
        {
            checkFirstDigit += (cpf[i]-'0');
        }else{
            system("cls||clear");
            printf("Data Inválida \n");
            return False1;
        }
    }
    system("cls||clear");
    return True1;
}*/

int carPlateValidation(char plate[7])
{
    size_t ln = strlen(plate) - 1;

    if (plate[ln] == '\n')
    {
        plate[ln] = '\0';
    }

    char plateLetters[5] = {plate[0], plate[1], plate[2], plate[4]};
    char plateNumbers[4] = {plate[3], plate[5], plate[6]};

    if (isalpha(plateLetters[0]) && isalpha(plateLetters[1]) && isalpha(plateLetters[2]) && isalpha(plateLetters[3]) && isdigit(plateNumbers[0]) && isdigit(plateNumbers[1]) && isdigit(plateNumbers[2]))
    {
        system("cls||clear");
        return True1;
    }
    else
    {
        system("cls||clear");
        printf("Digite no formato (AAA3A33) \n");
        return False1;
    }
}