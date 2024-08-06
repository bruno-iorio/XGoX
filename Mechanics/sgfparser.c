#include "sgfparser.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>



int sgf_parser(char* filename,int** x_vec, int** y_vec, int* n){
  
  FILE *fd = fopen(filename,"r");
  if(fd == NULL){
      fprintf(stderr, "invalid filename\n");
      return 1;
  }
  int parent_count=0;
  char c;
  int x;
  int y;
  int max_size = 100;
  
  printf("starting loop: \n");
   while((c = fgetc(fd))!=EOF){
  if(*n==max_size){
      max_size = 2*max_size;
    *x_vec = (int*) realloc(*x_vec,sizeof(int)*max_size);
    *y_vec = (int*) realloc(*y_vec,sizeof(int)*max_size);
  }
    if(c=='(' ){
      parent_count++;
    }
    else if(c=='('){
      parent_count--;
    }
    if (parent_count==1) {
      if(c==';'){
        continue;
      }
      if(c=='A' || c == 'P'){
        fgetc(fd);
        fgetc(fd);
        continue;
      }
      if(c=='B' || c=='W'){
        c = fgetc(fd);
        if(c!=' ' && c!='['){ continue;}
        while(c!='['){
          c = fgetc(fd);
        }
        int xset = 0;
        while(c!=']'){
          c = fgetc(fd);
          if(c==' '){
            continue;
          }
          if(xset == 0){
            x = (int) c;
            (*x_vec)[*n] = x - 96;
            xset = 1;
          } else{
            if(c!=']') {
              y = (int) c;
              (*y_vec)[*n] = y - 96;
              (*n)++;
              printf("%d",*n);
            }
          }
        }
      }
    }
  }
  printf("n is %d\n",*n);
  if(fclose(fd)!=0){
    fprintf(stderr,"error closing the file");
    return 1;
  }
  return 0;
}
