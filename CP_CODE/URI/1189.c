#include<stdio.h>

int main()
{
    double m[12][12],sum = 0;
    char ck;
    int i,j,k = 0;

    ck = getchar();
    for(i = 0;i<12;i++)
    {
        for(j = 0;j<12;j++)
        {
            scanf("%lf",&m[i][j]);

            if(i<6)
            {
                if((j<i))
                {
                sum+= m[i][j];
                k++;
                }
            }
            else
            {
                if((j<(11-i)))
                {
                sum+= m[i][j];
                k++;
                }
            }
        }
    }
    if(ck == 'S')
    printf("%.1lf\n",sum);
    else
    {
         printf("%.1lf\n",sum/k);
    }



    return 0;
}
