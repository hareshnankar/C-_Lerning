# version 1 : if you have multiple files this is basic version test 1
# hello: main.o   utils.o
# 	gcc -o hello main.o utils.o  # Linking stage
# # Compile main.c into main.o
# main.o: main.c
# 	gcc -c main.c #using this command main.o will be created 
# # Compile utils.c into utils.o
# utils.o: utils.c
# 	gcc -c utils.c #using this command utils.o will be created

#	explaination
# 	gcc -c utils.c using this command utils.o will be created be default 
# 	here you can name your own name for .o file using -o cammand

# # version 2 : here we will change .o name and use that 
# hello: main_test.o   utils_test.o
# 	gcc -o hello main.o utils.o  # Linking stage
# # Compile main.c into main.o
# main_test.o: main.c
# 	gcc -c main.c -o main_test.o #using this command main.o will be created 
# # Compile utils.c into utils.o
# utils_test.o: utils.c
# 	gcc -c utils.c -o utils_test.o #using this command utils.o will be created 

# # version 3 : pattern rule
# %.o: %.c
#     gcc -c $< -o $@
# Of course! This is a pattern rule in a Makefile, 
# used for compiling .c files into .o object files automatically.

# %.o: %.c
# This is a pattern rule, meaning:
# Any .o file depends on a .c file with the same name (file.o depends on file.c).
# gcc -c $< -o $@
# This is the command that compiles the .c file into an .o file.
# $< → Represents the first dependency (the .c file).
# $@ → Represents the target (the .o file).

# Example in Action:
# Suppose you have main.c, utils.c, and math.c. 
# This rule allows make to automatically compile them into:
# main.o
# utils.o
# math.o
# Instead of writing individual rules like:
# hello: main.o   utils.o
# 	gcc -o hello_test main.o utils.o  # Linking stage

# main.o: main.c
#     gcc -c main.c -o main.o

# utils.o: utils.c
#     gcc -c utils.c -o utils.o

hello: main.o   utils.o
	gcc -o hello_test main.o utils.o  # Linking stage
%.o: %.c
	gcc -c $< -o $@