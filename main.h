#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int intInput(char prompt[]);

const char* stringInput(char prompt[]);

int toBase10(char initialNumber[], int base);

void base10ToBinary(char *str, int denaryNumber);

void base10ToOctal(char *str, int denaryNumber);

void base10ToHex(char *str, int denaryNumber);

int main();