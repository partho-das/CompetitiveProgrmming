#include<stdio.h>

int main()
{
    int nu,i,j,cnt=0,dis = 1,test,sum = 0 ;


    scanf("%d",&test);
    for(i = 1;i<=test;i++)
    {

        sum = 0;
        cnt= 1;
    scanf("%d%d",&nu,&dis);

    for(j=nu;cnt<=dis;j++)
    {
        if(j%2!=0)
        {
            sum+=j;
            cnt++;
        }
    }
    printf("%d\n",sum);

    }
    return 0;
}
