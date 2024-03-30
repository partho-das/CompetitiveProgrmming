/// triangle calculator.
/// condition statement.


#include<stdio.h>

int main()
{
    int a,b,c;
    printf("Please enter the three sides of a triangle.\n");
    scanf("%d%d%d",&a,&b,&c);

    if(a+b>c && b+c > a && a+c > b)
    {
        printf("\nIt is possible to make triangle with this sides.\n");
        if(a == b && b == c)
        {
            printf("Equilateral triangle\n");

        }

        else if(a == b || b == c || c == a)
        {
            printf("Isosceles triangle\n");
        }
        else if(a!=b && b!=c && c!=a)
            printf("Scalene\n");

    }
    else
    {
            printf("It is not possible to make triangle with this sides.\n");
    }


    return 0;
}
