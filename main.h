#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int intInput(char prompt[]);

const char* stringInput(char prompt[]);

int toBase10(char initialNumber[], int base);

void base10ToBinary(char *str, int base10Number);

void base10ToOctal(char *str, int base10Number);

void base10ToHex(char *str, int base10Number);

int main();