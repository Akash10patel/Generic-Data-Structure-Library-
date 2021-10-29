#ifndef __MY_ARRAY__H
#define __MY_ARRAY__H 123
#include"my_common.h"
typedef struct __$__my_array
{
int rows;
void ***ptr;
int size;
}Array;

Array * createArray(bool *success);
int getSizeOfArray(Array *array);
void setElementOfArray(Array *array,int index,void *ptr,bool *success);
void * getElementFromArray(Array *array,int index,bool *success);
void destroyArray(Array *array);
#endif
