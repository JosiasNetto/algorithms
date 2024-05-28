#include <stdio.h>
#include <stdlib.h> //Including the malloc function

typedef struct link Link; //Predeclarating the Link(Noodle) struct
typedef struct list List; //Predeclarating the List struct

struct link{  //Defining the Link struct
  int element;  //The value that the Noodle stores
  Link * next;  //The pointer to the next noodle
};

//Func  that create a noodle 
Link* create_link(int it, Link* nextval){ //Arguments: The item that he stores, and the pointer to the next noodle 
  Link* newLink = (Link*) malloc(sizeof(Link)); //Malloc a memory space in the heap for the noodle 
  newLink->element = it;  //Element gonna be the it argument
  newLink->next = nextval;  //Next gonna be the pointer passed by the argument

  return newLink; //Return the pointer of the noodle
}

//Func to create the list the first time
Link* create_link_header(Link* nextval){  //Receive just the arg of the pointer
  Link* newLinkHeader = (Link*) malloc(sizeof(Link)); //Malloco a memory space for the header
  newLinkHeader->next = nextval;  //Point the next to the argument

  return newLinkHeader; //Return the pointer to the noodle
}

struct list{  //Defining the List struct
  Link* head; //The header pointer
  Link* tail; //The tail pointer
  Link* curr; //The cursor pointer
  int cnt;  //Int for the count of elements in the list
};

//Func that  creates the list
List* create_list(){
  List* l = (List*) malloc(sizeof(List)); //Malloc a memory space for the list in the heap
  l->curr = l->tail = l->head = create_link_header(NULL); //At the beggining, all the pointer point to a noodle, that points to NULL
  l->cnt = 0; //count of elements = 0 at the beggining

  return l; //Return the pointer of the list
};

//Func that insert a item in the list
void insert(List* l, int it){ //Arguments: The list  and the item that want to add
  l->curr->next = create_link(it, l->curr->next); //Create a new noodle after the cursor
  /*Point the next pointer of the cursor to the new noodle, and points the 'next' pointer of the new noodle
  to the previous noodle that the cursor was pointing */
  
  if(l->tail == l->curr){ //Check if the pointer of the tail points the smae as the cursor
    l->tail = l->curr->next;  //Points the tail to the next of the cursor
  }
  l->cnt++; //Increase the count of the elements
}

void move_to_start(List* l){  //Func that move the cursor to the start
  l->curr = l->head;  //Cursor point the smae as the head
}

void prev(List* l){ //Move the  cursor to the prev element
  if (l->curr == l->head){  //Check if the curso is not at the beggining of the list
    return;  //Does nothing
  }
  Link* temp = l->head; //Declare a temporary pointer, that starts in the head of the list
  while (temp->next != l->curr){  //Iterates the list, until the 'next' pointer of the temp is equal to the cursor
    temp = temp->next;  //Iterates the list
  }
  l->curr = temp; //Cursor point to where the temp are
}

void next(List* l){ //Func that move the cursor to the next position
  if (l->curr != l->tail){  //Check if the cursor is not at the of the list
    l->curr = l->curr->next;  //Cursor gonnga point to his next
  }
}

int remove_item(List* l){ //Func that remove a item from the list
  if (l->curr->next == NULL){ //Check if the item to remove is NULL
    return -1;
  }
  int it = l->curr->next->element;  //Decalre the item to delete
  if (l->tail == l->curr->next){  //Check if are deleting the last item
    l->tail = l->curr;  //The last item now is the cursor item
  }
  l->curr->next = l->curr->next->next;  //The 'next' pointer points to the item after the deleted item
  l->cnt--; //Decrease the count of elements
  return it;  //Returhn the removed element
}

int main(){
  //Testing the list
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