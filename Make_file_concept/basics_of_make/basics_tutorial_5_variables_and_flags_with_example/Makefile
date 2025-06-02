# Compiler and Flags
CC = gcc
CFLAGS = -Wall -O2 -g
LDFLAGS = -lm

# Source and Object Files
SRC = main.c utils.c
OBJ = main.o utils.o

# Target Executable
TARGET = hello

# Build the Executable
$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile Each Source File to Object File
main.o: main.c main.h
    $(CC) $(CFLAGS) -c $< -o $@

utils.o: utils.c utils.h
    $(CC) $(CFLAGS) -c $< -o $@

# Clean Build Artifacts
.PHONY: clean
clean:
    rm -rf $(OBJ) $(TARGET)

#Explanation:

# Variables:
# CC → Stores the compiler (gcc).
# CFLAGS → Compiler flags (-Wall -O2 -g for warnings, optimization, and debugging).
# LDFLAGS → Linker flags (-lm for the math library).
# SRC, OBJ → Manages source and object files.
# TARGET → Specifies the output executable name (hello).

# Automatic Variables:
# $@ → Expands to the target file name.
# $^ → Expands to all dependencies.
# $< → Expands to the first dependency.

# Dependency Management:
# Ensures .c files depend on their respective .h headers.
# Clean Target (.PHONY: clean):
# Prevents conflicts if a file named "clean" exists.

# Runs rm -rf to delete objects and the executable.