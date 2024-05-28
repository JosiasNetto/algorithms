#ifndef _LIST_H
#define _LIST_H

typedef struct list List;

List* createList(int size);

void clear(List* l);

void insert(List* l, int item);


#endif