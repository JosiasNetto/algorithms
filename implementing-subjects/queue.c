#include <stdio.h>
#include <stdlib.h>


typedef struct noodle Noodle;

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

typedef struct queue{
  Noodle* front;
  Noodle* rear;
  int size;
}Queue;

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

  if( q->front->next == NULL){
    q->rear = q->front;
  }
  q->size--;

  return it;
}
 
 int main(){
  return 0;
 }