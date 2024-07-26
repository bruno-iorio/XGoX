all: board sgfparser

board: board.o
	gcc -o board board.o

board.o: board.c
	gcc -c board.c

sgfparser: sgfparser.o
	gcc -o sgfparser sgfparser.o

sgfparser.o: sgfparser.c
	gcc -c sgfparser.c
	
remove: 
	rm sgfparser sgfparser.o board.o board

