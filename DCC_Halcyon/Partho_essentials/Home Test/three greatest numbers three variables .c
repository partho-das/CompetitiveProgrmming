///smallest among three
#include<stdio.h>

int main()
{
    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);
    if (b < a)
    {
        if (b < c)
            printf("%d b is smallest number  ",b);
        else
            printf("%d c is smallest number  ",c);
    }
    else
    {
        if(a < c)
            printf("%d a is smallest number  ",a);
        else
            printf("%d c  issmallest number  ",c);
    }

    return 0;
}
