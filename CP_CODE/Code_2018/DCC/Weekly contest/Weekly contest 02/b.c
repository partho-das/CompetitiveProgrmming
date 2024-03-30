#include<stdio.h>

#include<math.h>
double  pi = 2 * acos (0.0);
int main()
{
    double r,areac,areas,def;
    int test,i;

    scanf("%d",&test);

    for(i = 1;i<=test;i++)
    {
        scanf("%lf",&r);

        areac = (r*r*pi);
        areas = (2*r)*(2*r);

        def = areas - areac;

        printf("Case %d: %.2lf\n",i,def);
    }



    return 0;
}
