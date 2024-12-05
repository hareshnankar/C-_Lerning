/*data type and there size
-----------------------------------------------------------------------------------------------------------------------------
types of data type
1.premiteve
2.Derived data types
3.User-defined data types
-----------------------------------------------------------------------------------------------------------------------------
1.premiteve:
predefined data types and can be used directly by the user to declare variables
Examples include: 

datatype          size

1.char            1 byte 
2.int             4 bytes 
3.float           4 bytes
4.double          8 bytes 

1.1.Types of Modifiers in C
Examples include:

datatype           can use on             perpose to use
                   below datatype 

1.short            int                   : It decreases the size of the int to 2 bytes
2.long             int,double            : It increase the original size to two times
3.unsigned         char,short,int,long   : It shifts the data type range to the positive part of the whole numbers
4.signed           char,short,int,long   : It is default modifier of int and char data type if no modifier 
                                           is specified. It indicates that we can store both negative and positive values and 
                                           the range is equally divided to the positive and negative values

Example datatype size with Modifiers in C
Examples include:

datatype                            size                     range

1.char or signed char               1 byte                  -128 to 127
2.unsigned char                     1 byte                   0 to 255

3.short or singed short             2 byte                  -32768 to 32767
3.unsigned short                    2 byte                   0 to 65535

3.short int or singed short int     2 byte                  -32768 to 32767
3.unsigned short int                2 byte                   0 to 65535

3.long or singed long               4 byte                  -2147483648 to 2147483647  = -(65536*65536)/2 to (65536*65536)/2
3.unsigned long                     4 byte                   0 to 4294967295           =  0 to (65536 * 65535)

3.long int or singed long int       8 byte                  -2147483648 to 2147483647  = -(65536*65536)/2 to (65536*65536)/2
3.unsigned long int                 8 byte                   0 to 4294967295           =  0 to (65536 * 65535)

3.float                             4 bytes                  1.175494e-38 to 3.402823e+38
4.double                            8 bytes                  2.225074e-308 to 1.797693e+308

------------------------------------------------------------------------------------------------------------------------------

2.Derived Data Types:
These are data types derived from the primitive data types.
Examples include:
1.Arrays
2.Pointers
3.Functions

------------------------------------------------------------------------------------------------------------------------------
3.User-Defined Data Types: 
are defined by the user itself.
Examples include:
1.Class
2.Structure
3.Union
4.Enumeration

