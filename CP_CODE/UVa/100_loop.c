#include<stdio.h>

int main()
{
    int start,end,i,j,cnt = 0,inte = 0,scopy,x = 0,ecopy;


    while(scanf("%d%d",&start,&end) ==2 )
    {
        scopy = start;
        ecopy = end;

            if(start>end)
                {
                x = start;
                start = end;
                end = x;
                }
        inte = 0;

        for(i = start;i<=end;i++)
        {
            cnt = 0;

            start = i;

            while(1)
            {

            if(start==1)
            {
                cnt++;
                if(inte<cnt)
                    inte = cnt;
                    break;
            }
            else
            {
                if(start%2==0)
                    start = start/2;
                else
                    start = (3*start)+1;

                cnt++;
            }

            }
        }
        printf("%d %d %d\n",scopy,ecopy,inte);
    }


    return 0;
}
