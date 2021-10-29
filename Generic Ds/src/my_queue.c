#ifndef __MY_QUEUE__C
#define __My_QUEUE__C 123
#include<my_queue.h>
#include<stdio.h>
#include<stdlib.h>
#include<my_common.h>
Queue * createQueue(bool *success)
{
SinglyLinkedList *singlyLinkedList;
Queue *queue;
if(success)*success=false;
singlyLinkedList=createSinglyLinkedList(success);
if(success==false)return NULL;
queue=(Queue *)malloc(sizeof(Queue));
if(queue==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success)*success=false;
return NULL;
}
queue->singlyLinkedList=singlyLinkedList;
if(success)*success=true;
return queue;
}
void addToQueue(Queue *queue,void *ptr,bool *success)
{
if(success)*success=false;
if(queue==NULL)return;
if(queue==NULL || queue->singlyLinkedList==NULL)return;
addToSinglyLinkedList(queue->singlyLinkedList,ptr,success);
}
void * removeFromQueue(Queue *queue,bool *success)
{
void *ptr;
if(success)*success=false;
if(getSizeOfQueue(queue)==0)return NULL;
if(queue==NULL || queue->singlyLinkedList==NULL)return NULL;
ptr=(void *)removeFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success)*success=true;
return ptr;
}
int getSizeOfQueue(Queue *queue)
{
if(queue==NULL || queue->singlyLinkedList==NULL)return 0;
return getSizeOfSinglyLinkedList(queue->singlyLinkedList);
}
void * elementAtFrontOfQueue(Queue *queue,bool *success)
{
void *ptr;
if(success)*success=false;
if(queue==NULL || queue->singlyLinkedList==NULL)return NULL;
ptr=(void *)getFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success)*success=true;
return ptr;
}
bool isQueueEmpty(Queue *queue)
{
if(queue==NULL || queue->singlyLinkedList==NULL)return true;
if(queue->singlyLinkedList->size==0)return true;
return false;
}
void destroyQueue(Queue *queue)
{
if(queue==NULL || queue->singlyLinkedList==NULL)return;
clearSinglyLinkedList(queue->singlyLinkedList);
free(queue);
}
void clearQueue(Queue *queue)
{
if(queue==NULL || queue->singlyLinkedList==NULL)return;
clearSinglyLinkedList(queue->singlyLinkedList);
}
#endif