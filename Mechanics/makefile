all: sgf_player board.o sgfparser.o

board.o: board.c
	gcc -c board.c

sgfparser.o: sgfparser.c
	gcc -c sgfparser.c
	
sgf_player.o: sgf_player.c
	gcc -c sgf_player.c

sgf_player: sgf_player.o sgfparser.o board.o
	gcc -o sgf_player sgf_player.o sgfparser.o board.o

remove:
	rm sgf_player.o sgf_player board.o sgfparser.o
 
