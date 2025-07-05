
             /*   important therory in pointers  */
/*
 1.dangling pointers: the pointer which is pointing to dead memory 
 location or freedmemory is called as dangling pointer
*/

#include <stdio.h>

int* createPointer() {
    int a = 10;  // Local variable
    int *ptr = &a;  // Pointer to local variable
    return ptr;  // Return pointer to local variable
}



int main() {
    int *ptr = createPointer();  // Get a pointer to local variable
       // At this point, localVar in createPointer has gone out of scope
    // ptr is now a dangling pointer
    printf("value in ptr = %d",*ptr);
    return 0;
}
