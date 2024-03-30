#include<stdio.h>

int main()
{
    int n,i;
    double m,x,y,ave;

    scanf("%d",&n);

    for(i = 0; i<n;i++)
    {
        scanf("%lf%lf%lf",&m,&x,&y);
        ave = ((m*2)+(x*3)+(y*5))/10;

        printf("%.1lf\n",ave);
    }


    return 0;
}
