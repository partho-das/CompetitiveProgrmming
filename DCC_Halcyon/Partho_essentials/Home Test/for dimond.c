#include<stdio.h>

int main()

{
    int n,i;


        for(n = 1 ; n<10; n++)
    {
        for(i = 10-n; i>0;i--)
        {
            printf(" ");
        }

        for(i= 1; i<=n;i++)
        {

            printf("*");
        }


        printf("\n");

    }

        for(n = 9 ; n>=1; n--)
    {
        for(i =10-n; 1<=i;i--)
        {
            printf(" ");
        }
        for(i =1;i<=n;i++)
        {
            printf("*");
        }
        printf("\n");

    }

    return 0;
}
