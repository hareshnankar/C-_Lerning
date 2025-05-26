#test 1
#hello:	main.c
#	gcc	-o	hello	main.c

# 	This Makefile rule is almost correct! Here’s what it does:
#	Target: hello—this tells make that you want to build an executable named hello. 
#	we can use make hello command to run this (any name we can give suppose haresh: main.c  so make haresh)
#	Dependency: main.c — this means hello depends on main.c to be compiled.
#	Command: gcc -o hello main.c—this compiles main.c directly into an executable named hello.

#	Explaination for 	gcc	-o	hello	main.c (after this hello.exc is created we can give any name for this also ) 
#	The -o option in gcc (GNU Compiler Collection) specifies the output file name for the compiled program.
# 	SYNTHAX gcc -o output_file source_file.c
#	This compiles main.c and creates an executable file named hello.
#	Without -o, gcc would default to naming the output a.out (on Unix/Linux).

#	Why use -o?
#	Allows you to name your executable instead of relying on the default (a.out).
#	Improves organization when compiling multiple programs.
#	Useful for scripting and automation.

#	Potential Issues
#	This will work if main.c is a single source file with a main() function.
#	If main.c has dependencies on other .h or .c files, you'd need more rules in your Makefile.
#	You don't need -c here; gcc -o hello main.c already compiles and links the program.

#test 1 imprived verion 
haresh: main.o
	gcc -o first_test main.o

main.o:	main.c
	gcc -c main.c 

#exicution 
# make haresh
#gcc -c main.c #first it will creat main.o using gcc -c main.c file -c will compile main.c and creat main.o file 
#gcc -o first_test main.o #then it will run gcc -o first_test main.o 
#means used main.o and craet first_test.exe file 





