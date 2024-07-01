#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
  int* array;
  int size;
}Heap;

Heap* create_heap(){
  Heap* newHeap = (Heap*) malloc(sizeof(Heap));

  newHeap->array = (int*) malloc(sizeof(int) * 5000);
  newHeap->size = 0;

  return newHeap;
}

void heapify(Heap* hp){
  for(int i = hp->size; i > 1; i = i / 2){
    if(hp->array[i] < hp->array[i/2]){
      int temp = hp->array[i];
      hp->array[i] = hp->array[i/2];
      hp->array[i/2] = temp;
    }
  }
}

void heapify_down(Heap* hp, int index){
  int largest = index;

  int left_child = (2 * index); 
  int right_child = (2 * index) + 1;

  if(left_child <= hp->size && hp->array[left_child] < hp->array[largest]){
    largest = left_child;
  } 
  if(right_child <= hp->size && hp->array[right_child] < hp->array[largest]){
    largest = right_child;
  }
  if(largest != index){
    int temp = hp->array[index];
    hp->array[index] = hp->array[largest];
    hp->array[largest] = temp;

    heapify_down(hp, largest);
  }

}

void insert_heap(Heap* hp, int k){
  hp->size++;
  hp->array[hp->size] = k;
  heapify(hp);
}

int delete_root_heap(Heap* hp){
  if(hp->size == 0){
    return 0;
  }
  if(hp->size == 1){
    hp->size--;
    return hp->array[1];
  }

  int temp = hp->array[1];
  hp->array[1] = hp->array[hp->size];
  hp->array[hp->size] = temp;
  hp->size--;
  heapify_down(hp, 1);

  return hp->array[hp->size + 1];
}

int sum_heap(Heap* hp){
  int sum_geral, sum_normal, firstMin, secMin;
  sum_geral = 0;

  while(hp->size > 1){
    firstMin = delete_root_heap(hp);
    secMin = delete_root_heap(hp);

    sum_normal = firstMin + secMin;

    sum_geral += sum_normal;

    insert_heap(hp, sum_normal);
  }
    
  return sum_geral;
}


int main(){

  Heap* hp = create_heap();

  int n;
  scanf("%d", &n);

  while(n){
    hp = create_heap();

    for(int i = 0; i < n; i++){
      int x;
      scanf("%d", &x);
      insert_heap(hp, x);
    }
    int sum = sum_heap(hp);
    printf("%d\n", sum);

    scanf("%d", &n);
  }

  return 0;
}