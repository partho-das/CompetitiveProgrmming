#include<stdio.h>

int main()
{
    double value,avar,s = 0;
    int cnt = 0,i;

    while(1)
    {
        scanf("%lf",&value);

        if(value<0||value>10)
        {
            printf("nota invalida\n");
        }
        else
        {
            cnt++;
            s+=value;

        }
        if(cnt==2)
        {
            avar=(s/cnt);
             printf("media = %.2lf\n",avar);
             return 0;
        }
    }

    return 0;
}
