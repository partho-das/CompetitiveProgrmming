#include<stdio.h>
#include<stdlib.h>

int main()
{

    int *ptr;
    ptr = (int *)malloc(100*sizeof(int));
    ptr[0] = 5;

    printf("%d\n",ptr[0]);

    ptr = (int *)malloc(100*sizeof(int));

     printf("%d\n",ptr[0]);

    free(ptr);


    return 0;
}
