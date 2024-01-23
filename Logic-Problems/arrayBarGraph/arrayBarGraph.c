#include <stdio.h>
#include "arrayBarGraph.h"

int start() {
    int size;
    
    printf("\nEnter size of the array: ");
    scanf("%d", &size);
    if (size == 0) {
        return 0;
    }
    int arr[size];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    sortArr(arr, size);
    int maxOccurrence = maxNumOccurrences(arr, size);
    int maxNum = arr[size - 1];

    int elementCount = elementCounter(arr, size);
    int arrCopy[elementCount];
    removeDupe(arr, size, arrCopy, elementCount);
    
    int arrCount[elementCount];
    arrCounter(arr, size, arrCopy, arrCount, elementCount);

    printGraph(maxOccurrence, arrCopy, arrCount, elementCount);
    
    return 1;
}
