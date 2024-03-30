#include<stdio.h>
int main()
{
    int t,n,i,fl= 1;


    scanf("%d",&t);
    while(t--)
    {
        fl= 1;
        scanf("%d",&n);


        for(i = 2;i<n;i++)
        {
            if(n%i==0)
            {
                fl = 0;
                break;
            }
        }
        if(fl==0)
            printf("%d nao eh primo\n",n);
        else
            printf("%d eh primo\n",n);

    }


    return 0;
}
