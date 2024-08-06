#include "board.h"
#include "sgfparser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
if (argc != 2){
    fprintf(stderr, "wrong number of inputs");
}
  int n = 0;
  int* x;
  int* y;
  x = (int *) malloc(sizeof(int)*100);
  y = (int *) malloc(sizeof(int)*100);
  sgf_parser(argv[1],&x,&y,&n);
  printf("n in the main program is: %d",n);
  board* Board = create_board();
  int color = BLACK;
  print_board(Board);
  printf("\n");
  for(int i = 0; i < n; i++){
    play_move(Board, color, x[i],y[i]);

    switch (color){
      case BLACK:
        color = WHITE;
        break;
      case WHITE:
        color = BLACK;
        break;
      default:
        break;
    }
    print_board(Board);

  printf("\n");
  }
  free(x);
  free(y);

return 0;
}
