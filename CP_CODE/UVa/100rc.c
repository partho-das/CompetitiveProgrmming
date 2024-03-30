#include<stdio.h>
int cnt  = 0;
void Print(int n)
{
    cnt++;
    if(n==1) return;
    Print(n&1 ? 3*n+1 : n>>1);
}
int  main()
{
    int n,i,m,value = 0,cn  = 0,ex;

   while(scanf("%d%d",&m,&n) !=EOF)
   {
       value = 0,cn  = 0;
       printf("%d %d ",m,n);
       if(m>n)
       {
           ex = m;
           m = n;
           n = ex;
       }

    for(i = m;i<=n;i++)
    {
          Print(i);
          value = cnt;
          if(cn<value)
            cn=value;
            cnt =0;

    }
    printf("%d\n",cn);
   }
    return 0;
}
