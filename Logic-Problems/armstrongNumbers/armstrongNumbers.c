#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, result = 0, count = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    for(temp = num; temp != 0; temp /= 10){
        count++;
    }
    for(temp = num; temp != 0; temp /= 10){
        result += pow(temp % 10, count);
    }
    printf("%d is %san Armstrong Number\n", num, result == num ? "" : "NOT ");
    
    return 0;
}
