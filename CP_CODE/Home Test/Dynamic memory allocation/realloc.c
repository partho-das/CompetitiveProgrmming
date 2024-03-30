#include<stdio.h>
#include<stdlib.h>
int main()
{
int *ptr,*ptr2;
ptr = (int *)malloc(5 * sizeof(int));
ptr[4] = 10;
ptr[1] = 2;
printf("ptr = %d\n",ptr[4]);
ptr2 = (int *)realloc(ptr , 2 * sizeof(int));
printf("getter ptr = %d\n",ptr[4]); /// reallocating less size
printf("getter ptr2 = %d\n",ptr2[4]);
printf("in range ptr = %d\n",ptr[1]); /// destroyed the value of getter position
printf("in range ptr2 = %d\n",ptr2[1]);
free(ptr);
return 0;
}
/**
1.
#include<stdio.h>
#include<stdlib.h>
int main()
{
int *ptr,*ptr2;
ptr = (int *)malloc(5 * sizeof(int));
ptr[4] = 10;
printf("ptr = %d\n",ptr[4]);
ptr2 = (int *)realloc(ptr , 10 * sizeof(int)); ///reallocating ptr
printf("ptr = %d\n",ptr[4]); ///(for the reallocation the memory size of ptr free address changed )
printf("ptr2 = %d\n",ptr2[4]); ///and putting the same address to ptr2
							///for that the address and values are same
free(ptr);
return 0;
}

2.
#include<stdio.h>
#include<stdlib.h>
int main()
{
int *ptr,*ptr2;
ptr = (int *)malloc(5 * sizeof(int));
ptr[4] = 10;
printf("%d\n",&ptr[4]);
ptr2 = (int *)realloc(ptr , 10 * sizeof(int)); ///reallocating ptr
printf(" ptr = %d\n",&ptr[4]); ///(for the reallocation the memory size of ptr free address changed )
printf(" ptr2 = %d\n",&ptr2[4]); ///and putting the same address to ptr2
							///for that the address and values are same
free(ptr);
}

3.
#include<stdio.h>
#include<stdlib.h>
int main()
{
int *ptr,*ptr2;
ptr = (int *)malloc(5 * sizeof(int));
ptr[4] = 10;
ptr[1] = 2;
printf("ptr = %d\n",ptr[4]);
ptr2 = (int *)realloc(ptr , 2 * sizeof(int));
printf("getter ptr = %d\n",ptr[4]); /// reallocating less size
printf("getter ptr2 = %d\n",ptr2[4]);
printf("in range ptr = %d\n",ptr[1]); /// destroyed the value of getter position
printf("in range ptr2 = %d\n",ptr2[1]);
free(ptr);
return 0;
}
*/
