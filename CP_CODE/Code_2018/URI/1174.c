#include<stdio.h>

int main()
{
    double ar[200];

    int i = 0;


    for(i = 0;i<100;i++)
    {
        scanf("%lf",&ar[i]);

        if(ar[i]<=10)
            printf("A[%d] = %.1lf\n",i,ar[i]);
    }

    return 0;
}
