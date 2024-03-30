#include<stdio.h>

int main()
{
    int a,b,c,x,y,z;

    scanf("%d%d%d",&a,&b,&c);

    (a<b)?((a<c)?(x = a):(x = c)):((b<c)?(x = b):(x = c));
     (a>b)?((a>c)?(y = a):(y = c)):((b>c)?(y = b):(y = c));


    if((a == x && b == y)||(a == y && b == x))
    {
        z = c;
    }
    else if((b == x && c == y )||(b == y && c == x ))
    {
         z = a;
    }
    else if ( (c == x && a == y )|| (c == y && a == x))
    {
        z = b;
    }

    printf("%d\n%d\n%d\n",x,z,y);


    printf("\n%d\n%d\n%d\n",a,b,c);




    return 0;
}

