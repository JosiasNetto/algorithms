#include <stdio.h>
#include <stdlib.h>

typedef struct noodle Noodle;
typedef struct queue Queue;

Noodle* create_noodle(int, Noodle*);
Noodle* create_first_noodle(Noodle*);
Queue* create_queue();
void enqueue(Queue*, int);
int dequeue(Queue*);


int main(){

  int testCases, i;

  scanf("%d", testCases);

  for (i = 0; i < testCases; i++){
    int students;
    scanf("%d", students);
    
  }

  return 0;
}

struct noodle{
  int element;
  Noodle* next;
};

 Noodle* create_noodle(int it, Noodle* nextval){
  Noodle* newNoodle = (Noodle*) malloc(sizeof(Noodle));
  newNoodle->element = it;
  newNoodle->next = nextval;

  return newNoodle;
 }
 Noodle* create_first_noodle(Noodle* nextval){
  Noodle* newNoodle = (Noodle*) malloc(sizeof(Noodle));
  newNoodle->next = nextval;

  return newNoodle;
 }

struct queue{
  Noodle* front;
  Noodle* rear;
  int size;
};

Queue* create_queue(){
  Queue* newQueue = (Queue*) malloc(sizeof(Queue));
  newQueue->front = newQueue->rear = create_first_noodle(NULL);
  newQueue->size = 0;

  return newQueue;
}

void enqueue(Queue* q, int it){
  q->rear->next = create_noodle(it, NULL);
  q->rear = q->rear->next;
  q->size++;
}

int dequeue(Queue* q){
  if (q->size == 0){
    return -1;
  }
  int it = q->front->next->element;
  q->front->next = q->front->next->next;

  if (q->front->next == NULL){
    q->rear = q->front;
  }
  q->size--;

  return it;
}