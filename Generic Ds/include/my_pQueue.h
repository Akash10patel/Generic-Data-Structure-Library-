#ifndef __MY_PQUEUE__H
#define __MY_PQUEUE__H 123
#include"my_heap.h"
#include"my_common.h"
typedef struct __$__my_pQueue
{
Heap *heap;
}PQueue;

PQueue * createPQueue(int (*myComparator)(void *,void *),bool *success);
void addToPQueue(PQueue *pQueue,void *ptr,bool *success);
void * removeFromPQueue(PQueue *pQueue,bool *success);
int getSizeOfPQueue(PQueue *pQueue);
void * elementAtFrontOfPQueue(PQueue *pQueue,bool *success);
bool isPQueueEmpty(PQueue *pQueue);
void destroyPQueue(PQueue *pQueue);
void clearPQueue(PQueue *pQueue);
#endif
