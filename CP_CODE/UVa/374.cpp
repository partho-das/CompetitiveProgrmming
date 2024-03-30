#include <stdio.h>

long long mod(long long b, long long p, long long m)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
    	long long temp = mod(b,p/2,m);
        return (temp*temp)%m;
    }
    return (mod(b,p-1,m)*(b%m))%m;
}
int main()
{
    int b,p,m;
    while(scanf("%d %d %d",&b,&p,&m) == 3){
        printf("%d\n",mod(b,p,m));
    }
    return 0;
}