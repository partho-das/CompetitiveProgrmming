#include<stdio.h>

int main()


{
    double x, y, x1, y1, d;

    scanf("%lf%lf%lf%lf",&x,&y,&x1,&y1);

    d = sqrt(((x - x1)*(x - x1))+((y - y1) * (y - y1)));

    printf("%.4lf\n",d);



    return 0;
}
