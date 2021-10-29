#include<stdio.h>
#include<my_queue.h>
int main()
{
Queue *queue;
bool success;
int i1,i2,i3,i4,i5;
int *x;
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
queue=createQueue(&success);
if(success==false)printf("memory is enough\n");

addToQueue(queue,(void *)&i1,&success);
if(success)printf("%d is added to queue\n",i1);
else printf("%d is not added to queue\n",i1);

addToQueue(queue,(void *)&i2,&success);
if(success)printf("%d is added to queue\n",i2);
else printf("%d is not added to queue\n",i2);

addToQueue(queue,(void *)&i3,&success);
if(success)printf("%d is added to queue\n",i3);
else printf("%d is not added to queue\n",i3);

addToQueue(queue,(void *)&i4,&success);
if(success)printf("%d is added to queue\n",i4);
else printf("%d is not added to queue\n",i4);

printf("Size of queue is %d\n",getSizeOfQueue(queue));
if(isQueueEmpty(queue))printf("Queue is Empty\n");
else printf("Queue is not Empty\n");

x=(int *)elementAtFrontOfQueue(queue,&success);
if(success==false)printf("Queue is empty\n");
else printf("%d is element at front\n",*x);

printf("Now removing the element of queue\n");
while(!isQueueEmpty(queue))
{
x=(int *)removeFromQueue(queue,&success);
printf("%d\n",*x);
}
destroyQueue(queue);
printf("Queue destroying\n");
}