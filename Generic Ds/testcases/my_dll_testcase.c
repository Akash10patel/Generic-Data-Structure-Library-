#include<my_dll.h>
#include<stdio.h>
int main()
{
DoublyLinkedList *list1,*list2;
int i1,i2,i3,i4,i5;
int *x;
int y;
bool succ;
DoublyLinkedListReverseIterator iter;
list1=createDoublyLinkedList(&succ);
list2=createDoublyLinkedList(&succ);
if(succ==false)printf("Not enough memory\n");
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
addToDoublyLinkedList(list1,(void *)&i1,&succ);
if(succ==false)printf("%d is not added\n",i1);
else printf("%d is added\n",i1);

addToDoublyLinkedList(list1,(void *)&i2,&succ);
if(succ==false)printf("%d is not added\n",i2);
else printf("%d is added\n",i2);

addToDoublyLinkedList(list1,(void *)&i3,&succ);
if(succ==false)printf("%d is not added\n",i3);
else printf("%d is added\n",i3);

addToDoublyLinkedList(list1,(void *)&i4,&succ);
if(succ==false)printf("%d is not added\n",i4);
else printf("%d is added\n",i4);

iter=getDoublyLinkedListReverseIterator(list1,&succ);
if(succ)
{
while(hasPreviousInDoublyLinkedList(&iter))
{
x=(int *)getPreviousElementFromDoublyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}


destroyDoublyLinkedList(list1);
printf("destroying dll\n");
}