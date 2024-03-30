#include<stdio.h>

int main()

{
   long int a,b,c,m,n,o,i= 1,s = 0;
    a = b = c = m = n = n = 0;
    scanf("%9ld%9ld%9ld",&a,&b,&c);

    scanf("%9ld%%9ld%9ld",&n,&m,&o);

    c = c+o;
    b = b + m;
    a = a+n;
    i = c;
    while(i)
    {

        i = i%10;
        s++;
    }

    o = c %(100*(s-1));
    c = c - (100*s-1);

    b = o+b;
    i = b;
    s = 0;
    while(i)
    {

        i = i%10;
        s++;
    }

    n = b %(100*(s-1));
    b = b - (100*s-1);


   a = a+n;



    printf("%d %d %d",a,b,c);

    return 0;
}
