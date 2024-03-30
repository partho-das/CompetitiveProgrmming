#include<stdio.h>

int main()
{
    int x,z = 0,i,s=0,cnt=0;

    scanf("%d",&x);
    z = x-1;
    while(x>=z)
    {
        z = x-1;
        scanf("%d",&z);

        if(x<z)
        {
            for(i = x;i<10000;i++)
            {
                s+=i;
                cnt++;
                if(s>z)
                {
                    printf("%d\n",cnt);
                    break;
                }
            }
        }
    }

    return 0;
}
