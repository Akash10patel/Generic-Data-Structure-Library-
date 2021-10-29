#include<stdio.h>
#include<stdlib.h>
#include<my_avl_tree.h>
int myComparator(void *left,void *right)
{
int *leftInt;
int *rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int ch,num;
bool success;
int *x;
AVLTree *tree;
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preOrderIterator;
AVLTreePostOrderIterator postOrderIterator;
AVLTreeLevelOrderIterator levelOrderIterator;
tree=createAVLTree(&success,myComparator);
if(success)
{
while(1)
{
printf("1.Insert Into AVL Tree\n");
printf("2.Remove\n");
printf("3.InOrder Iterator\n");
printf("4.PreOrder Iterator\n");
printf("5.PostOrder Iterator\n");
printf("6.LevelOrder Iterator\n");
printf("7.Search\n");
printf("8.Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a Number : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success)printf("Address is added that contain %d\n",*x);
else printf("Address is not added that contain %d\n",*x);
}else if(ch==2)
{
printf("Enter to number remove : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)removeFromAVLTree(tree,(void *)&num,&success);
if(success)printf("%d is found and remove\n",*x);
else printf("%d is not found\n",num);
}else if(ch==3)
{
inOrderIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(&inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator,&success);
printf("%d\n",*x);
}
}
}else if(ch==4)
{
preOrderIterator=getAVLTreePreOrderIterator(tree,&success);
if(success)
{
while(hasNextPreOrderElementInAVLTree(&preOrderIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&preOrderIterator,&success);
printf("%d\n",*x);
}
}
}else if(ch==5)
{
postOrderIterator=getAVLTreePostOrderIterator(tree,&success);
if(success)
{
while(hasNextPostOrderElementInAVLTree(&postOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&postOrderIterator,&success);
printf("%d\n",*x);
}
}
}else if(ch==6)
{
levelOrderIterator=getAVLTreeLevelOrderIterator(tree,&success);
if(success)
{
while(hasNextLevelOrderElementInAVLTree(&levelOrderIterator))
{
x=(int *)getNextLevelOrderElementFromAVLTree(&levelOrderIterator,&success);
printf("%d\n",*x);
}
}
}else if(ch==7)
{
printf("Enter to number serach : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)getFromAVLTree(tree,(void *)&num,&success);
if(success)printf("%d is found\n",*x);
else printf("%d is not found\n",num);
}else if(ch==8) break;
}
}
return 0;
}