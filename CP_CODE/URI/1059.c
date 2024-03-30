#include<stdio.h>

void print(int n)
{
    if(n < 2) return;

    print(n-1);
    if(!(n&1))  printf("%d\n",n);
}
int main()
{
    print(100);
    return 0;
}
