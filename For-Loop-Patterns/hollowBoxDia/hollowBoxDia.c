#include <stdio.h>
#include "hollowBoxDia.h"

int size;
void start(){
    printf("Hello! Enter size of diamond: ");
    scanf("%d", &size);
    printDiamond(size);
}

void printDiamond(int x){
    for (int y = 1; y <= 2*x+1; y++){printf("* ");} printf("\n");
    for (int i = 1; i <= x; i++){
        printf("* ");
        for (int space = 1; space <= x-i; space++){
                printf("  ");
        }
        for (int j = 1; j <= 2*i-1; j++){
            printf("* ");
        }
        for (int space = 1; space <= x-i; space++){
                printf("  ");
        }
        printf("* ");printf("\n");
    }

    for (int i = 1; i < x; i++){
        printf("* ");
        for (int space = 1; space <= i; space++){
                printf("  ");
        }
        for (int j = 1; j <= 2*x-(i*2+1); j++){
            printf("* ");
        }
        for (int space = 1; space <= i; space++){
            printf("  ");
        }
        printf("* ");printf("\n");
    }
    for (int y = 1; y <= 2*x+1; y++){printf("* ");} printf("\n");
}
