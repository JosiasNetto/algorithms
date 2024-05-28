#include <stdio.h>
#include <stdlib.h>


typedef struct list{
  int maxSize; //Capacity if the list
  int listSize; //Number of current elements
  int curr; //Position of the cursor
  int* listArray
}List;

List* create_list(int size){
  List* l = (int*) malloc(sizeof(List));
  l->maxSize = size;
  l->listSize = l->curr = 0;
  l->listArray = (int*) malloc(size * sizeof(int));

  return l;
}