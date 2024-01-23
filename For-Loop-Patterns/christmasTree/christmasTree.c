#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void printTree(int size);
void printGreetings();

int start(){
    int size=1;
    while (size < 3){
        printf("Enter size greater than 2: ");
        scanf("%d", &size);
        if (size <= 0 || !isdigit(size)){return 0;}
    }
    printGreetings();
    printTree(size);
}

void printGreetings(){
    printf("\n");
    printf("         ____\n");
    printf("      .-\" +' \"-.    __,  ,___,\n");
    printf("     /.'.'A_'*`.\\  (--|__| _,,_ ,_ \n");
    printf("    |:.*'/\\-\\. ':|   _|  |(_||_)|_)\\/\n");
    printf("    |:.'.||\"|.'*:|  (        |  | _/\n");
    printf("     \\:~^~^~^~^:/          __,  ,___,\n");
    printf("      /`-....-'\\          (--|__| _ |' _| _,   ,\n");
    printf("     /          \\           _|  |(_)||(_|(_|\\//_)\n");
    printf("     `-.,____,.-'          (               _/\n\n");
}

void printTree(int size){
    char ornaments[] = {'.','*','o','*','^','*','O','+','*','*','.','*','^','*','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}; 
    int spaceLimit = size*2;
    int astLimit = 1;
    srand(time(NULL));

    for (int i = 1; i <= size; i++){
        for (int j = 0; j < 3; j++){
            for (int space = spaceLimit-j; space > 0; space--){
                printf(" ");
            }
            for (int k = 1; k <= (astLimit-1)+((j+1)*2-1); k++){
                if (k == 1 && astLimit == 1 && j == 0){
                    printf("^");
                } else if (k == 1){
                    printf("/");
                } else if (k == (astLimit-1)+((j+1)*2-1)){
                    printf("\\");
                } else {
                    if (j == 2){
                        printf("%c", ornaments[rand() % 27]);
                    } else {
                        printf("%c", ornaments[rand() % 13]);
                    }
                }
                
            }
            printf("\n");
        }
        astLimit += 4;
        spaceLimit -= 2;
    }

    for (int i = 1; i <= 3; i++){
        for (int space = 1; space <= size*2-1; space++){
            printf(" ");
        }
        printf("|||\n");
    }
    printf("\n\n");
}