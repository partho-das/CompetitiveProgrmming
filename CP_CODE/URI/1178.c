#include<stdio.h>

int main()
{
    double ar[120],value;
    int i;


    scanf("%lf",&value);

    for(i = 0;i<100;i++)
    {
        ar[i] = value;
        value *= 2;

        printf("N[%d] = %.4lf\n",i,ar[i]);
    }

    return 0;
}
