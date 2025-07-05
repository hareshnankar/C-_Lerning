# 1. What .PHONY Means in Makefiles

# .PHONY is a special target in Makefiles that tells make not to treat 
# it as a real file.It’s used for commands like clean, install, or all 
# that don’t produce actual files.

# Why is .PHONY useful?
# Sometimes, a Makefile has commands like clean or install, 
# but these names could also be real files. If make sees a file named clean, 
# it might think nothing needs to be done, and skip the command.

#Example Without .PHONY (Problem)
make
clean:
    rm -rf *.o hello

#If a file called clean exists, make clean won't run because 
#it assumes the "target" is up-to-date.

#Example With .PHONY (Fix)
make
.PHONY: clean
clean:
    rm -rf *.o hello

# Now, make clean always runs because clean is treated as a command, 
# not a file.

# Where to Use .PHONY
# ✔ clean → Remove temporary files 
# ✔ test → Run tests 
# ✔ install → Install the program 
# ✔ all → Build everything