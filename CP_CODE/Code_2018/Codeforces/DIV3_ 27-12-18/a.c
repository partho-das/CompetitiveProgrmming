#include<stdio.h>

int main()
{
    char ar[60];
    int n,i,j;
    int sum = 0;

    scanf("%d",&n);
    scanf("%*",j);
    for(i = 0;i<n;i++)
    {
        scanf("%c",&ar[i]);
    }


    for(i = 1;sum<n;i++)
    {
        sum+=i;
        printf("%c",ar[sum-1]);
    }
    printf("\n");

    return 0;
}
