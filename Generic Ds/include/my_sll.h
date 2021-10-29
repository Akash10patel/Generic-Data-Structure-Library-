#ifndef __MY_SLL__H
#define __MY_SLL__H
#include"my_common.h"
typedef struct __$__my_sll_node
{
void *ptr;
struct __$__my_sll_node *next;
}SinglyLinkedListNode;

typedef struct __$__my_sll
{
struct __$__my_sll_node *start;
struct __$__my_sll_node *end;
int size;
}SinglyLinkedList;

typedef struct __$__my_iterator
{
SinglyLinkedListNode *node;
}SinglyLinkedListIterator;

SinglyLinkedList * createSinglyLinkedList(bool *success);
void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success);
void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success);
void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void * getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,bool *success);
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlylinkedList,bool *success);
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator);
void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success);
#endif