#include<stdio.h>

int main()
{
   double n,res;
   int i = 0;

   while(scanf("%lf",&n) !=EOF)
   {
       i++;
        res= n/4;

        printf("Person %d: %.2lf\n",i,res);
   }


    return 0;
}
