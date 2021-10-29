#ifndef __MY_QUEUE__H
#define __MY_QUEUE__H 123
#include"my_sll.h"
#include"my_common.h"
typedef struct __$__my_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;

Queue * createQueue(bool *success);
void addToQueue(Queue *queue,void *ptr,bool *success);
void * removeFromQueue(Queue *queue,bool *success);
int getSizeOfQueue(Queue *queue);
void * elementAtFrontOfQueue(Queue *queue,bool *success);
bool isQueueEmpty(Queue *queue);
void destroyQueue(Queue *queue);
void clearQueue(Queue *queue);
#endif
