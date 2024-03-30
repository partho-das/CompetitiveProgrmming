#include<stdio.h>

int main()
{
    int i,j,po=1,xo;

    double sum=0;

    for(i = 1;i<=;i++)
    {
        if(i%2!=0)
        {
            sum +=((double)i)/po;
            po*=2;
        }
    }
    printf("%.2lf\n",sum);

    return 0;
}
