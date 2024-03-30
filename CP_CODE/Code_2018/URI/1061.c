#include<stdio.h>

int main()

{
   int d1,d2,h1,h2,m1,m2,s1,s2,t1,t2,t;
    char a[10],b[10];
   scanf("Dia %d\n%d : %d : %d",&d1,&h1,&m1,&s1);
   scanf("%*cDia %d\n%d : %d : %d",&d2,&h2,&m2,&s2);


   t1 = (d1*86400)+m1*60+s1+(h1*3600);
   t2 = (d2*86400)+(m2*60)+s2+(h2*3600);
 t = (t2-t1)+(t2<=t1)*86400;

   int day = t/86400, h = (t - (day*86400))/(60*60), min =(t- (h*3600) - (day*86400))/60 , s =  (t- (h*3600) -(day*86400)-(min*60));

    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n",day,h,min,s);


    return 0;
}
