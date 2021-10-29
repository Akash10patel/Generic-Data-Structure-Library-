#include<stdio.h>
#include<my_pQueue.h>
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
PQueue *pQueue;
pQueue=createPQueue(myComparator,&succ);
if(!succ) printf("Memory is Low\n");
a1=100;
a2=34;
a3=23;
a4=50;
a5=12;
a6=304;
addToPQueue(pQueue,(void *)&a1,&succ);
addToPQueue(pQueue,(void *)&a2,&succ);
addToPQueue(pQueue,(void *)&a3,&succ);
addToPQueue(pQueue,(void *)&a4,&succ);
addToPQueue(pQueue,(void *)&a5,&succ);
addToPQueue(pQueue,(void *)&a6,&succ);
printf("Size of PQueue is %d\n",getSizeOfPQueue(pQueue));
while(getSizeOfPQueue(pQueue)>0)
{
x=(int *)removeFromPQueue(pQueue,&succ);
printf("%d\n",*x);
}
printf("Size of PQueue is %d\n",getSizeOfPQueue(pQueue));
destroyPQueue(pQueue);
return 0;
}