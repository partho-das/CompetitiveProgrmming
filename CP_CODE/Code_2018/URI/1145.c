#include<stdio.h>

int main()
{
    int nu,i,j,mod;

    scanf("%d%d",&mod,&nu);

    for(i =1; i<= nu;i++)
    {
        printf("%d",i);
        if(i%mod == 0)
           putchar('\n');
        else
            putchar(' ');

    }

    return 0;
}
