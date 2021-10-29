#include<my_sll.h>
#include<stdio.h>
int main()
{
SinglyLinkedList *list1,*list2;
int i1,i2,i3,i4,i5;
int *x;
int y;
bool succ;
SinglyLinkedListIterator iter;
list1=createSinglyLinkedList(&succ);
list2=createSinglyLinkedList(&succ);
if(succ==false)printf("Not enough memory\n");
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
addToSinglyLinkedList(list1,(void *)&i1,&succ);
if(succ==false)printf("%d is not added\n",i1);
else printf("%d is added\n",i1);

addToSinglyLinkedList(list1,(void *)&i2,&succ);
if(succ==false)printf("%d is not added\n",i2);
else printf("%d is added\n",i2);

addToSinglyLinkedList(list1,(void *)&i3,&succ);
if(succ==false)printf("%d is not added\n",i3);
else printf("%d is added\n",i3);

addToSinglyLinkedList(list1,(void *)&i4,&succ);
if(succ==false)printf("%d is not added\n",i4);
else printf("%d is added\n",i4);


iter=getSinglyLinkedListIterator(list1,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
destroySinglyLinkedList(list1);
printf("destroying sll\n");
}