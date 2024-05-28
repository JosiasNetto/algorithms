#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct noodle Noodle;
typedef struct list List;

Noodle* create_noodle(char, Noodle*);
Noodle* create_noodle_first(Noodle*);
List* create_list();
void insert(List*, char);
void next(List*);
void print_list(List*);
void move_start(List*);
void move_final(List*);


int main(){

  char txt[1000000];

  while(scanf("%s",txt) != EOF){
    int i = 0;

    List* listtxt = create_list();
    
    while(txt[i] != '\0'){
      if(txt[i] != '['&& txt[i] != ']'){
        insert(listtxt, txt[i]);
        next(listtxt);
      }
      else if(txt[i] == '['){
        move_start(listtxt);
      }
      else{  
        move_final(listtxt);
      }
      i++;
  }
    print_list(listtxt);
    printf("\n");
 }
  return 0;
}

struct noodle{
 char letter;
 Noodle* next;
};

Noodle* create_noodle(char lt, Noodle* next){
  Noodle* newNoodle = (Noodle*) malloc(sizeof(Noodle));
  newNoodle->letter = lt;
  newNoodle->next = next;

  return newNoodle;
}

Noodle* create_noodle_first(Noodle* next){
  Noodle* newNoodleHeader = (Noodle*) malloc(sizeof(Noodle));
  newNoodleHeader->next = next;

  return newNoodleHeader;
}

struct list{
  Noodle* header;
  Noodle* tail;
  Noodle* curr;
  int count;
};

List* create_list(){
  List* l = (List*) malloc(sizeof(List));
  l->curr = l->tail = l->header = create_noodle_first(NULL);
  l->count = 0;

  return l;
}

void insert(List* l, char letter){
  l->curr->next = create_noodle(letter, l->curr->next);

  if (l->tail == l->curr){
    l->tail = l->curr->next;
  }
  l->count++;
}

void next(List* l){
  l->curr = l->curr->next;
}

void print_list(List* l){
  Noodle* temp = l->header->next;

  while(temp != NULL){
    printf("%c", temp->letter);
    temp = temp->next;
  }
}

void move_start(List* l){
  l->curr = l->header;
}

void move_final(List* l){
  l->curr = l->tail;
}