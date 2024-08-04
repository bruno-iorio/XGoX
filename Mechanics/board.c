#include "board.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(){
  board* Board = create_board();
  print_board(Board);
  return 0;
}

board* create_board(void){
  board* Board = (board*) malloc(sizeof(board*));
  Board->grid = (int**) malloc(BOARDSIZE*sizeof(int*));

  for(int i = 0; i < BOARDSIZE; i++){
    Board->grid[i] = (int *) malloc(BOARDSIZE*sizeof(int));
  }
  
  for(int i = 0; i <  BOARDSIZE; i++){
    for(int j = 0; j <  BOARDSIZE; j++){
      if (i == 0 || i == BOARDSIZE - 1 || j == 0 || j == BOARDSIZE-1){
        Board->grid[i][j] = 3;
      } else {
        Board->grid[i][j] = 0;
      }
    }
  }
  return Board;
}

void print_board(board* Board){
  for(int i = 0; i < BOARDSIZE; ++i){
    for(int j = 0; j < BOARDSIZE; ++j){
      printf("%d ",Board->grid[i][j]);
    }
    printf("\n");
  }
}

int play_move(board* Board,int color, int x, int y){
  if(x <= 0 || x >= BOARDSIZE-1 || y <= 0 || y >= BOARDSIZE-1){
    return -1; //error
  }
  Board->grid[x][y] = color;
  return 0;
}
