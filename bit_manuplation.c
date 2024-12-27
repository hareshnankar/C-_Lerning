#include <stdio.h>
unsigned int value = 0x0;
void printb(unsigned int a)
{
    unsigned int size = sizeof(a);
    printf("size = %d\n",size);
    unsigned int no_of_bits = size * 8;
    printf("no_of_bits = %d\n",no_of_bits);// from 31 to 0 bittranval 
    for(int i = no_of_bits -1;i>=0;i--)
    {
        int bit = (a >> i ) & 1 ;
        printf("%d",bit);
    }
    printf("\n");
    
}

int main() {
int pos = 2;
value = value | 1<<(pos-1);// set 
printb(value);
value = value & ~(1<<(pos-1));// reset
printb(value);
value = value ^ (1<<(pos-1));// toggel
printb(value);
}
