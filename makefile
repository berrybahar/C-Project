assembler: assembler.o file_handling.o pre_assembler.o linked_list.o
	       gcc -ansi -Wall -pedantic -g assembler.o file_handling.o pre_assembler.o linked_list.o -o assembler -lm

assembler.o: assembler.c assembler.h
			 gcc -c -ansi -Wall -pedantic assembler.c -o assembler.o

file_handling.o: file_handling.c file_handling.h
			 	 gcc -c -ansi -Wall -pedantic file_handling.c -o file_handling.o

pre_assembler.o: pre_assembler.c pre_assembler.h
				 gcc -c -ansi -Wall -pedantic pre_assembler.c -o pre_assembler.o

linked_list.o: linked_list.c linked_list.h
			   gcc -c -ansi -Wall -pedantic linked_list.c -o linked_list.o