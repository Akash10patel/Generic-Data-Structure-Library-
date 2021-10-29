#ifndef __MY_HEAP__H
#define __MY_HEAP__H 123
#include"my_common.h"
#include"my_array.h"
typedef struct __$__my_heap
{
Array *array;
int (*comparator)(void *,void *);
int size;
}Heap;

Heap * createHeap(int (*comparator)(void *,void *),bool *success);
void addToHeap(Heap *heap,void *elem,bool *success);
void * removeFromHeap(Heap *heap,bool *success);
void * elementAtTopOfHeap(Heap *heap,bool *success);
int getSizeOfHeap(Heap *heap);
void destroyHeap(Heap *heap);
#endif
