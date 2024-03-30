/// sum of m to n odd numbers

#include<stdio.h>

int main()
{
    int n,i,sum =0,m,exc = 0 ;
    scanf("%d",&m,&n);

    if(m>n)
    {
        exc= m;
        m = n;      ///if m>n exchange the value of them
        n = exc;
    }

    for(i = m;i<=n;i++)
    {
        if(i%2!=0)
            sum+=i;  ///sum = sum +i;
    }
    printf("%d",sum);
    return 0;
}
