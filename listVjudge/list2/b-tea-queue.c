#include <stdio.h>
#include <stdlib.h>

typedef struct noodle{
  int element;
  struct noodle* next;
}Noodle;

typedef struct queue{
  Noodle* front;
  Noodle* rear;
  int size;
}Queue;

Noodle* create_noodle(int, Noodle*);
Noodle* create_first_noodle(Noodle*);
Queue* create_queue();
void enqueue(Queue*, int);
int dequeue(Queue*);


int main(){

  int testCases;

  scanf("%d", &testCases);

  for (int i = 0; i < testCases; i++){
    int students;
    scanf("%d", &students);

    Queue* queueTimeArrive = create_queue();
    Queue* queueTimeMax = create_queue();

    int timeArrive;
    int timeMax;
    int time = 1;

    for(int j = 0; j < students; j++){ 
      scanf("%d", &timeArrive);
      enqueue(queueTimeArrive,timeArrive );
      scanf("%d", &timeMax);
      enqueue(queueTimeMax, timeMax);
      if ((queueTimeMax->front->next->element - queueTimeArrive->front->next->element) >= (time - queueTimeArrive->front->next->element)){
        if(queueTimeArrive->front->next->element > time){
          time = queueTimeArrive->front->next->element;
        }
        printf("%d ", time);
        time++;
      }
      else{
        printf("0 ");
      }
      dequeue(queueTimeArrive);
      dequeue(queueTimeMax);
    }
    printf("\n");
  }

  return 0;
}

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