#include <stdio.h>
#include <stdbool.h>
#define NO_OF_BITS_IN_BYTE 8
//note ;imp- if we want same bit of collection of bit then & with 1 or collection of 1
unsigned char value = 0b00001111;
void PrintBinary(unsigned char a)
{
    unsigned int size = sizeof(a);
    //printf("size = %d\n",size);
    unsigned int no_of_bits = size * NO_OF_BITS_IN_BYTE;
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
    a = a | 1 << (pos-1);// set 
    return a;
}
unsigned int Reset_bit(unsigned int a, int pos)
{
    a = a & ~(1 << (pos-1) );// set 
    return a;
}

unsigned int toggle_bit(unsigned int a, int pos)
{
    a = a ^ 1 << (pos-1);// set 
    return a;
}

bool check_bit_is_set_or_no(unsigned int a, int pos)
{
    bool result = a & 1 << (pos-1);// set 
    return result;
}

unsigned char swap_bit(unsigned char a ,int pos1,int pos2)
{
// Extract the bits at pos1 and pos2
//00000
unsigned char bit1 = (a >> (pos1 - 1) ) & 1;
unsigned char bit2 = (a >> (pos2 - 1) ) & 1;
 // If the bits are different, swap them
 if(bit1 != bit2)
 {
    unsigned char cobination = bit1 ^ bit2 ;
    a = (a ^ (cobination << (pos1 - 1))) ^ (cobination << (pos2 - 1));
 }
 return a;
}
unsigned int swap_nibbles(unsigned int a )
{

    return  ((a & 0x0f) << 4)|
            ((a & 0xf0) >> 4);
}

 unsigned int swap_byte(unsigned int a )
{

    return  ((a & 0x00FF) << 8)|
            ((a & 0xFF00) >> 8);
}

int main() {

PrintBinary(value);
// value = set_bit(value,2);
// PrintBinary(value);
// value = Reset_bit(value,2);
// PrintBinary(value);
// value = toggle_bit(value,2);
// PrintBinary(value);
 value = swap_bit(value,1,8);
 PrintBinary(value);
// value = swap_nibbles(value);
// value = swap_byte(value);
// for(int i = 1;i<=8;i++)
// {
//     if(check_bit_is_set_or_no(value,i))
//     {
//         printf("bit is set\n");
//     }
//     else
//     {
//         printf("bit is not set\n");
//     }
// }
//PrintBinary(value);

}



