#include<stdio.h>

int power(int a,int n)
{
    int ans = 1;
    while(n--)
    ans = ans*a;
    return ans;

}

int main()
{
    int a;
    a = power(2,10);

    printf("%d",a);
    return 0;
}
