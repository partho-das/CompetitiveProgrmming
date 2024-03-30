#include<stdio.h>

int main()
{
    int t,i,n,fib[50];

    fib[0] = 0, fib[1] = 1;
    for(i = 2; i <= 45; i++) fib[i] = fib[i-1]+fib[i-2];

    scanf("%d",&t);
    while(t--) scanf("%d",&n), printf("%d\n", fib[n-1]);

    return 0;
}
