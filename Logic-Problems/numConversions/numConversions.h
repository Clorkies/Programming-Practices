#pragma once
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

long long toBin(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 2) + 10 * toBin(num / 2);
    }
}

long long toDec(int num) {
    if (num == 0)
        return 0;
    else
        return (num % 10) + 2 * toDec(num / 10);
}

int countDigit(int num) {
    if (num == 0) {
        return 0;
    } else { 
        return 1 + countDigit(num/10);
    }
}

void toLowerString(char *word) {
    for (int i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
}

int isValid(char *input) {
    if (strcmp(input, "binary") != 0 && strcmp(input, "decimal") != 0) {
        printf("Invalid operation\n");
        return 0;
    } 
    return 1;
}

#include "numConversion.c"