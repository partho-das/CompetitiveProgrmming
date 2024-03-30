#include<stdio.h>

int main()
{
    int sum, a,n=-1,i;

    scanf("%d",&a);

    while(n<=0)
    {
        sum = 0;
        scanf("%d",&n);
         if(n>0)
            for(i = a;i<(a+n);i++)
         {
             sum +=i;
         }
    }
    printf("%d\n",sum);


    return 0;
}
