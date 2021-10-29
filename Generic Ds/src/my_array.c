#ifndef __MY_ARRAY__C
#define __MY_ARRAY__C 123
#include<my_array.h>
#include<stdlib.h>
#include<my_common.h>
Array * createArray(bool *success)
{
Array *array;
if(success)*success=false;
array=(Array *)malloc(sizeof(Array));
array->ptr=NULL;
array->size=0;
array->rows=0;
if(success)*success=true;
return array;
}
int getSizeOfArray(Array *array)
{
if(array==NULL || array->ptr==NULL)return 0;
return array->size;
}
void setElementOfArray(Array *array,int index,void *element,bool *success)
{
int rowIndex,columnIndex;
void ***tmp;
int i,sp,ep;
if(success)*success=false;
if(array==NULL)return;
if(index<0)return;
rowIndex=index/10;
columnIndex=index%10;
if(rowIndex>=array->rows)
{
if(array->ptr!=NULL)
{
tmp=(void ***)calloc(rowIndex+1,sizeof(void **));
sp=0;
ep=array->rows-1;
for(i=sp;i<ep;i++)tmp[0]=array->ptr[0];
free(array->ptr);
array->ptr=tmp;
array->rows=rowIndex+1;
}
else
{
array->ptr=(void ***)calloc(rowIndex+1,sizeof(void **));
array->rows=rowIndex+1;
}
}
if(array->ptr[rowIndex]==NULL)
{
array->ptr[rowIndex]=(void **)calloc(10,sizeof(void *));
}
array->ptr[rowIndex][columnIndex]=element;
if(index>=array->size)array->size=index+1;
if(success)*success=true;
}
void * getElementFromArray(Array *array,int index,bool *success)
{
int rowIndex,columnIndex;
if(success)*success=false;
if(array==NULL || array->ptr==NULL)return 0;
if(array->size==0)return 0;
if(index<0 || index>=array->size)return 0;
rowIndex=index/10;
if(rowIndex>=array->rows)return 0;
if(array->ptr[rowIndex]==NULL)return 0;
columnIndex=index%10;
if(success)*success=true;
return array->ptr[rowIndex][columnIndex];
}
void destroyArray(Array *array)
{
int i,ep,sp;
if(array==NULL || array->ptr==NULL)return;
sp=0;
ep=array->rows-1;
for(i=sp;i<ep;i++)
{
if(array->ptr[i]!=NULL)free(array->ptr[i]);
}
free(array->ptr);
free(array);
}
#endif