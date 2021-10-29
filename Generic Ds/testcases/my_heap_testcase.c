#include<stdio.h>
#include<my_heap.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int a1,a2,a3,a4,a5,a6;
int succ,i;
int *x;
Heap *heap;
heap=createHeap(myComparator,&succ);
if(!succ) printf("Memory is Low\n");
a1=100;
a2=34;
a3=23;
a4=50;
a5=12;
a6=304;
addToHeap(heap,(void *)&a1,&succ);
addToHeap(heap,(void *)&a2,&succ);
addToHeap(heap,(void *)&a3,&succ);
addToHeap(heap,(void *)&a4,&succ);
addToHeap(heap,(void *)&a5,&succ);
addToHeap(heap,(void *)&a6,&succ);
printf("Size of Heap is %d\n",getSizeOfHeap(heap));
while(getSizeOfHeap(heap)>0)
{
x=(int *)removeFromHeap(heap,&succ);
printf("%d\n",*x);
}
printf("Size of Heap is %d\n",getSizeOfHeap(heap));
destroyHeap(heap);
return 0;
}