#ifndef __MY_AVL_TREE__C
#define __MY_AVL_TREE__C
#include<stdlib.h>
#include<my_avl_tree.h>
AVLTree * createAVLTree(bool *success,int (*predicate)(void *,void *))
{
AVLTree *avlTree;
if(success)*success=false;
avlTree=(AVLTree *)malloc(sizeof(AVLTree));
if(avlTree==NULL || predicate==NULL)return NULL;
avlTree->start=NULL;
avlTree->predicate=predicate;
avlTree->size=0;
if(success)*success=true;
return avlTree;

}
void destroyAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL || avlTree->start==NULL)return;
clearAVLTree(avlTree);
free(avlTree);
}
int getSizeOfAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL)return 0;
return avlTree->size;
}
void clearAVLTree(AVLTree *avlTree)
{

}
void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
Stack *stack;
bool succ;
AVLTreeNode *t,*j;
int weight;
if(success)*success=false;
if(avlTree==NULL)return;
if(ptr==NULL)return;
if(avlTree->start==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL)return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
avlTree->start=t;
avlTree->size++;
if(success)*success=true;
return;
}
stack=createStack(&succ);
if(succ==false)return;
j=avlTree->start;
while(1)
{
weight=avlTree->predicate(ptr,j->ptr);
if(weight==0)return;
pushOnStack(stack,(void *)j,&succ);
if(succ==false)
{
destroyStack(stack);
stack=NULL;
return;
}
if(weight<0)
{
if(j->left==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
avlTree->size++;
if(success)*success=true;
balanceAVLTree(avlTree,stack);
destroyStack(stack);
}
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
Stack *stack;
Queue *queue;
bool succ;
AVLTreeNode *t,*j,*e,*f,**p2p;
void *foundPtr;
if(success)*success=false;
if(avlTree==NULL || avlTree->start==NULL)return NULL;
stack=createStack(&succ);
if(succ==false)return NULL;
queue=createQueue(&succ);
if(succ==false)return NULL;
t=avlTree->start;
while(t!=NULL)
{
if(avlTree->predicate(ptr,t->ptr)==0)break;
pushOnStack(stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(stack);
return NULL;
}
j=t;
if(avlTree->predicate(ptr,t->ptr)<0)t=t->left;
else t=t->right;
}
if(t==NULL)return NULL;
foundPtr=t->ptr;
if(t==avlTree->start)p2p=&(avlTree->start);
else if(t==j->left)p2p=&(j->left);
else p2p=&(j->right);
if(t->left==t->right)
{
*p2p=NULL;
}
else
{
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left)
{
addToQueue(queue,(void *)e,&succ);
if(succ==false)
{
destroyQueue(queue);
return NULL;
} 
f=e;
}
pushOnStack(stack,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
return NULL;
}
if(e==t->right)
{
e->left=t->left;
}
else
{
f->left=e->right;
e->right=t->right;
e->left=t->left;
}
*p2p=e;
}
else
{
for(e=t->left;e->right!=NULL;e=e->right)
{
addToQueue(queue,(void *)e,&succ);
if(succ==false)
{
destroyQueue(queue);
return NULL;
}
f=e;
}
pushOnStack(stack,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
return NULL;
}
if(e==t->left)
{
e->right=t->right;
}
else
{
f->right=e->left;
e->right=t->right;
e->left=e->left;
}
*p2p=e;
}
}
while(!isQueueEmpty(queue))
{
e=(AVLTreeNode *)removeFromQueue(queue,&succ);
pushOnStack(stack,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
return NULL;
}
}
free(t);
avlTree->size--;
balanceAVLTree(avlTree,stack);
destroyStack(stack);
if(success)*success=true;
return foundPtr;
}
void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
AVLTreeNode *t;
if(success)*success=false;
if(avlTree==NULL || avlTree->start==NULL)return NULL;
t=avlTree->start;
while(t!=NULL)
{
if(avlTree->predicate(ptr,t->ptr)==0)
{
if(success)*success=true;
return t->ptr;
}
else if(avlTree->predicate(ptr,t->ptr)<0)t=t->left;
else t=t->right;
}
if(t==NULL)
{
return NULL;
}
}

int getHeightOfAVLTree(AVLTreeNode *root)
{
int leftHeight,rightHeight;
if(root==NULL)return 0;
leftHeight=getHeightOfAVLTree(root->left);
rightHeight=getHeightOfAVLTree(root->right);
return (leftHeight>rightHeight)?leftHeight+1:rightHeight+1;
}
void balanceAVLTree(AVLTree *avlTree,Stack *stack)
{
int lch,rch,diff;
bool succ;
AVLTreeNode *lc,*rc,*lcrc,*rclc,*parent,*root;
AVLTreeNode **p2p;
if(avlTree==NULL || avlTree->start==NULL)return;
if(stack==NULL)return;
while(!isStackEmpty(stack))
{
root=popFromStack(stack,&succ);
lch=getHeightOfAVLTree(root->left);
rch=getHeightOfAVLTree(root->right);
diff=lch-rch;
if(diff<=1 && diff>=-1)continue;
parent=elementAtTopOfStack(stack,&succ);
if(root==avlTree->start)p2p=&(avlTree->start);
else if(root==parent->left)p2p=&(parent->left);
else p2p=&(parent->right);
if(lch<rch)      //right is heavy.
{
rc=root->right;
if(getHeightOfAVLTree(rc->left)>getHeightOfAVLTree(rc->right))
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}    //right is heavy if ended.
else   //left is heavy.
{
lc=root->left;
if(getHeightOfAVLTree(lc->right)>getHeightOfAVLTree(lc->left))
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}    //left is heavy if ended.
}
}
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeNode *t;
int succ;
AVLTreeInOrderIterator avlTreeInOrderIterator;
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
if(success)*success=false;
if(avlTree==NULL)return avlTreeInOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreeInOrderIterator;
}
avlTreeInOrderIterator.stack=createStack(&succ);
if(succ==false)return avlTreeInOrderIterator;
t=avlTree->start;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.stack=NULL;
return avlTreeInOrderIterator;
}
t=t->left;
}
avlTreeInOrderIterator.node=popFromStack(avlTreeInOrderIterator.stack,&succ);
if(success)*success=true;
return avlTreeInOrderIterator;
}
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator)
{
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL)return false;
return true;
}
void * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
int succ;
if(success)*success=false;
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL)return NULL;
j=avlTreeInOrderIterator->node;
t=j->right;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
return j->ptr;
}
t=t->left;
}
if(isStackEmpty(avlTreeInOrderIterator->stack))
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->node=NULL;
avlTreeInOrderIterator->stack=NULL;
}
else
{
avlTreeInOrderIterator->node=popFromStack(avlTreeInOrderIterator->stack,&succ);
}
if(success)*success=true;
return j->ptr;
}

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreePreOrderIterator avlTreePreOrderIterator;
avlTreePreOrderIterator.node=NULL;
avlTreePreOrderIterator.stack=NULL;
if(success)*success=false;
if(avlTree==NULL)return avlTreePreOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreePreOrderIterator;
}
avlTreePreOrderIterator.stack=createStack(&succ);
if(succ==false)return avlTreePreOrderIterator;
avlTreePreOrderIterator.node=avlTree->start;
if(success)*success=true;
return avlTreePreOrderIterator;
}
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator)
{
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL)return false;
return true;
}
void * getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
int succ;
if(success)*success=false;
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL)return NULL;
j=avlTreePreOrderIterator->node;
if(j->right!=NULL)
{
pushOnStack(avlTreePreOrderIterator->stack,(void *)j->right,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(j->left!=NULL)
{
pushOnStack(avlTreePreOrderIterator->stack,(void *)j->left,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(isStackEmpty(avlTreePreOrderIterator->stack))
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
}
else
{
avlTreePreOrderIterator->node=(AVLTreeNode *)popFromStack(avlTreePreOrderIterator->stack,&succ);
}
if(success)*success=true;
return j->ptr;
}

AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeNode *t;
int succ;
AVLTreePostOrderIterator avlTreePostOrderIterator;
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success)*success=false;
if(avlTree==NULL)return avlTreePostOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreePostOrderIterator;
}
avlTreePostOrderIterator.stack=createStack(&succ);
if(succ==false)return avlTreePostOrderIterator;
t=avlTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(avlTreePostOrderIterator.stack,(void *)t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.stack=NULL;
return avlTreePostOrderIterator;
}
}
pushOnStack(avlTreePostOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.stack=NULL;
return avlTreePostOrderIterator;
}
t=t->left;
}
t=(AVLTreeNode *)popFromStack(avlTreePostOrderIterator.stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator.stack) && t->right!=NULL && t->right==elementAtTopOfStack(avlTreePostOrderIterator.stack,&succ))
{
popFromStack(avlTreePostOrderIterator.stack,&succ);
pushOnStack(avlTreePostOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.stack=NULL;
return avlTreePostOrderIterator;
}
t=t->right;
}
else
{
break;
}
}
avlTreePostOrderIterator.node=t;
if(success)*success=true;
return avlTreePostOrderIterator;
}
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator)
{
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL)return false;
return true;
}
void * getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
int succ;
if(success)*success=false;
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL)return NULL;
j=avlTreePostOrderIterator->node;
if(isStackEmpty(avlTreePostOrderIterator->stack))
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
t=NULL;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(avlTreePostOrderIterator->stack,(void *)t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
}
pushOnStack(avlTreePostOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
t=t->left;
}
t=(AVLTreeNode *)popFromStack(avlTreePostOrderIterator->stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator->stack) && t->right!=NULL && t->right==elementAtTopOfStack(avlTreePostOrderIterator->stack,&succ))
{
popFromStack(avlTreePostOrderIterator->stack,&succ);
pushOnStack(avlTreePostOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
t=t->right;
}
else
{
break;
}
}
avlTreePostOrderIterator->node=t;
if(success)*success=true;
return j->ptr;
}
AVLTreeLevelOrderIterator getAVLTreeLevelOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeNode *t;
int succ;
AVLTreeLevelOrderIterator avlTreeLevelOrderIterator;
avlTreeLevelOrderIterator.node=NULL;
avlTreeLevelOrderIterator.queue=NULL;
if(success)*success=false;
if(avlTree==NULL)return avlTreeLevelOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
avlTreeLevelOrderIterator.queue=createQueue(&succ);
if(succ==false)return avlTreeLevelOrderIterator;
avlTreeLevelOrderIterator.node=avlTree->start;
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
bool hasNextLevelOrderElementInAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator)
{
if(avlTreeLevelOrderIterator==NULL || avlTreeLevelOrderIterator->node==NULL)return false;
return true;
}
void * getNextLevelOrderElementFromAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator,bool *success)
{
AVLTreeNode *j;
int succ;
if(success)*success=false;
if(avlTreeLevelOrderIterator==NULL || avlTreeLevelOrderIterator->node==NULL)return NULL;
j=avlTreeLevelOrderIterator->node;
if(j->left!=NULL)
{
addToQueue(avlTreeLevelOrderIterator->queue,(void *)j->left,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->queue=NULL;
avlTreeLevelOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(j->right!=NULL)
{
addToQueue(avlTreeLevelOrderIterator->queue,(void *)j->right,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->queue=NULL;
avlTreeLevelOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(isQueueEmpty(avlTreeLevelOrderIterator->queue))
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->queue=NULL;
avlTreeLevelOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
else
{
avlTreeLevelOrderIterator->node=(AVLTreeNode *)removeFromQueue(avlTreeLevelOrderIterator->queue,&succ);
}
if(success)*success=true;
return j->ptr;
}
#endif