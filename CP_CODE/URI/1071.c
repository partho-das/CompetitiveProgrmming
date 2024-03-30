#include<stdio.h>

int main()
{
    int start,end,s= 0, i;

    scanf("%d%d",&start,&end);
    if(start < end)
    {
        for(i = 1+start; i < end; i++ )
        {
            if(i%2 != 0)
                s = s+i;
        }
    }
    else
        for(i = 1+end; i < start; i++ )
    {
        if(i%2 != 0)
            s = s + i;
    }
    printf("%d\n",s);


    return 0;
}
