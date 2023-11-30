#include <stdio.h>
#include "diamondNumCenter.h"

int size;

void printInput(){
    printf("Hello! Input the size of diamond: ");
    scanf("%d", &size);
    int x = size;
    if (size % 2 == 0){
        x++;
    }
    printDiamond(x);
}

void printDiamond(int x){
    for (int i = 1; i <= (x/2)+1; i++){
        for (int space = 1; space <= (x/2)+1-i; space++){
            printf(" ");
        }
        for (int j = 1; j <= i*2-1; j++){
            if (i == (x/2)+1 && j == (x/2)+1){
                printf("%d", size);
            }else {
                printf("*");
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= x/2; i++){
        for (int space = 1; space <= i; space++){
            printf(" ");
        }
        for (int j = 1; j <= x-2*i; j++){
            printf("*");
        }
        printf("\n");
    }
}
