#include<stdio.h>

int main()
{
    int n,i;
    double x,y,result;

    scanf("%d",&n);

    for(i = 0; i<n;i++)
    {
        scanf("%lf%lf",&x,&y);
        if(y==0)
            printf("divisao impossivel\n");
        else
        {
            result = x/y;
        printf("%.1lf\n",result);
        }

    }



    return 0;
}
