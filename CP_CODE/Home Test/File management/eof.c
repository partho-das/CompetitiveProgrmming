#include<stdio.h>

int main()
{
    int n;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n) !=EOF)
    {
        printf("%d\n",n);
    }

    return 0;
}
