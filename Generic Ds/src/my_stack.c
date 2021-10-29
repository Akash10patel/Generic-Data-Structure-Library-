#ifndef __MY_STACK__C
#define __MY_STACK__C 123
#include<my_stack.h>
#include<stdio.h>
#include<stdlib.h>
#include<my_common.h>
Stack * createStack(bool *success)
{
SinglyLinkedList *singlyLinkedList;
Stack *stack;
if(success)*success=false;
singlyLinkedList=createSinglyLinkedList(success);
if(success==false)return NULL;
stack=(Stack *)malloc(sizeof(Stack));
if(stack==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success)*success=false;
return NULL;
}
stack->singlyLinkedList=singlyLinkedList;
if(success)*success=true;
return stack;
}
void pushOnStack(Stack *stack,void *ptr,bool *success)
{
if(success)*success=false;
if(stack==NULL)return;
if(stack==NULL || stack->singlyLinkedList==NULL)return;
insertIntoSinglyLinkedList(stack->singlyLinkedList,0,ptr,success);
}
void * popFromStack(Stack *stack,bool *success)
{
void *ptr;
if(success)*success=false;
if(stack==NULL || stack->singlyLinkedList==NULL)return NULL;
ptr=(void *)removeFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(success)*success=true;
return ptr;
}
int getSizeOfStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL)return 0;
return getSizeOfSinglyLinkedList(stack->singlyLinkedList);
}
void * elementAtTopOfStack(Stack *stack,bool *success)
{
void *ptr;
if(success)*success=false;
if(stack==NULL || stack->singlyLinkedList==NULL)return NULL;
ptr=(void *)getFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(success)*success=true;
return ptr;
}
bool isStackEmpty(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL)return true;
if(stack->singlyLinkedList->size==0)return true;
return false;
}
void destroyStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL)return;
clearSinglyLinkedList(stack->singlyLinkedList);
free(stack);
}
void clearStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL)return;
clearSinglyLinkedList(stack->singlyLinkedList);
}
#endif