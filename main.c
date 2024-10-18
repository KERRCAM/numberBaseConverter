#include "main.h"
#include <stdbool.h>
// ------------------------------------------------------------------------------------------ //

int intInput(char prompt[32]){

    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;

}

// ------------------------------------------------------------------------------------------ //

void getString(int base, char *str){
    char newStr[16];
    printf("Enter a base %d number: ", base);
    scanf("%s", &newStr);
    strcpy(str, newStr);
}


// ------------------------------------------------------------------------------------------ //

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

// ------------------------------------------------------------------------------------------ //

void base10ToBinary(char *str){

}

// ------------------------------------------------------------------------------------------ //

void base10ToOctal(char *str){
    
}

// ------------------------------------------------------------------------------------------ //

void base10ToHex(char *str){
    
}

// ------------------------------------------------------------------------------------------ //

double logx(int number, int base){

    double loggedNumber = log(number) / log(base);
    
    return loggedNumber;

}

// ------------------------------------------------------------------------------------------ //

int main(){

    int base = intInput("Type the base of the initial number: ");
    char initialNumber[16] = "";
    getString(base, initialNumber);
    int base10Number = toBase10(initialNumber, base);
    printf("%d\n", base10Number);

    return 0;
}

// ------------------------------------------------------------------------------------------ //
