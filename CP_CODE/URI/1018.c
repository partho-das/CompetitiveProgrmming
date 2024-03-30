#include<stdio.h>

int main()
{
    int n,in;

    scanf("%d",&n);

    printf("%d\n",n);

    in = n/100;

    printf("%d nota(s) de R$ 100,00\n",in);

    n = n%100;

    in = n/50;

    printf("%d nota(s) de R$ 50,00\n",in);

    n = n%50;

    in = n/20;

    printf("%d nota(s) de R$ 20,00\n",in);

    n = n%20;

    in = n/10;

    printf("%d nota(s) de R$ 10,00\n",in);

    n = n%10;

    in = n/5;

    printf("%d nota(s) de R$ 5,00\n",in);

    n = n%5;

    in = n/2;

    printf("%d nota(s) de R$ 2,00\n",in);

    n = n%2;

    in = n/1;

    printf("%d nota(s) de R$ 1,00\n",in);


    return 0;
}
