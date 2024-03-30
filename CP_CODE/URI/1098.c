#include<stdio.h>

int main()
{
    double i,j,m,n;

    for(i = 0;i<=2.0;i+=.2)
    {
        j = i+1;
        n = 3+i;
        for(j = j; j<=n;j++)
        {
            printf("I=%g J=%g\n",i,j);
        }
    }
    return 0;
}
