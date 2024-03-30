#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x;
   int *p ;

   p = malloc(sizeof(int));
   printf("%d\n",p);
    *p = 5;
    printf("%d",*p);
   free(p);
    return 0;
}
