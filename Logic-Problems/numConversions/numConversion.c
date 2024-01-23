#include <stdio.h>
#include "numConversions.h"

int start() {
    long long convertedNum;
    int num;
    char operation[10];
    char baseNum[10];

    printf("\nSelect base number (Decimal or Binary): ");
    scanf("%[^\n]", baseNum);
    getchar();
    toLowerString(baseNum);

    if (baseNum[0] == 'x') {
        return 0;
    } else if (!isValid(baseNum)) {
        return 1;
    }

    printf("Convert to (Decimal or Binary): ");
    scanf("%[^\n]", operation);
    getchar();
    toLowerString(operation);
    if (!isValid(operation)) {
        return 1;
    }

    printf("Enter %s number: ", baseNum);
    scanf("%d", &num);
    getchar();

    if (strcmp(operation, "binary") == 0) {
        convertedNum = toBin(num);
    } else if (strcmp(operation, "decimal") == 0) {
        convertedNum = toDec(num);
    } else {
        isValid(operation);
    } 

    printf("%d to %s is: %lld\n\n", num, operation, convertedNum);

    return 1;
}