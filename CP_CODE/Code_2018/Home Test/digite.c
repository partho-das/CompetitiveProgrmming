#include<stdio.h>

int count_digit(int n){
    if(!n) return 1;
    int cnt = 0;
    while(0 < n) n /= 10, cnt++;
    return cnt;
}

int main()
{
    int n, m, di = 0 ;

    scanf("%d",&n);
    printf("%d\n", count_digit(n));


    return 0;
}
