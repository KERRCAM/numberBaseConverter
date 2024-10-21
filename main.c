#include "main.h"

// ------------------------------------------------------------------------ //

int intInput(char prompt[32]){

    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;

}

// ------------------------------------------------------------------------ //

void getString(int base, char *str){
    char newStr[16];
    printf("Enter a base %d number: ", base);
    scanf("%s", &newStr);
    strcpy(str, newStr);
}

// ------------------------------------------------------------------------ //

double logx(int number, int base){

    double loggedNumber = log(number) / log(base);
    return loggedNumber;

}

// ------------------------------------------------------------------------ //

int toDenary(char initialNumber[16], int base){

    int denaryNumber = 0;
    int digits = strlen(initialNumber);
    int j = 0;
    for (int i = digits - 1; i > -1; i--){
        if (initialNumber[i] >= 'A' && initialNumber[i] <= 'F'){
            denaryNumber += pow(base, j) * (initialNumber[i] - 55);
        } else if (isdigit(initialNumber[i])){
            denaryNumber += pow(base, j) * (initialNumber[i] - 48);
        } else{
            //invalid char
        }
        j++;
    }
    return denaryNumber;

}

// ------------------------------------------------------------------------ //

void denaryToBinary(char *str, int denaryNumber){
    int size = (int) (ceil(ceil(logx(denaryNumber, 2)) / 4) * 4);
    char binaryNumber[size];
    for (int i = 0; i < size; i++){
        binaryNumber[i] = '0';
    }
    binaryNumber[size] = '\0';
    while (denaryNumber > 0){
        int pos = floor(logx(denaryNumber, 2));
        binaryNumber[size - pos - 1] = '1';
        denaryNumber -= pow(2, pos);
    }
    strcpy(str, binaryNumber);
}

// ------------------------------------------------------------------------ //

void denaryToOctal(char *str, int denaryumber){
    // should be same as hex but with base 8s and differnt char limits
}

// ------------------------------------------------------------------------ //

void denaryToHex(char *str, int denaryNumber){
    int size = (int) ceil(logx(denaryNumber, 16));
    char hexNumber[size];
    for (int i = 0; i < size; i++){
        hexNumber[i] = '0';
    }
    hexNumber[size] = '\0';
    while (denaryNumber > 0){
        int pos = floor(logx(denaryNumber, 16));
        printf("pos: %d\n", pos);
        printf("test: %f\n", pow(16, pos));
        int currDigit = floor(denaryNumber / pow(16, pos));
        char currChar;
        if (currDigit > 9){
            currChar = 55 + currDigit;
        } else{
            currChar = currDigit + 48;
        }
        hexNumber[pos] = currChar;
        denaryNumber -= currDigit;
        printf("digit: %d\n", currDigit);
        printf("char: %c\n", currChar);
    }
    strcpy(str, hexNumber);
}

// ------------------------------------------------------------------------ //

int main(){

    int initialBase = intInput("Type the base of the initial number: ");
    char initialNumber[16] = "";
    getString(initialBase, initialNumber);
    int translatedBase = intInput("Type the base you want to transalte to: ");
    int denaryNumber = toDenary(initialNumber, initialBase);
    char translatedNumber[16] = "";
    switch (translatedBase){
        case 2:
            denaryToBinary(translatedNumber, denaryNumber);
            break;
        case 8:
            denaryToOctal(translatedNumber, denaryNumber);
            break;
        case 10:
            sprintf(translatedNumber, "%d", denaryNumber);
            break;
        case 16:
            denaryToHex(translatedNumber, denaryNumber);
            break;
    }
    printf("%s\n", translatedNumber);

    return 0;
}

// ------------------------------------------------------------------------ //
