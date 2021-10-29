#include<stdio.h>
#include<my_stack.h>
int main()
{
Stack *stack;
bool success;
int i1,i2,i3,i4,i5;
int *x;
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
stack=createStack(&success);
if(success==false)printf("memory is enough\n");

pushOnStack(stack,(void *)&i1,&success);
if(success)printf("%d is pushed on stack\n",i1);
else printf("%d is not pushed on stack\n",i1);

pushOnStack(stack,(void *)&i2,&success);
if(success)printf("%d is pushed on stack\n",i2);
else printf("%d is not pushed on stack\n",i2);

pushOnStack(stack,(void *)&i3,&success);
if(success)printf("%d is pushed on stack\n",i3);
else printf("%d is not pushed on stack\n",i3);

pushOnStack(stack,(void *)&i4,&success);
if(success)printf("%d is pushed on stack\n",i4);
else printf("%d is not pushed on stack\n",i4);

printf("Size of stack is %d\n",getSizeOfStack(stack));
if(isStackEmpty(stack))printf("Stack is Empty\n");
else printf("Stack is not Empty\n");

x=(int *)elementAtTopOfStack(stack,&success);
if(success==false)printf("Stack is empty\n");
else printf("%d is element at top\n",*x);

printf("Now popping the element of stack\n");
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&success);
printf("%d\n",*x);
}
destroyStack(stack);
printf("Stack destroying\n");
}