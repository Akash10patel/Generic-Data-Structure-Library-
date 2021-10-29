#include<my_array.h>
#include<stdio.h>
int main()
{
Array *array;
bool succ;
int i;
int *ptr;
array=createArray(&succ);
if(!succ)printf("Low On Memory\n");
setElementOfArray(array,0,(void *)224,&succ);
if(succ)printf("address added that contain 224\n");
else printf("address not added that contain 224\n");
setElementOfArray(array,1,(void *)45666,&succ);
if(succ)printf("address added that contain 45666\n");
else printf("address not added that contain 45666\n");
setElementOfArray(array,2,(void *)89700,&succ);
if(succ)printf("address added that contain 89700\n");
else printf("address not added that contain 89700\n");
setElementOfArray(array,3,(void *)34522,&succ);
if(succ)printf("address added that contain 34522\n");
else printf("address not added that contain 34522\n");
setElementOfArray(array,4,(void *)202020,&succ);
if(succ)printf("address added that contain 202020\n");
else printf("address not added that contain 202020\n");
printf("Array size is : %d",getSizeOfArray(array));
for(i=0;i<getSizeOfArray(array);i++)
{
ptr=(int *)getElementFromArray(array,i,&succ);
printf("(%d--->%d)",i,*ptr);
}
destroyArray(array);
return 0;
}