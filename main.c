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

int toBase10(char initialNumber[16], int base){

    int base10Number = 0;
    int digits = strlen(initialNumber);
    int j = 0;
    for (int i = digits - 1; i > -1; i--){
        if (initialNumber[i] >= 'A' && initialNumber[i] <= 'F'){
            base10Number += pow(base, j) * (initialNumber[i] - 55);
        } else if (isdigit(initialNumber[i])){
            base10Number += pow(base, j) * (initialNumber[i] - 48);
        } else{
            //invalid char
        }
        j++;
    }
    return base10Number;

}

// ------------------------------------------------------------------------ //

void base10ToBinary(char *str, int base10Number){
    int size = (int) (ceil(ceil(logx(base10Number, 2)) / 4) * 4);
    char binaryNumber[size];
    for (int i = 0; i < size; i++){
        binaryNumber[i] = '0';
    }
    binaryNumber[size] = '\0';
    while (base10Number > 0){
        int pos = floor(logx(base10Number, 2));
        binaryNumber[size - pos - 1] = '1';
        base10Number -= pow(2, pos);
    }
    strcpy(str, binaryNumber);
}

// ------------------------------------------------------------------------ //

void base10ToOctal(char *str, int base10Number){
    
}

// ------------------------------------------------------------------------ //

void base10ToHex(char *str, int base10Number){
    
}

// ------------------------------------------------------------------------ //

int main(){

    int base = intInput("Type the base of the initial number: ");
    char initialNumber[16] = "";
    getString(base, initialNumber);
    int base10Number = toBase10(initialNumber, base);
    printf("%d\n", base10Number);
    char binaryNumber[16] = "";
    base10ToBinary(binaryNumber, base10Number);
    printf("%s\n", binaryNumber);

    return 0;
}

// ------------------------------------------------------------------------ //
