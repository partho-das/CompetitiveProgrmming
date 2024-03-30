#include<stdio.h>
#include<stdlib.h>
int main()
{
int *ptr;
ptr = (int *)calloc(10 , sizeof(int));
ptr[4] = 6;
ptr[7] = 5;
printf("%d ",ptr[9]);
printf("%d ",ptr[8]);
printf("%d ",ptr[7]);
printf("%d ",ptr[6]); /// the default value of any position is zero
printf("%d ",ptr[5]); ///until we change it.
printf("%d ",ptr[4]);
ptr = (int *)calloc(10 , sizeof (int));
printf("After reallocation : ");
printf("%d ",ptr[9]);
printf("%d ",ptr[8]);
printf("%d ",ptr[7]); /// After the reallocation it changes its value to
printf("%d ",ptr[6]); /// default value.
printf("%d ",ptr[5]);
printf("%d ",ptr[4]);
free(ptr);
return 0;
}
