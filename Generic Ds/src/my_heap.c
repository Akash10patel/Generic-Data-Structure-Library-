#ifndef __MY_HEAP__C
#define __MY_HEAP__C 123
#include<my_heap.h>
#include<my_array.h>
#include<stdlib.h>
#include<my_common.h>
Heap * createHeap(int (*comparator)(void *,void *),bool *success)
{
bool succ;
Heap *heap;
heap=NULL;
if(success)*success=false;
if(comparator==NULL)return heap;
heap=(Heap *)malloc(sizeof(Heap));
if(heap==NULL)return heap;
heap->array=createArray(&succ);
if(!succ)
{
free(heap);
return NULL;
}
heap->size=0;
heap->comparator=comparator;
if(success)*success=true;
return heap;
}
void addToHeap(Heap *heap,void *elem,bool *success)
{
int succ,ci,ri,weight;
void *riValue,*ciValue;
if(success)*success=false;
if(heap==NULL || heap->array==NULL)return;
setElementOfArray(heap->array,heap->size,elem,&succ);
if(!succ)return;
heap->size++;
ci=heap->size-1;
while(ci>0)
{
ri=(ci-1)/2;
ciValue=getElementFromArray(heap->array,ci,&succ);
riValue=getElementFromArray(heap->array,ri,&succ);
weight=heap->comparator(ciValue,riValue);
if(weight<0)
{
setElementOfArray(heap->array,ri,ciValue,&succ);
setElementOfArray(heap->array,ci,riValue,&succ);
ci=ri;
}
else break;
}
if(success)*success=true;
}
void * removeFromHeap(Heap *heap,bool *success)
{
void *element,*swiValue,*riValue;
int succ,swi,ri,lci,rci,upperBond;
if(success)*success=false;
if(heap==NULL || heap->array==NULL)return NULL;
if(heap->size==0)return NULL;
element=getElementFromArray(heap->array,0,&succ);
setElementOfArray(heap->array,0,getElementFromArray(heap->array,heap->size-1,&succ),&succ);
heap->size--;
ri=0;
upperBond=heap->size-1;
while(ri<upperBond)
{
lci=(ri*2)+1;
if(lci>upperBond)break;
rci=lci+1;
if(rci>upperBond)
{
swi=lci;
}
else
{
if(heap->comparator(getElementFromArray(heap->array,lci,&succ),getElementFromArray(heap->array,rci,&succ))<0)
{
swi=lci;
}
else 
{
swi=rci;
}
}
riValue=getElementFromArray(heap->array,ri,&succ);
swiValue=getElementFromArray(heap->array,swi,&succ);
if(heap->comparator(swiValue,riValue)<0)
{
setElementOfArray(heap->array,swi,riValue,&succ);
setElementOfArray(heap->array,ri,swiValue,&succ);
ri=swi;
}
else break;
}
if(success)*success=true;
return element;
}
void * elementAtTopOfHeap(Heap *heap,bool *success)
{
void *element;
int succ;
if(success)*success=false;
if(heap==NULL || heap->array==NULL)return NULL;
if(heap->size==0)return NULL;
element=getElementFromArray(heap->array,0,&succ);
if(success)*success=true;
return element;
}
int getSizeOfHeap(Heap *heap)
{
if(heap==NULL || heap->array==NULL)return 0;
return heap->size;
}
void destroyHeap(Heap *heap)
{
if(heap==NULL || heap->array==NULL)return;
destroyArray(heap->array);
free(heap);
}
#endif