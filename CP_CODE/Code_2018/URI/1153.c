#include<stdio.h>

int main()
{
    int num,i,ans = 1;

    scanf("%d",&num);

    for(i = 1;i<=num;i++)
    {
        ans*=i;
    }
    printf("%d\n",ans);

    return 0;
}
