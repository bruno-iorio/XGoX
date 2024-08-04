#include "board.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(){

  board* Board = create_board();
  if(Board == NULL){
    return 1;
  }
  /* Debugging session
  play_move(Board,BLACK, 2, 3);
  play_move(Board,BLACK, 3, 3);
  play_move(Board,WHITE, 4, 3);
  play_move(Board,WHITE, 1, 3);
  play_move(Board,WHITE, 3, 2);
  play_move(Board,WHITE, 3, 4);
  play_move(Board,WHITE, 2, 4);
  play_move(Board,WHITE, 2, 2);
  print_board(Board);
  int* x = (int*) malloc(sizeof(int)*361);
  int* y = (int*) malloc(sizeof(int)*361);
  printf("%d\n",find_group_liberties(Board,x,y,2,3,0));
  free(x);
  free(y);
  */
  for(int i = 0; i < BOARDSIZE; i++){
    free(Board->grid[i]);
  }
  free(Board->grid);
  free(Board);
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
        Board->grid[i][j] = WALL;
      } else {
        Board->grid[i][j] = EMPTY;
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

int find_group_liberties(board* Board,int* x, int* y,int x1,int y1, int n){
  if(x1 <= 0 || x1 >= BOARDSIZE-1 || y1 <= 0 || y1 >= BOARDSIZE-1){
   return -1; //error 
  }
  int color = Board->grid[x1][y1];
  int color1,color2,color3,color4;
  color1 = Board->grid[x1+1][y1];
  color2 = Board->grid[x1-1][y1];
  color3 = Board->grid[x1][y1+1];
  color4 = Board->grid[x1][y1-1];

  *(x + n) = x1;
  *(y + n) = y1;
  printf("here it goes: %d , %d, %d\n",*(x+n),*(y+n),n);
  if(color1 == EMPTY || color2 == EMPTY || color3 == EMPTY || color4 == EMPTY){return 0;}
  
  if(color1 == color){
    int found = 0;
    for(int i = 0; i < n; i++){
      if(x1 + 1 == *(x + i) && y1 == *(y + i)){found = 1; break;}
    }
    if(!found){
      if(find_group_liberties(Board,x,y,x1+1,y1,++n) == 0){return 0;}
    }
  }
  if(color2 == color){
    int found = 0;
    for(int i = 0; i < n; i++){
      if(x1 - 1 == *(x + i) && y1 == *(y + i)){found = 1; break;}
    } 
    if(!found){
      if(find_group_liberties(Board,x,y,x1-1,y1,++n) == 0){ return 0;};
    }
  }
  if(color3 == color){
    int found = 0;
    for(int i = 0; i < n; i++){
      if(x1 == *(x + i) && y1 + 1 == *(y + i)){found = 1;break;}
    } 
    if(!found){
      if(find_group_liberties(Board,x,y,x1,y1+1,++n)==0){return 0;}
    }
  }
  if(color4 == color){
    int found = 0;
    for(int i = 0; i < n; i++){
      if(x1 == *(x + i) && y1 - 1 == *(y + i)){found = 1; break;}
    } 
    if(!found){
      if(find_group_liberties(Board,x,y,x1,y1-1,++n)==0){return 0;}
    }
  }
  return 1; //dead
}




