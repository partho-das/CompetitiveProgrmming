#include<stdio.h>

int main()
{
    int i = 0,now = 0 ,first = 0,second = 1,nth;

    scanf("%d",&nth);

    for(i = 1; i<=nth;i++)
    {
        now = first+ second;
        printf("%d",first );
        first = second;
        second = now;
        if(i<nth)
            printf(" ");


    }
    printf("\n");

    return 0;
}
