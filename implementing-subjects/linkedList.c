#include <stdio.h>
#include <stdlib.h>

typedef struct link Link;
typedef struct list List;

struct link{
  int element;
  Link * next;
};

Link* create_link(int it, Link* nextval){
  Link* newLink = (Link*) malloc(sizeof(Link)); 
  newLink->element = it;
  newLink->next = nextval;

  return newLink;
}

Link* create_link_header(Link* nextval){
  Link* newLinkHeader = (Link*) malloc(sizeof(Link));
  newLinkHeader->next = nextval;

  return newLinkHeader;
}

struct list{
  Link* head;
  Link* tail;
  Link* curr;
  int cnt;
};

List* create_list(){
  List* l = (List*) malloc(sizeof(List));
  l->curr = l->tail = l->head = create_link_header(NULL);
  l->cnt = 0;

  return l;
};

void insert(List* l, int it){
  l->curr->next = create_link(it, l->curr->next);
  if(l->tail == l->curr){
    l->tail = l->curr->next;
  }
  l->cnt++;
}

void move_to_start(List* l){
  l->curr = l->head;
}

void prev(List* l){
  if (l->curr == l->head){
    return;
  }
  Link* temp = l->head;
  while (temp->next != l->curr){
    temp = temp->next;
  }
  l->curr = temp;
}

void next(List* l){
  if (l->curr != l->tail){
    l->curr = l->curr->next;
  }
}

int remove_item(List* l){
  if (l->curr->next == NULL){
    return -1;
  }
  int it = l->curr->next->element;
  if (l->tail == l->curr->next){
    l->tail = l->curr;
  }
  l->curr->next = l->curr->next->next;
  l->cnt--;
  return it;
}

int main(){
  List* l = create_list();

  for(int i = 0; i < 10; i++){
    insert(l, i);
  }
  Link* temp = l->head->next;

  while (temp != NULL){
    printf("%d ", temp->element);
    temp = temp->next;
  } 
}