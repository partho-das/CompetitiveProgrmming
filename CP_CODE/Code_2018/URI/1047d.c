#include<stdio.h>

int main()

{
    int a, b, c, d,x,y,k,h;

    scanf("%d%d%d%d",&a,&c,&b,&d);

    if( a>b)   k = (b + 24 -a);
    else        k = b - a;

    if( c > d ) {
        h= d+60 - c;
        --k;
    }
    else h = d - c;

   if (a == b && c == d)
   {
     printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
       return 0;
   }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",k,h);
    return 0;
}

