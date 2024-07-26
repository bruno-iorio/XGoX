#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<board.h>

void update_turn(game* game){
	if (game.turn==WHITE){
		game->turn = BLACK;
	} else{
		game->turn = WHITE;
	}

}
game* create_game(int handicap,int komi){
	int board_size = BOARD_SIZE;
	game* game = (game *) malloc(sizeof(game));
	game->turn = BLACK;
	game->komi = komi;
	game->handicap = handicap;

	game->board = (int **) malloc(BOARD_SIZE*sizeof(int*));
	for(int i = 0; i < BOARD_SIZE, i++ ){
		game->board[i] = (int *) malloc(BOARD_SIZE*sizeof(int));
		for(int j = 0; j < BOARD_SIZE, j++){
			game->board[i][j] = EMPTY;
		}
	}
	return game
}
