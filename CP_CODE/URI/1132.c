#include<stdio.h>

int main()
{
    int x,y,sum = 0,i,in;

    scanf("%d%d",&x,&y);

    if(x>y)
    {
        in = x;
        x = y;
        y = in;
    }

    i = x;

    while(i<=y)
    {
        if(i%13!= 0)
            sum+=i;
        i++;
    }
    printf("%d\n",sum);

    return 0;
}
