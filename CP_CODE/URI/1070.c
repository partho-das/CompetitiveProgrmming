#include<stdio.h>

int main()
{
    int n,i,s= 0;

    scanf("%d",&n);

    if(n%2 == 0)
    {
        n++;
    }

    if(n%2 !=0)
    {
        for(i = 1;i<=6; i++)
        {

            printf("%d\n",n);
            n+=2;
        }
    }
    return 0;
}
