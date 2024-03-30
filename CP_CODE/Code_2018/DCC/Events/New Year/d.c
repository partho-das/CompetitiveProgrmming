#include<stdio.h>

int main()
{
    int x,y;
    double res = 1;

    while(scanf("%d%d",&x,&y) == 2)
    {
        res = (y/(float)x)*100;

        printf("%.2lf%%\n",res);
    }

    return 0;
}
