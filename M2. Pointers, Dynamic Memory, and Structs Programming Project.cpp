// M2. Pointers, Dynamic Memory, and Structs Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Array Reversal using For Loop Function
#include <stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to reverse the array using a for loop
void reverseArrayForLoop(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers towards the center
        start++;
        end--;
    }
}

int main() {
    //Initialize an array
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //Print original array
    printf("Original array: ");
    printArray(arr, n);

    //Reverse the array using the function
    reverseArrayForLoop(arr, n);

    //Print reversed array
    printf("Reversed array (for loop): ");
    printArray(arr, n);

    return 0;
} 