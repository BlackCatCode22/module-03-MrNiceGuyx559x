#include <stdio.h>

int main() {
    int arr[5] = { 10, 20, 30, 40, 50 }; // Declare an array of integers with 5 elements

    // Print the address of each element in the array using pointer arithmetic
    printf("Addresses of each element in the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Address of arr[%d]: %p\n", i, (void*)&arr[i]);
    }

    // Increment a pointer to traverse the array and print each value
    printf("\nValues of each element in the array:\n");
    int* ptr = arr; // Initialize a pointer to the first element of the array
    for (int i = 0; i < 5; i++) {
        printf("Value at arr[%d]: %d\n", i, *ptr);
        ptr++; // Increment the pointer to point to the next element
    }

    return 0;
}