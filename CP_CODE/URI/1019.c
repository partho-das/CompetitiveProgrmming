#include<stdio.h>

int main()

{
    int t,h,min;

    scanf("%d",&t);

    h = t/3600;

    t = t % 3600;

    min = t / 60;

    t = t % 60;

    printf("%d:%d:%d\n",h,min,t);


    return 0;
}
