#pragma once
#include <stdio.h>

void sortArr(int *arr, int size); //Sorts the array from smallest to largest number
int elementCounter(int *arr, int size); //Count the number of unique elements in the array
void removeDupe(int *arr, int size, int *arrCpy, int count); //Copies the unique elements in the array to another array, basically removing the duplicate elements
void arrCounter(int *arr, int size, int *arrCpy, int *arrCount, int count); //Stores the number of occurrences of each element in an array
int maxNumOccurrences(int *arr, int size); //Finds the number of most occurrences 
void printGraph(int maxOccurrence, int *arrCpy, int *arrCount, int count); //Le magic

//Sorts the array from smallest to biggest
void sortArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int temp = 0;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Count the number of unique elements in the array
int elementCounter(int *arr, int size) {
    int counter = 0;
    for (int i = 0; i < size; i ++) {
        if (arr[i] != arr[i + 1]) {
            counter++;
        }
    }
    return counter;
}

//Copies the unique elements in the array to another array, basically removing the duplicate elements
void removeDupe(int *arr, int size, int *arrCpy, int count) {
    for (int i = 0; i < count;) {
        for (int j = 0; j < size; j++) {
            if (arr[j] != arr[j + 1]) {
                arrCpy[i] = arr[j];
                i++;
            }
        }
    }
}

//Stores the number of occurrences of each element in an array
void arrCounter(int *arr, int size, int *arrCopy, int *arrCount, int count) {
    int j = 0;
    for (int i = 0; i < count; i++) {
        int counter = 0;
        for (j; j < size; j++) {
            if (arrCopy[i] == arr[j]) {
                counter++;
            }
            if (arr[j] != arr[j + 1]) {
                j++;
                break;
            }
        }
        arrCount[i] = counter;
    }
}

//Finds the highest number of occurences
int maxNumOccurrences(int *arr, int size) {
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int counter = 0;
        for (int j = i; arr[j] == arr[i]; j++, counter++) {}
        if (counter > maxCount) {
            maxCount = counter;
        }
    }
    return maxCount;
}

void printGraph(int maxOccurrence, int *arrCpy, int *arrCount, int count) {

    printf("\n\n--");
    for (int j = 0; j < count; j++) {
        printf("-----");
    }
    printf("\n");
    for (int j = 0; j < count/4; j++) {
        printf("     ");
    }
    printf("BAR GRAPH VISUALIZATION\n");
    for (int j = 0; j < count; j++) {
        printf("-----");
    }
    printf("--\n\n");

    printf("--");
    for (int j = 0; j < count; j++) {
        printf("-----");
    }
    printf("\n");
    for (int i = maxOccurrence; i >= 0; i--) {
        printf("%d    ", i);
        for (int j = 0; j < count; j++) {
            if (i == 0) {
                printf("%02d   ", arrCpy[j]);
            } else if (i <= arrCount[j]) {
                printf("||   ");
            } else {
                printf("     ");
            }
            
        }
        printf("\n");
    }
    printf("__");
    for (int j = 0; j < count; j++) {
        printf("_____");
    }
    printf("\n\n");
}

#include "arrayBarGraph.c"