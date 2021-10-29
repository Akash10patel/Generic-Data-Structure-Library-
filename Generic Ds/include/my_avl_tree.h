#ifndef __MY_AVL_TREE__H
#define __MY_AVL_TREE__H
#include"my_common.h"
#include"my_stack.h"
#include"my_queue.h"
typedef struct __$__my_avl_tree_node
{
void *ptr;
struct __$__my_avl_tree_node *left;
struct __$__my_avl_tree_node *right;
}AVLTreeNode;

typedef struct __$__my_avl_tree
{
struct __$__my_avl_tree_node *start;
int (*predicate)(void *,void *);
int size;
}AVLTree;

typedef struct __$__my_avl_tree_in_order_iterator
{
struct __$__my_avl_tree_node *node;
Stack *stack;
}AVLTreeInOrderIterator;

typedef struct __$__my_avl_tree_pre_order_iterator
{
struct __$__my_avl_tree_node *node;
Stack *stack;
}AVLTreePreOrderIterator;

typedef struct __$__my_avl_tree_post_order_iterator
{
struct __$__my_avl_tree_node *node;
Stack *stack;
}AVLTreePostOrderIterator;

typedef struct __$__my_avl_tree_level_order_iterator
{
struct __$__my_avl_tree_node *node;
Queue *queue;
}AVLTreeLevelOrderIterator;

AVLTree * createAVLTree(bool *success,int (*predicate)(void *,void *));
void destroyAVLTree(AVLTree *avlTree);
int getSizeOfAVLTree(AVLTree *avlTree);
void clearAVLTree(AVLTree *avlTree);
void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
int getHeightOfAVLTree(AVLTreeNode *root);
void balanceAVLTree(AVLTree *avlTree,Stack *stack);


AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator);
void * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success);

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator);
void * getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success);

AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator);
void * getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success);

AVLTreeLevelOrderIterator getAVLTreeLevelOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextLevelOrderElementInAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator);
void * getNextLevelOrderElementFromAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator,bool *success);
#endif