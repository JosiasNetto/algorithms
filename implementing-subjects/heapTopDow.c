#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
  int *array;
  int size;
}Heap;

Heap* create_heap(){
  Heap* newHeap = (Heap*) malloc(sizeof(Heap));
  
  newHeap->array = (int*) malloc(sizeof(int) * 10000);
  newHeap->size = 0;
}

void heapify(Heap* hp){
  for(int i = hp->size; i > 1; i = i / 2){
    if(hp->array[i] > hp->array[i / 2]){
      int temp = hp->array[i];
      hp->array[i] = hp->array[i / 2];
      hp->array[i /2] = temp; 
    }
 }
}

void heapify_down(Heap* hp, int index){
  int largest = index;
  int leftChild = (2 * index);
  int rightChild = (2 * index) + 1;

  if(leftChild < hp->size && hp->array[largest] < hp->array[leftChild]){
    largest = leftChild;
  }
  if(rightChild < hp->size && hp->array[largest] < hp->array[rightChild]){
    largest = rightChild;
  }
  if(largest != index){
    int temp = hp->array[largest];
    hp->array[largest] = hp->array[index];
    hp->array[index] = temp;

    heapify_down(hp, largest);
  }
}

void insert_heap(Heap* hp, int k){
  hp->size++;
  hp->array[hp->size] = k;
  heapify(hp);
}

int delete_heap_element(Heap* hp, int k){
  if(hp->size == 0){
    return -1;
  }
  else if(hp->size == 1){
    hp->size--;
    return hp->array[1];
  }
  int del = hp->array[1];
  hp->array[1] = hp->array[hp->size];
  hp->size--;
  heapify_down(hp, 1);
}

void print_heap(Heap* hp){
  for(int i = 1; i <= hp->size ; i++)
    printf("%d\n", hp->array[i]);
}

int main(){

  Heap* heap = create_heap();

  for(int i = 0; i < 11; i++){
    insert_heap(heap, i);   
  }

  print_heap(heap);

  return 0;
}