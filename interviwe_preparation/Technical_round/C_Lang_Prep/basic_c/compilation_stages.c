/*
-----------------            STEP1            
|  helloW   .c  | ------> PREPROCESSOR <----- Header files,macros,preprocessor
-----------------             ||
    initial file              ||
                              \/
        STEP2            ------------
      COMPILATION <------| hellow.i |
          ||             ------------
          \/            intermediat file
  ------------------     
  |hellow.s or .asm|
  ------------------
  asseblely code file
          ||
          ||
          \/             library files
        STEP3                 ||
      ASSEMBLER               \/
  ------------------         STEP4          ------------
  |hellow.obj or .o| -----> LINKER ------>  |hellow.exe|
  ------------------                        ------------

1.PREPROCESSORS:
It performs the following tasks:
1.Removing comments
2.Header files inclusion
3.Macro expansion
4.Resolve the conditional compilation directives

2.COMPILATION
It performs the following tasks:
1.output of the preprocessor(.i file) and converts it to assembly language
2.Assembly code, often referred to as assembly language which involve obcode represent CPU operations
3.This is exactly the same code you may have worked with when programming microcontrollers directly in assembly language (e.g., 8051 microcontroller).

3.ASSEBLER
It performs the following tasks:
1.The tool that converts Assembly code into machine code is called assembler, and its task is called assembling.
2.In low-level microcontroller programming, the assembler converts the assembly code into a binary sequence

4.LINKING
1.The linker merges all the object code from multiple modules into a single one. 
2.If we are using a function from libraries, linker will link our code with that library function code
3.For libraries outside the C standard library, you must to link it manually
4.The output is non-readable.

IMPORTANT POINT TO REMENMBER
1.after compilation we will get synthax error if it is there 
2.after after .exc we will get logical/input data error if it is there 


          

*/