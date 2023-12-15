#include <stdio.h>
#include "printCalendar.h"

int start(){
    int year;

    printf("\nHello, let's print a calendar!\nEnter year (not earlier than 2023): ");
    scanf("%d", &year);
    if (year == 0){
        return 0;
    }
    printCalendar(year);
}

void printMonth(int month){
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        printf("%s\n", months[month-1]);
}
////// --------->>>> CHECK WHAT WENT WRONG
int printCalendar(int year){
    int month=1;
    int days, daycount=1, weekcheck=1;
    int startingDate = (year-2023) % 7; // What day of the week the first day resides        
    
    printf("\n    ---------\nYEAR %d CALENDAR\n    ---------\n\n", year);
    for (int i = 1; i <= 12; i++, month++){
        if (month == 4 || month == 6 || month == 9 || month == 11){
            days = 30;    
        } else if(month == 2){
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){   //Checks for leap year
                days = 29;
            } else {days = 28;}
        } else {days = 31;}

        printMonth(month); 

        for (int j = 0; j < startingDate; j++){
            printf("   ");
        }
        for (int j = 1; j <= days; j++){
            printf("%2d ", j);
            if (++weekcheck > 7){  // ??? It works, why
                printf("\n");
                weekcheck = 1;
            }
        }   
        printf("\n\n");

        startingDate = (startingDate + days) % 7;  // Update startingDate for the next month
        weekcheck = startingDate + 1; // Reset weekcheck for the new month
    }
}