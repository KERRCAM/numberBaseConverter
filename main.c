#include <stdio.h>
#include <string.h>

int main(){

    int base;
    printf("Type the base of the initial number: ");
    scanf("%d", &base);
    char initialNumber[] = "";
    printf("Enter a base %d number: ", base);
    scanf("%s", &initialNumber);

    return 0;
}



