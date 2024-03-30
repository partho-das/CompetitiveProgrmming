#include<stdio.h>

int main()
{
    double money,a = 0,b = 0,c = 0,s = 0;

    scanf("%lf",&money);

    if(money <= 2000)
    {
        printf("Isento\n");
        return 0;
    }

    else if(money>4500)
    {
        b = (money-4500)*.28;

    }
   money = (money - 2000);
   if(money>1000)
   {
       a = money - 1000;

       c = 1000*.08;
   }
   else
   {
       c = money*.08;
   }

   if(a > 1500)
   {
       money = a - 1500;
       a=1500*.18;
   }
   else
   {
       a= a*.18;
   }

    s = a+b+c;


    printf("R$ %.2lf\n",s);





    return 0;
}
