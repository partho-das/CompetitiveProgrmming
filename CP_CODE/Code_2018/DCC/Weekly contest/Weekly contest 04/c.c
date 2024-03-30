#include<stdio.h>

int main()
{
    int n,k,mt = 240 ,cnt = 0,rt= 0,i;
    scanf("%d%d",&n,&k);

    mt = mt - k;

    for(i = 1; i<=n;i++ )
    {

        rt+=(i*5);
        if(rt<=mt)
        {
            cnt++;
        }
        else
            break;
    }

    printf("%d\n",cnt);



    return 0;
}
