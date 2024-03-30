#include<stdio.h>

int main()
{

    int y,b,r,i,j,num = 0,res = 0;


    scanf("%d%d%d",&y,&b,&r);


    if(y<b&&(b-y)>=1)
    {
        if(y<r&&(r-y)>=2)
            num = 1;
        else
            num = 3;
    }
    else
        if(b<r&&(r-b)>=1)
            num = 2;
        else
            num = 3;

    if(num == 1 )
    {
        res = (y+(y+1)+(y+2));
    }
    else if(num == 2)
    {
        res = (b+(b-1)+(b+1));
    }
    else if(num == 3)
    res = r+(r-1)+(r-2);

    printf("%d\n",res);

    return 0;
}
