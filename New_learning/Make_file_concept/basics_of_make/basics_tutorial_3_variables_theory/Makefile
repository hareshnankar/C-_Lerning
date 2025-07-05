#Variables in make files
#	basic synthax 
#		VARIABLE_NAME = value
#		You can reference the variable later using:
#		$(VARIABLE_NAME) or ${VARIABLE_NAME}
#
# 	Where to Use Variables
# 		use                  	common variable name 
# 		Compiler settings 	(CC, CFLAGS, LDFLAGS)
# 		Directories 		(SRC, OBJ)
# 		File lists 		(SRCS = main.c utils.c)
# 		Reusable commands 	(RM = rm -rf)
#
#       there are three typs of variables
#       1. Simple Variables (=)
#       2. Immediate Variables (:=)
#       3. Append Variables (+=)
#       4. Automatic Variables
#       5. Environment Variables
#.....................................................................................
#       With Example 
#	1. Simple Variables (=)
#	Evaluated when used, meaning changes affect later references.
#
# 		CC = gcc
# 		CFLAGS = -Wall -O2
# 		SRC = main.c utils.c
# 		OBJ = main.o utils.o
#
# 		hello: $(OBJ)
#    			 $(CC) $(CFLAGS) -o hello $(OBJ)
#		If CFLAGS is modified later, previous references will see the new value.
#........................................................................................
#	2. Immediate Variables (:=)
#       Evaluated when defined, meaning later changes won't affect earlier uses.
#       $(shell date +%Y-%m-%d) executes once at definition, storing the value
#
# 		VERSION := 1.0
# 		DATE := $(shell date +%Y-%m-%d)
#
# 		info:
# 		    @echo "Version: $(VERSION)"
# 		    @echo "Build Date: $(DATE)"
#.........................................................................................
#	3. Append Variables (+=)
#	Adds values to an existing variable.
#		CFLAGS = -Wall
#		CFLAGS += -O2 -g
#
#		hello: main.c
#			gcc $(CFLAGS) -o hello main.c
#	This expands CFLAGS to -Wall -O2 -g.
#..........................................................................................
#	4. Automatic Variables
#       Used inside rules to reference targets and dependencies:
#
#	hello: main.o utils.o
#    		gcc -o $@ $^  # $@ = hello, $^ = main.o utils.o
#	%.o: %.c
#   		gcc -c $< -o $@  # $< = source file, $@ = target object file
#
#          where,
#		$@ → Target name.
#		$^ → All dependencies.
#		$< → First dependency.
#          whre 
#        	target: first_dependency second_dependency
#		command using $@
#...........................................................................................
#	5. Environment Variables
#	Passed from the shell, overriding default values.
#
#	export CC=clang
#	make
#	Or inside a Makefile:
#
#	CC ?= gcc  # Uses 'gcc' if CC is not set externally.
#
#	hello: main.c
#	    $(CC) -o hello main.c
#	?= only sets CC if not already defined externally.
#............................................................................................



