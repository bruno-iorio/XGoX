#ifndef BOARD_H
#define BOARD_H
#define BOARDSIZE 21
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define WALL 3



typedef struct board{
  int** grid;
  int turn; //1 if black, 2 if white
} board;

int play_move(board*, int,int,int);
int play_match(board*);
void print_board(board*);
board* create_board();
int find_group_liberties(board*,int*,int*,int,int,int);
#endif // BOARD_H
