#include<stdio.h>

int main()
{
    int n,i,t;

    scanf("%d",&t);
    while(t--)
         {
             scanf("%d",&n);
             int sum = 0;

             for(i = 1; i<n;i++)
             {
                 if(n%i==0)
                 {
                     sum+=i;
                 }
                 if(sum>n) break;

             }
             if(sum==n)
                printf("%d eh perfeito\n",n);
             else
                printf("%d nao eh perfeito\n",n);

         }
    return 0;
}
