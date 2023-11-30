#include <stdio.h>
#include <math.h>
#include "centavoChange.h"

float money;
int start(){
    printf("\n\nHello! Enter money: $");
    scanf("%f", &money);
    if (money == 0){return 0;}
    centavoChange(money);return 1;
}

void centavoChange(float x){
    int twntyFiveCents, fiveCents, cent;
    cent = round((x-(int)x)*100);

    printf("\nYour money $%.2f is $%d with centavo changes of: \n", money, (int)money);

    twntyFiveCents = cent/25;
    cent -= twntyFiveCents*25;
    printf("No. of 25 cents    = %d\n", twntyFiveCents);

    fiveCents =  cent/5;
    cent -= fiveCents*5;
    printf("No. of 5 cents     = %d\n", fiveCents);

    printf("No. of 1 cents     = %d\n", cent); printf("---------------------\n");
}