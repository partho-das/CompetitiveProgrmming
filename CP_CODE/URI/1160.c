#include<stdio.h>

int main()
{
    int t,i,p1,p2,re1 = 0,re2= 0;

    double g1,g2;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%lf%lf",&p1,&p2,&g1,&g2);

        re1= p1;
        re2 = p2;

        for(i = 0;re1<=re2;i++)
        {
          re1 += (((double)p1/100)*g1);
            re2 +=(((double)p2/100)*g2);
            p1= re1;
            p2= re2;
            if(i>100)
            {
                 printf("Mais de 1 seculo.\n");
                 break;
            }
         }

            if(i<=100)
         printf("%d anos.\n",i);
    }


    return 0;
}
