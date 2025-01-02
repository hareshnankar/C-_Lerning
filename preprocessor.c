/* therory about preprocessor
preprocessor directives:
instruction started with # is called as preprocessor,this code is processed before
copilation of code , ; (semicolon) is not required at the end od these instruction

types of preprocessor

1.Macro Definition : #define
2.File Inclusion directive : #include
3.Conditional Compilation : #undef,#if, #ifdef, #else, #elif, #endif 
4.Line control : #line
5.Error directive : #error
6.Pragma direcive : #pragma message,#pragma once.(Commonly used pragma directives)
---------------------------------------------------------------------
---------------------------------------------------------------------
1.Macro Definition : #define
----------------------------------------------------------------------
A.Macro with Parameters and Parentheses
Q. What is the output of the following code?

#include <stdio.h>
#define SQUARE(x) x * x

int main() {
    int a = 5;
    int b = SQUARE(a + 1);
    printf("%d\n", b);
    return 0;
}

ANSWER:
The output is 11, not 36. 
This is because the macro SQUARE(x)
is expanded as a + 1 * a + 1, 
which is equivalent to a + (1 * a) + 1 due to operator precedence.
To fix this, the macro should be defined with parentheses around the parameters

2. stringification
*/
