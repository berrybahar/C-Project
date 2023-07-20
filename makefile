assembler: assembler.o file_handling.o
	       gcc -ansi -Wall -pedantic -g assembler.o file_handling.o -o assembler -lm

assembler.o: assembler.c assembler.h
			 gcc -c -ansi -Wall -pedantic assembler.c -o assembler.o

file_handling.o: file_handling.c file_handling.h
			 gcc -c -ansi -Wall -pedantic file_handling.c -o file_handling.o