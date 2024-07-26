#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<errnor.h>

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
	
	game->groups = (group*) malloc(sizeof(group))

	return game;
}
void update_groups_size(game* game,int inc){
	group_new = (group*) realloc(game->groups,sizeof(group)*(inc + number_groups))
        game->groups = group_new;
}

int add_stone(game* game, int color, int x, int y){
	if(color != WHITE && color != BLACK){
		perror("Invalid Color! Please, choose white or black");
		return -1;
	}
	if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE){
		perror("Invalid coordinates! Please, valid coordinates");
		return -1;
	}
	game->board[x][y] = color;	
	return 0;
}

int remove_stone(*game, int x, int y){
	if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE){
		perror("Invalid coordinates! Please, valid coordinates");
		return -1;
	}
	game->board[x][y] = EMPTY;
	return 0;
}

int check_capture(group* group);
	if(group == NULL){
		perror("Group has null value");
		return -1
	}
	if (group->liberties==0){ //captured
		return 1;
	}
	return 0; //not captured

