#include<stdio.h>

int main()
{
    double arr[13][13],sum = 0, ava = 0;
    int i,j;
    char sa;

    scanf("%c",&sa);
    for(i = 0;i<12;i++)
    {
        for(j = 0;j<12;j++)
        {
            scanf("%lf",&arr[i][j]);
            if(i>j) sum += arr[i][j];
        }
    }
    if(sa == 'S') printf("%.1lf\n",sum);
    else{
        ava = sum/66;
        printf("%.1lf\n",ava);
    }


    return 0;
}
