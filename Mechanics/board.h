#ifndef BOARD_H
#define BOARD_H
#define BOARDSIZE 21
enum Color{
  Empty = 0,
  Black = 1,
  White = 2,
  Wall = 3, 
};

typedef struct board{
  int** grid;
  int turn; //1 if black, 2 if white
} board;

int play_move(board*, int,int,int);
void print_board(board*);
board* create_board();
#endif // BOARD_H
