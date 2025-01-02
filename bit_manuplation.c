#include <stdio.h>
//note ;imp- if we want same bit of collection of bit then & with 1 or collection of 1
unsigned int value = 0b00001111;
void printb(unsigned int a)
{
    unsigned int size = sizeof(a);
    //printf("size = %d\n",size);
    unsigned int no_of_bits = size * 8;
    //printf("no_of_bits = %d\n",no_of_bits);// from 31 to 0 bittranval 
    for(int i = no_of_bits -1;i>=0;i--)
    {
        int bit = (a >> i ) & 1 ;
        printf("%d",bit);
    }
    printf("\n");
    
}
unsigned int set_bit(unsigned int a, int pos)
{
    a = a | 1<<(pos-1);// set 
    return a;
}
unsigned int Reset_bit(unsigned int a, int pos)
{
    a = a & ~(1<<(pos-1));// set 
    return a;
}

unsigned int toggle_bit(unsigned int a, int pos)
{
    a = a ^ 1<<(pos-1);// set 
    return a;
}
unsigned int swap_bit(unsigned int a ,int pos1,int pos2)
{
// Extract the bits at pos1 and pos2
unsigned int bit1 = (a >> (pos1 - 1) ) & 1;
unsigned int bit2 = (a >> (pos2 - 1) ) & 1;
 // If the bits are different, swap them
 if(bit1 != bit2)
 {
    unsigned int xor_mask = (1 << (pos1 - 1)) | (1 << (pos2 - 1));
    a = a ^ xor_mask;
 }
 return a;
}
unsigned int swap_nibbles(unsigned int a )
{

    // Extract the nibbles at pos1 and pos2
    unsigned int nibble_low = a  & 0x0f;
    unsigned int nibble_high= (a >> 4 ) & 0x0f;
    return ((nibble_low << 4)  | nibble_high);
 }

 unsigned int swap_byte(unsigned int a )
{
    // Extract the nibbles at pos1 and pos2
    unsigned int byte_low = a  & 0xFf;
    unsigned int byte_high= (a >> 8 ) & 0xFf;
    return ((byte_low << 8)  | byte_high);
 }
int main() {

printb(value);
// value = set_bit(value,2);
// printb(value);
// value = Reset_bit(value,2);
// printb(value);
// value = toggle_bit(value,2);
// printb(value);
//value = swap_bit(value,1,2);
//printb(value);
//value = swap_nibbles(value);
value = swap_byte(value);

printb(value);
}



