#include<stdio.h>

#define n 3.14159
int main()
{
  double R, A;
  scanf("%lf",&R);

  A = n*R*R;

  printf("A=%.4lf\n",A);

   return 0;
}

