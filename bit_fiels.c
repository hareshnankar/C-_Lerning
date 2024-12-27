#include <stdio.h>

/*
 * Bit Fields Example
 *
 * Bit fields allow you to define the number of bits a particular field within a structure should occupy.
 * This can be useful for memory optimization, 
 --->especially when dealing with hardware registers or network protocols.
 *
 * Key Points:
 * - Bit fields can be used to pack data tightly, saving memory.
 * - The compiler may add padding to align the bit fields to byte or word boundaries.
 * - Bit fields cannot be initialized directly in the structure definition.
 * - Bit fields are typically used with integer types.
 * - we cannot access bitfeilds by address
 * - Accessing bit fields can be slower than accessing regular integers due to bit masking and shifting operations.
 */

struct Status {
    unsigned int is_active : 1;   // 1 bit: Represents whether the system is active (0 or 1)
    unsigned int has_error : 1;   // 1 bit: Represents whether there is an error (0 or 1)
    unsigned int mode : 2;        // 2 bits: Represents the mode (0 to 3)
    unsigned int : 4;             // 4 bits: Padding to make the total size a multiple of the word size
};

int main() {
    struct Status status;

    // Initialize the bit fields
    status.is_active = 1;         // Set is_active to 1 (true)
    status.has_error = 0;         // Set has_error to 0 (false)
    status.mode = 2;              // Set mode to 2

    // Print the values of the bit fields
    printf("is_active: %d\n", status.is_active);  // Output: is_active: 1
    printf("has_error: %d\n", status.has_error);  // Output: has_error: 0
    printf("mode: %d\n", status.mode);            // Output: mode: 2

    // Example of assigning a value larger than the bit field can hold
    status.mode = 5;   
    /*it will give warning : large integer implicitly truncated to unsigned type*/           
    /*mode is 2 bits, so 5 (binary 101) will be truncated to 1 (binary 01)*/
    printf("mode after assigning 5: %d\n", status.mode);  // Output: mode after assigning 5: 1

    return 0;
}