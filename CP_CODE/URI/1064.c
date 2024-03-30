#include<stdio.h>

int main()
{
   double nu[10],sum = 0,ave;
   int i = 0, s= 0;

    for(i = 0;  i<6;i++)
    {
        scanf("%lf",&nu[i]);
        if(nu[i] >= 0 )
        {
            s++;
            sum = sum + nu[i];
        }
    }
    ave = sum/s;
    printf("%d valores positivos\n",s);
    printf("%.1lf\n",ave);

    return 0;
}
