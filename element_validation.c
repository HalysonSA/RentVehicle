#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int True1 = 1;
const int False1 = 0;

int CPFValidation(char cpf[11]){
    int i, firstDigit, secondDigit;
    int checkFirstDigit = 0;
    int checkSecondDigit = 0;
    for(i = 0; i < 9;i++){
        checkFirstDigit += (cpf[i]-'0')*(i+1);
    }
    firstDigit = checkFirstDigit % 11;
    if (firstDigit >= 10) {
        firstDigit = 0;
    }

    for(i = 0; i < 10;i++){
        checkSecondDigit += (cpf[i]-'0')*i;
    }
    secondDigit = checkSecondDigit % 11;
    if (secondDigit >= 10) {
        secondDigit = 0;
    }

    if (firstDigit == (cpf[9]-'0') && secondDigit == (cpf[10]-'0')) {
        system("cls||clear");
        return True1;
    }else{
        system("cls||clear");
        printf("CPF Inválido \n");
        return False1;
    }
}

int carPlateValidation(char plate[7]){
    
    char plateLetters[4] = {plate[0],plate[1],plate[2],plate[4]};
    char plateNumbers[4] = {plate[3],plate[5],plate[6]};

    if (strpbrk(plateNumbers, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c") == NULL && strpbrk(plateLetters, "0123456789abcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c") == NULL) {
        system("cls||clear");
        return True1;
    }else{
        system("cls||clear");
        printf("Digite a Placa Corretamente com NUMEROS e LETRAS maiusculas (LLLNLNN) \n");
        return False1;
    }
}