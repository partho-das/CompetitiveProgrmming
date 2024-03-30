#include<stdio.h>

int main()
{
    int n,m;

     scanf("%d",&n);
    while(n)
    {
        n--;
        scanf("%d",&m);
        if(m%2==0)
            printf("0\n");
        else
            printf("1\n");
    }

    return 0;
}
