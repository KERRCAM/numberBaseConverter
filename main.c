#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// ------------------------------------------------------------------------------------------ //

int intInput(char prompt[]){

    int input;
    printf(prompt);
    scanf("%d", &input);
    return input;

}

// ------------------------------------------------------------------------------------------ //

void getString(int base, char *str){
    char newStr[16];
    //gets(newStr);
    printf("Enter a base %d number: ", base);
    scanf("%s", &newStr);
    strcpy(str, newStr);
}


// ------------------------------------------------------------------------------------------ //

int toBase10(char initialNumber[], int base){

    int base10Number = 0;
    for (int i = 0; i < strlen(initialNumber); i++){
        if (isalpha(initialNumber[i])){
            base10Number += pow(base, i) * (initialNumber[i] - 0);
        } else{
            base10Number += pow(base, i) * (initialNumber[i] - 48);
        }
        
    }
    return base10Number;

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
