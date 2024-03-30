///first sort then apply the formula.
#include<stdio.h>

int main()
{
    double a,b,c,x,y,z;

     scanf("%lf%lf%lf",&a,&b,&c);

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

    if(y >= (z+x))
    {
        printf("NAO FORMA TRIANGULO\n");
    }

    else
    {
        if((y*y) == ((x*x)+(z*z)))
        {
            printf("TRIANGULO RETANGULO\n");
        }
        else if((y*y) > ((x*x) + (z*z)))
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else if((y*y) < ((x*x) + (z*z)))
        {
            printf("TRIANGULO ACUTANGULO\n");
        }

        if(y ==x && x == z)
            printf("TRIANGULO EQUILATERO\n");

        else if( y==x || x == z || z == y )
            printf("TRIANGULO ISOSCELES\n");

    }


    return 0;
}
