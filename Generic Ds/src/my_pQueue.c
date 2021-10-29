#ifndef __MY_PQUEUE__C
#define __My_PQUEUE__C 123
#include<my_pQueue.h>
#include<stdio.h>
#include<stdlib.h>
#include<my_common.h>
PQueue * createPQueue(int (*myComparator)(void *,void *),bool *success)
{
Heap *heap;
PQueue *pQueue;
if(success)*success=false;
heap=createHeap(myComparator,success);
if(success==false)return NULL;
pQueue=(PQueue *)malloc(sizeof(PQueue));
if(pQueue==NULL)
{
destroyHeap(heap);
if(success)*success=false;
return NULL;
}
pQueue->heap=heap;
if(success)*success=true;
return pQueue;
}
void addToPQueue(PQueue *pQueue,void *ptr,bool *success)
{
if(success)*success=false;
if(pQueue==NULL)return;
if(pQueue==NULL || pQueue->heap==NULL)return;
addToHeap(pQueue->heap,ptr,success);
}
void * removeFromPQueue(PQueue *pQueue,bool *success)
{
void *ptr;
if(success)*success=false;
if(pQueue==NULL || pQueue->heap==NULL)return NULL;
ptr=(void *)removeFromHeap(pQueue->heap,success);
if(success)*success=true;
return ptr;
}
int getSizeOfPQueue(PQueue *pQueue)
{
if(pQueue==NULL || pQueue->heap==NULL)return 0;
return getSizeOfHeap(pQueue->heap);
}
void * elementAtFrontOfPQueue(PQueue *pQueue,bool *success)
{
void *ptr;
if(success)*success=false;
if(pQueue==NULL || pQueue->heap==NULL)return NULL;
ptr=(void *)elementAtTopOfHeap(pQueue->heap,success);
if(success)*success=true;
return ptr;
}
bool isPQueueEmpty(PQueue *pQueue)
{
if(pQueue==NULL || pQueue->heap==NULL)return true;
if(getSizeOfHeap(pQueue->heap)==0)return true;
return false;
}
void destroyPQueue(PQueue *pQueue)
{
if(pQueue==NULL || pQueue->heap==NULL)return;
destroyHeap(pQueue->heap);
free(pQueue);
}
void clearPQueue(PQueue *pQueue)
{
int succ;
if(pQueue==NULL || pQueue->heap==NULL)return;
while(getSizeOfHeap(pQueue->heap)>0)
{
removeFromHeap(pQueue->heap,&succ);
}
}
#endif