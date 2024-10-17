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

const char* stringInput(char prompt[]){

    char input[] = "";
    printf(prompt);
    scanf("%s", &input);
    return input;

}

// ------------------------------------------------------------------------------------------ //

const char* initialNumberInput(int base){

    char input[] = "";
    printf("Enter a base %d number: ", base);
    scanf("%s", &input);
    return input;

}

// ------------------------------------------------------------------------------------------ //

int toBase10(char initialNumber[], int base){

    int base10Number = 0;
    for (int i = 0; i < strlen(initialNumber); i++){
        if (isalpha(initialNumber[i])){
            base10Number += pow(base, i) * (initialNumber[i] - 55);
        } else{
            base10Number += pow(base, i) * (initialNumber[i] - 48);
        }
    }
    return base10Number;

}

// ------------------------------------------------------------------------------------------ //

int main(){

    int base = intInput("Type the base of the initial number: ");
    const char* initialNumber = initialNumberInput(base);
    printf("%s\n", *initialNumber);
    int base10Number = toBase10(*initialNumber, base);
    printf("%d\n", base10Number);

    return 0;
}

// ------------------------------------------------------------------------------------------ //
