#include<stdio.h>

int main()
{
    float a,b,c,p,area;

    scanf("%f%f%f",&a,&b,&c);

    if( a <(b+c) && b<(a+c) && c < (a+b))
    {
        p = (a+b+c);
        printf("Perimetro = %.1lf\n",p);
    }
    else{
        area = ((a+b)*c)/2;
    printf("Area = %.1lf\n",area);
    }
    return 0;
}
