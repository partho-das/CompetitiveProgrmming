#include<stdio.h>

int main()
{
    double n;
   int cnt = 0;

   scanf("%lf",&n);
   for( n; 1.0< n ; n/=10 )
   {
        cnt++;
        printf("%lf\n", n);

   }
  printf("%lf\n", n);
   printf("%d\n", cnt);

    return 0;
}
