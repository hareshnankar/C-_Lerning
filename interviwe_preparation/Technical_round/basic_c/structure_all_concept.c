/*theory in structure
1.it is user define data type 
2.it use to define different types of data in singe unit - items in struc call its member 
3.the va;ue of structures stored in contigues memory location
two ways to define structure 

1.it is called as structure prototype and no memory is allocated to the 
structure in the declaration.

struct structure_name
{
};

struct structure_name variable_name;

2.structure prototype with declaration

struct structure_name
{
}variable name;

*/
#include <stdio.h>

struct student
{
    int id;
    int roll_no;
};
struct student haresh;

struct student_2
{
    int id;
    int roll_no;
}haresh_n;

/*structure padding example*/

/* Structure Padding Example */

/*
When the compiler reads data, it generally reads 4 bytes at a time in a single CPU cycle.
There are two main options:
1. To reduce CPU cycles: Use structure padding (automatically done by the compiler).
2. To reduce memory consumption: Use structure packing.

1. Structure Padding:
Structure padding is a technique used by the compiler to align the data members of a structure in memory.
This alignment optimizes the access speed of the data members.

2. Structure Packing:
You can instruct the compiler to pack the structure members tightly without padding.
There are two methods for packing structures:

1. Use #pragma pack(1):
This directive tells the compiler to read 1 byte at a time.
struct person
{                 // With padding  With packing          
    char name;    //-->4 bytes     -->1 byte
    int no;       //-->4 bytes     -->4 bytes
    char sirname; //-->4 bytes     -->1 byte
};
struct person haresh_nankar;

2. Use __attribute__((packed)):
This attribute tells the compiler to pack the structure members tightly without padding.
struct person
{                 // With padding  With packing          
    char name;    //-->4 bytes     -->1 byte
    int no;       //-->4 bytes     -->4 bytes
    char sirname; //-->4 bytes     -->1 byte
} __attribute__((packed));
struct person haresh_nankar;
*/


/*structure padding example*/
struct person
{                 //with padding  with packing          
    char name;    //-->4 byte      -->1 byte
    int no;       //-->4 byte      -->4 byte
    char sirname; //-->4 byte      -->1 byte
};

struct person haresh_nankar;
int main ()
{
    haresh.id = 10;
    haresh.roll_no = 20;
    printf("haresh.id ---> %d\n",haresh.id);
    printf("haresh.roll_no ----> %d\n",haresh.roll_no);

    haresh_n.id = 10;
    haresh_n.roll_no = 20;
    printf("haresh_n.id ---> %d\n",haresh_n.id);
    printf("haresh_n.roll_no ----> %d\n",haresh_n.roll_no);

    printf("structure size--->%ld\n",sizeof(haresh_nankar));//size when normal means with padding 
    return 0;
}

