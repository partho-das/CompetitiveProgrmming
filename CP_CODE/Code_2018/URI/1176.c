#include<stdio.h>

int main()
{
    unsigned long long int fib[70];
    int i,nt,t;

    fib[0] = 0;
    fib[1] = 1;
    for(i = 2;i<61;i++) fib[i] = fib[i-2]+fib[i-1];

    scanf("%d",&t);
    while(t--) scanf("%d",&nt), printf("Fib(%d) = %llu\n",nt,fib[nt]);

    return 0;
}
