#include<stdio.h>

int main()
{
    int x,y,sunm = 0 ,i,in;

    scanf("%d%d",&x,&y);

    if(x>y)
    {
        in = x;
        x = y;
        y = in;
    }

    i = x+1;

    while(i<y)
    {
        if(i%5 ==2|| i%5==3)
        printf("%d\n",i);

        i++;
    }

    return 0;
}
