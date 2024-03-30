#include<stdio.h>

int main()

{
    int a,b,c,ab = 0,bc = 0;

    scanf("%d%d%d",&a,&b,&c);

    ab = (a + b + abs(a-b))/2 ;

    b = ab;

    bc = (b + c + abs(b-c))/2 ;

    printf("%d eh o maior\n",bc);

    return 0;
}
