#include<stdio.h>

int main()

{
    int h1,h2,m1,m2;

    scanf("%d%d%d%d",&h1,&m1,&h2,&m2);

    int t1 = h1*60 + m1, t2 = h2*60 + m2;
    int t = t2 - t1+(t2 <= t1)*24*60;

    int h = t/60, m = t - h*60;

    ///printf("%d %d\n", h, m);
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",h,m);

    return 0;
}
