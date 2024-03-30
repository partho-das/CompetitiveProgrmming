/// if first hour is getter or equal then second one . then add 24 hour to second one .

#include<stdio.h>

int main()

{
    int a, b;

    scanf("%d%d",&a,&b);

    if(a>=b)
    {
        b = (b + 24) - (a);
    }

    else

    {
        b = b - a;
    }
        printf("O JOGO DUROU %d HORA(S)\n",b);

    return 0;
}
