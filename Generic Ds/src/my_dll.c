#ifndef __MY_DLL__C
#define __MY_DLL__C
#include<stdlib.h>
#include<my_common.h>
#include<my_dll.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
DoublyLinkedList *doublyLinkedList;
if(success)*success=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL)return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success)*success=true;
return doublyLinkedList;
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
DoublyLinkedListNode *node;
if(success)*success=false;
if(doublyLinkedList==NULL)return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
node->previous=doublyLinkedList->end;
doublyLinkedList->end->next=node;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;
if(success)*success=true;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *node,*p1,*p2;
int x;
if(success)*success=false;
if(doublyLinkedList==NULL)return;
if(index<0 || index>doublyLinkedList->size)return;
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
if(success)*success=true;
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(index==0)
{
doublyLinkedList->start->previous=node;
node->next=doublyLinkedList->start;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success)*success=true;
return;
}
x=0;
p1=doublyLinkedList->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
p2->next=node;
node->next=p1;
p1->previous=node;
node->previous=p2;
doublyLinkedList->size++;
if(success)*success=true;
}
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *p1,*p2;
void *ptr;
int x;
if(success)*success=false;
if(doublyLinkedList==NULL)return NULL;
if(index<0 || index>=doublyLinkedList->size)return NULL;
x=0;
p1=doublyLinkedList->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(doublyLinkedList->start==p1 && doublyLinkedList->end==p1)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}
else if(doublyLinkedList->start==p1)
{
doublyLinkedList->start=doublyLinkedList->start->next;
doublyLinkedList->start->previous=NULL;
}
else if(doublyLinkedList->end==p1)
{
doublyLinkedList->end=p2;
doublyLinkedList->end->next=NULL;
}
else
{
p2->next=p1->next;
p1->next->previous=p2;
}
free(p1);
doublyLinkedList->size--;
if(success)*success=true;
return ptr;
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return 0;
return doublyLinkedList->size;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL)return;
while(doublyLinkedList->start)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
}
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *node;
int x;
if(success)*success=false;
if(doublyLinkedList==NULL)return NULL;
if(index<0 || index>=doublyLinkedList->size)return NULL;
x=0;
node=doublyLinkedList->start;
while(x<index)
{
node=node->next;
x++;
}
if(success)*success=true;
return node->ptr;
}
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)
{
DoublyLinkedListNode *s,*e,*t,*node;
bool done;
if(success)*success=false;
if(targetDoublyLinkedList==NULL)return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)
{
if(success)*success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceDoublyLinkedList->start;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
else{
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
}
if(success)*success=true;
}
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(success)*success=false;
if(doublyLinkedList==NULL)return doublyLinkedListIterator;
if(doublyLinkedList->start==NULL)
{
if(success)*success=true;
return doublyLinkedListIterator;
}
doublyLinkedListIterator.node=doublyLinkedList->start;
if(success)*success=true;
return doublyLinkedListIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL)return false;
if(doublyLinkedListIterator->node==NULL)return false;
return true;
}
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success)
{
void *ptr=NULL;
if(success)*success=false;
if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL)return ptr;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success)*success=true;
return ptr;
}
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(success)*success=false;
if(doublyLinkedList==NULL) return doublyLinkedListReverseIterator;
if(doublyLinkedList->end==NULL)
{
if(success)*success=true;
return doublyLinkedListReverseIterator;
}
doublyLinkedListReverseIterator.node=doublyLinkedList->end;
if(success)*success=true;
return doublyLinkedListReverseIterator;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL) return false;
if(doublyLinkedListReverseIterator->node==NULL)return false;
return true;
}
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success)
{
void *ptr;
if(success)*success=false;
if(doublyLinkedListReverseIterator==NULL || doublyLinkedListReverseIterator->node==NULL)return NULL;
ptr=doublyLinkedListReverseIterator->node->ptr;
if(success)*success=true;
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->previous;
return ptr;
}
#endif