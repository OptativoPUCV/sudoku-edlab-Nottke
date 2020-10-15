#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int value;
  for (int j = 0; j < 9; j++){
    for (int i = 0; i < 9; i++){
      value = n->sudo[i][j];
      if (n->sudo[i][j] != 0){
        for (int x = 0; x < 9; x++){
          if((x != i) && (n->sudo[x][j] == value)){
            return 0;
          }
        }
        for (int y = 0; y < 9; y++){
          if ((y != j) && (n->sudo[i][y] == value)){
            return 0;
          }
        }
        int k;
        k = (i/3)*3 + j/3;
        for ( int z = 0; z < 9; z++){
          int x = 3*(k / 3) + (z / 3);
          int y = 3*(k % 3) + (z % 3);
          //printf("%d", n->sudo[x][y]);
          if (z % 3 == 2){
            printf("\n");
          }
          if (n->sudo[x][y] == value){
            if (( x != i) || (y != j)){
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i;
    int j;
    int num;
    for (i = 0; i < 9; i++){
      for (j = 0; j < 9; j++){
        if ( n->sudo[i][j] == 0){
          for ( num = 1; num <= 10; num++){
            n->sudo[i][j] = num;
            if (is_valid (n) ){
              Node *newnode = copy(n);
              pushBack(list, newnode);
            }
          }
          n->sudo[i][j] = 0;
          return list;
        }
      }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/