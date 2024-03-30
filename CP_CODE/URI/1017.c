#include<stdio.h>

int main()

{
    int hour,speed;
    double oil;
    scanf("%d%d",&hour,&speed);

    oil = (speed*hour)/(12.0);

    printf("%.3lf\n",oil);

    return 0;
}
