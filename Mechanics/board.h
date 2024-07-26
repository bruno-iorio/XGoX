#ifndef BOARD_H
#define BOARD_H
#define BLACK 1
#define WHITE 2
#define EMPTY 0
#define BOARD_SIZE 19

typedef struct group{
int color;
int liberties;  // Important for capture race
int eyes_count; // >= 2 eyes is confirmed alive!
		
		// To define a group, we just need 1 stone of this group:
int x_pos;      
int y_pos;
} group

typedef struct game{
int** board;   // This will be the board
int handicap;  // How many extra-stones to be played with
int komi;      // How much komi for white
int turn;      // whose turn is it in this game
group* groups
} game;



typedef struct stone{
int x_pos;
int y_pos;

} stone;

group* find_group(int,int);
game* create_game(int handicap,int komi);
void update_turn(game*);



#endif //BOARD_H







