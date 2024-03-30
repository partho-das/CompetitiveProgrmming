#include<stdio.h>

int main()
{
    int a,b,sumi,subi;
    float c,d,sumf,subf;

    scanf("%d%d",&a,&b);

    scanf("%f%f",&c,&d);

    sumi = a+b;
    subi = a-b;

    sumf = c+d;
    subf = c-d;

    printf("%d %d\n%.1f %.1f\n",sumi,subi,sumf,subf);

    return 0;
}
