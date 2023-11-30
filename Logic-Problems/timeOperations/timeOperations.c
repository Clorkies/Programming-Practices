#include <stdio.h>
#include "timeOperations.h"

int start(){
    int time, num;
    char timeConvention, response;
    printf("\nInput time: ");
    scanf("%d %c", &time, &timeConvention);
    if (time > 12){ return 0;}

    printf("Add or subtract time (A or S): ");
    scanf(" %c", &response);
    switch (response){
        case 'A': printf("\nEnter time to add: "); scanf("%d", &num); break;
        case 'S': 
            printf("\nEnter time to subtract: "); scanf("%d", &num); 
            num = 0-num;
            break;
        default: break;
    }
    timeOperation(time, num, timeConvention); return 1;
}

void timeOperation(int time, int num, char timeConvention){
    int counter = 1;
    time += num;
    counter += (int)(time/12);

    if (time > 12 || (time <= 12 && time > 0)){
        if (time > 12){time -= 12;}
            if (timeConvention == 'P' && counter % 2 == 0 && counter != 0){
                timeConvention = 'A';
            } else if (timeConvention == 'A' && counter % 2 == 0 && counter != 0){
                timeConvention = 'P';
            }
    } else if (time < 1){
        time = 12 + time;
        if (timeConvention == 'P' && counter % 2 != 0 && counter != 0){
            timeConvention = 'A';
        } else if (timeConvention == 'A' && counter % 2 != 0 && counter != 0){
            timeConvention = 'P';
        }
    }
    printf("\n\nTime is: %d %cM\n----------------\n", time, timeConvention);
}