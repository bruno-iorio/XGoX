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

group* groups;
int number_groups;
} game;

typedef struct stone{
int x_pos;
int y_pos;

} stone;

group* find_group(int,int);
game* create_game(int,int);
void update_turn(game*);
void update_groups_size(game*,int);
int add_stone(game*,int,int,int); // doesnt matter the turn!
int remove_stone(game*,int,int);
int check_capture(group*);


#endif //BOARD_H







