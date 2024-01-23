#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define MAX_SECT 5

void printAddress(char *address) {  // Issue: When only 1 section of the address is filled, zip code prints out even though no zip code is included
    char section[MAX_SECT][MAX];
    int i = 0, j = 0, k = 0, l = 0, position = 0;

    for (l; l < strlen(address); l++) {
        if (address[l] == ',') {
            position++;
        }
    }

    for (i = (MAX_SECT - 2) - position; i < MAX_SECT; i++) {  
        if (address[k] == ' ') {
            k++;
        }
        for (j = 0; address[k] != ',' && address[k] != '\0'; j++, k++) {
            if (i == 3 && isdigit(address[k + 1])) {
                break;
            }
            section[i][j] = address[k];
        }
        section[i][j] = '\0'; 
        k++; 
    }

    for (i = 0; i < MAX_SECT; i++) {
        if (section[i][0] != '\0') {
            switch (i) {
                case 0: printf("Street:   %s\n", section[i]); break;
                case 1: printf("Barangay: %s\n", section[i]); break;
                case 2: printf("Town:     %s\n", section[i]); break;
                case 3: printf("Province: %s\n", section[i]); break;
                case 4: printf("Zip Code: %s\n", section[i]); break;
                default: break;  
            }
        }
    }
}

int main() {
    char address[MAX];

    printf("\n\nEnter address: ");
    scanf("%99[^\n]", address);

    printAddress(address);

    return 0;
}
