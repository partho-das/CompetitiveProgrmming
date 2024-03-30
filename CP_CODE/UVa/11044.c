#include<stdio.h>

int main()
{
    int m,n,a,value,x,y,xv,yv,test;
scanf("%d",&test);
while(test--)
{
    scanf("%d%d",&m,&n);
    m-=2;
    n-=2;

    x = m/3;
    xv = m%3;
    y = n/3;
    yv = n%3;
    if(xv!=0)
        x++;
    if(yv!=0)
        y++;

    value = x*y;
    printf("%d\n",value);
}
    return 0;
}
