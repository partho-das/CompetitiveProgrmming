#include<stdio.h>

int main()
{
    int n,k,a,b,c,s;

    double x,y,z;
    scanf("%d%d",&n,&k);

    x = (double)(2*n)/k;

    a = x;
    x = x-a;
    if(x>0)
    {
        a++;
    }

    x = (double)(5*n)/k;
    b = x;
    x = x-b;
    if(x>0)
    b++;

    x = (double)(8*n)/k;
    c = x;
    x = x-c;
    if(x>0)
        c++;

    s = a+b+c;
    printf("%d\n",s);

    return 0;
}
