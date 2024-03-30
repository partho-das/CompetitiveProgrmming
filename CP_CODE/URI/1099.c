#include<stdio.h>

int main()
{
    int n,x,y,i,j,t,s = 0;
    scanf("%d",&n);

    for(t = 0;t<n;t++)
    {
        s = 0;
        scanf("%d%d",&x,&y);
     if(x!=y)
     {
        if(x<y)
        {
            for(i = x+1;i<y;i++)
            {
                if(i%2!=0)
                {
                    s+=i;
                }
            }
        }
        else if(x>y)
        {
            for(i = y+1;i<x;i++)
            {
                if(i%2!=0)
                {
                    s+=i;
                }
            }
        }
        printf("%d\n",s);
     }
     else
        printf("0\n");
    }

    return 0;
}
