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
        printf("CPF Invalido \n");
        return False1;
    }
}

int DateValidation(char data[11])
{
    size_t ln = strlen(data) - 1;

    if (data[ln] == '\n')
    {
        data[ln] = '\0';
    }

    char dia[3] = {data[0], data[1]};
    char mes[3] = {data[3], data[4]};
    char ano[5] = {data[6], data[7], data[8], data[9]};

    if (dia[0] >= '0' && dia[0] <= '3' && dia[1] >= '0' && dia[1] <= '9' && mes[0] >= '0' && mes[0] <= '1' && mes[1] >= '0' && mes[1] <= '9' && ano[0] >= '1' && ano[0] <= '2' && ano[1] >= '0' && ano[1] <= '9' && ano[2] >= '0' && ano[2] <= '9' && ano[3] >= '0' && ano[3] <= '9' && ln == 9 && data[2] == '/' && data[5] == '/')
    {
        if (mes[0] == '0' && mes[1] == '2' && dia[0] >= '3' && dia[1] >= '0')
        {
            system("cls||clear");
            printf("Data Invalida \n");
            return False1;
        }
        else if (mes[0] == '0' && mes[1] == '4' && dia[0] >= '3' && dia[1] > '0')
        {
            system("cls||clear");
            printf("Data Invalida \n");
            return False1;
        }
        else if (mes[0] == '0' && mes[1] == '6' && dia[0] >= '3' && dia[1] > '0')
        {
            system("cls||clear");
            printf("Data Invalida \n");
            return False1;
        }
        else if (mes[0] == '0' && mes[1] == '9' && dia[0] >= '3' && dia[1] > '0')
        {
            system("cls||clear");
            printf("Data Invalida \n");
            return False1;
        }
        else if (mes[0] == '1' && mes[1] == '1' && dia[0] >= '3' && dia[1] > '0')
        {
            system("cls||clear");
            printf("Data Invalida \n");
            return False1;
        }
        else
        {
            system("cls||clear");
            return True1;
        }
    }
    else
    {
        system("cls||clear");
        printf("Data Invalida \n");
        return False1;
    }
}

int carPlateValidation(char plate[7])
{
    size_t ln = strlen(plate) - 1;

    if (plate[ln] == '\n')
    {
        plate[ln] = '\0';
    }

    char plateLetters[5] = {plate[0], plate[1], plate[2], plate[4]};
    char plateNumbers[4] = {plate[3], plate[5], plate[6]};

    if (isalpha(plateLetters[0]) && isalpha(plateLetters[1]) && isalpha(plateLetters[2]) && isalpha(plateLetters[3]) && isdigit(plateNumbers[0]) && isdigit(plateNumbers[1]) && isdigit(plateNumbers[2]) && ln == 6)
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