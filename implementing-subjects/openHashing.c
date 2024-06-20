#include <stdio.h>
#include <stdlib.h>

typedef struct link{
  int element;
  struct Link* next;
}Link;

typedef struct list{
  Link* header;
  Link* tail;
  Link* curr;
  int count;
}List;

typedef struct dict{
  int m;
  int cnt;
  struct List* arrayList[];

}Dict;
int main(){

}

Link* create_link(int it, Link* next){
  Link* newLink = (Link*) malloc(sizeof(Link));

  newLink->element = it;
  newLink->next = next; 

  return newLink;
}
Link* create_first_link(Link* next){
  Link* newLink = (Link*) malloc(sizeof(Link));

  newLink->next = next; 

  return newLink;
}
List* create_list(){
  List* newList = (List*) malloc(sizeof(List));

  newList->curr = newList->header = newList->tail = create_first_link(NULL);
  newList->count = 0;

  return newList;
}
