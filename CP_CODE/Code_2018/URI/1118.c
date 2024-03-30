#include<stdio.h>

int main()
{
    double value,media,s = 0;
    int ck = 0 , t = 0,cnt= 0;

    y:
        cnt= 0;
        s = 0;
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
            media = (s/cnt);
            printf("media = %.2lf\n",media);
            goto x;
        }

    }

    x:
        while(1)
    {
    printf("novo calculo (1-sim 2-nao)\n");
    scanf("%d",&t);
    if(t==2)
    return 0;
        else if(t==1)
        goto y;
    }


    return 0;
}
