#include<stdio.h>

int main()
{
    int ar[30],i,ex = 0;

     for(i = 0;i<20;i++)
     {
         scanf("%d",&ar[i]);

     }


     for(i = 0;i<10;i++)
     {
         ex = ar[i];
         ar[i] = ar[19-i];
         ar[19-i] = ex;
     }
     for(i = 0;i<20;i++)
     {
         printf("N[%d] = %d\n",i,ar[i]);
     }


    return 0;
}
