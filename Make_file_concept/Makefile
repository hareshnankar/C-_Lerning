hello:	main.o	utils.o
	gcc	-o	hello	main.o	utils.o  # Only links object files

# Compile .c files into .o files
%.o:	%.c
		gcc	-c	$<	-o	$@
