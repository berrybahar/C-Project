assembler: assembler.o pre_assembler.o functions.o
	       gcc -ansi -Wall -pedantic -g assembler.o pre_assembler.o functions.o -o assembler -lm

assembler.o: assembler.c assembler.h
			 gcc -c -ansi -Wall -pedantic assembler.c -o assembler.o

pre_assembler.o: pre_assembler.c pre_assembler.h
				 gcc -c -ansi -Wall -pedantic pre_assembler.c -o pre_assembler.o

functions.o: functions.c 
		     gcc -c -ansi -Wall -pedantic functions.c -o functions.o
