/*

What is Endianness?
Endianness refers to the order in which bytes are arranged in memory. 
Different languages read their text in different orders. for example, 
English reads from left to right, while Arabic reads from right to left. 
Endianness works similarly for computers. If one computer reads bytes from left to right and another reads them from right to left, 
issues arise when these computers need to communicate

Big-endian (BE): Stores the most significant byte (the “big end”) first. 
This means that the first byte (at the lowest memory address) is the largest,
which makes the most sense to people who read left to right.

Little-endian (LE): Stores the least significant byte (the “little end”) first. 
This means that the first byte (at the lowest memory address) is the smallest, 
which makes the most sense to people who read right to left.

most important part 

1. 8 bit data  ---> 0xFF 
2. 16 bit data ---> 0xFFFF
3. 32 bit data ---> 0xFFFFFFFF

value = 0xABCD-EFGH

Big-endian (BE):

                     MSB        LSB
read from here ----> 0xAB-CD-EF-GH 
mem address--------> 0x01-02-03-04 //msb(bigger end )will store into lowest memory address first

Little-endian (LE):

MSB        LSB
0xAB-CD-EF-GH <---- read from here 
0x04-03-02-01 <-------- mem address //lsb(little end )will store into lowest memory address first



*/

#include <stdio.h>
unsigned int x = 0x76543210; // 32 bit data 
unsigned short y = 0xABCD; // 32 bit data 

void check_endianness(unsigned int *a)
{
  //taking charactor pointer so store fist address of x
  char *c = (char*) a;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10) //here c will contain starting address of x 
                  //if address of 0x10 stored in c then it is littile means *c == 0x10
                  //if address of 0x76 stored in c then it is littile means *c == 0x76
  {
    printf ("little endian. \n");
  }
  else
  {
     printf ("big endian. \n");
  }
}
unsigned int reverse_endianness_32_bit(unsigned int value)
{
printf("size = %lu\n",sizeof(value));
return ((value & 0x000000FF)  << 24  |
        (value & 0X0000FF00)  << 8  |
        (value & 0X00FF0000)  >> 8  |
        (value & 0XFF000000)  >> 24 );
}
unsigned short reverse_endianness_16_bit(unsigned short value)
{
printf("size = %lu\n",sizeof(value));
return ((value & 0x00FF)  << 8  |
        (value & 0XFF00)  >> 8 );
}
int main ()
{
 
    //check_endianness(&x);
    printf ("before x is: 0x%x\n", x);
    x = reverse_endianness_32_bit(x);
    printf ("after x is: 0x%x\n", x);

    printf ("before y is: 0x%x\n", y);
    y = reverse_endianness_16_bit(y);
    printf ("after y is: 0x%x\n", y);
  return 0;
}