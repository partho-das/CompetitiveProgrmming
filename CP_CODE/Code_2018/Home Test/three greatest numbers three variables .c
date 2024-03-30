#include<stdio.h>

int main()
{
    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);
    if (b > a)
    {
        if (b > c)
            printf("%d b is Greatest number  ",b);
        else
            printf("%d c is Greatest number  ",c);
    }
    else
    {
        if(a > c)
            printf("%d a is Greatest number  ",a);
        else
            printf("%d c  is Greatest number  ",c);
    }

    return 0;
}
