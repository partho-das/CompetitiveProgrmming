#include<stdio.h>

int main()
{
    int a[4], sum = 0,i;

    for(i = 0; i < 4; i++)
    {
        scanf("%d",&a[i]);

    sum = sum + a[i] ;

    }

    printf("%d",sum);

    return 0;
}
