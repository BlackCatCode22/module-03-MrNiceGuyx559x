#include <stdio.h>

int main() {
    int a = 10; // Declare an integer variable 'a' and assign it a value of 10
    int* p; // Declare a pointer to an integer

    p = &a; // Assign the address of 'a' to the pointer 'p'

    // Print the address stored in 'p' and the value of 'a' using 'p'
    printf("Address stored in p: %p\n", (void*)p);
    printf("Value of a using p: %d\n", *p);

    // Change the value of 'a' using 'p'
    *p = 20;

    // Print the new value of 'a'
    printf("New value of a: %d\n", a);

    return 0;
}