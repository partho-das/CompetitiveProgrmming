#include<stdio.h>

int main()
{
    double arr[13][13],sum = 0,ava = 1;
    int i,j,li;
    char sa;

    scanf("%d%*c%c",&li,&sa);
    for(i = 0;i<12;i++)
    {
        for(j= 0;j<12;j++)
        {
            scanf("%lf",&arr[i][j]);
            if(j==li) sum+=arr[i][j];
        }
    }
    if(sa=='S')
        printf("%.1lf\n",sum);
    else
    {
        ava = (sum/12);
        printf("%.1lf\n",ava);
    }

    return 0;
}
