#include<stdio.h>

void print(int n)
{

    printf("%d ",(n+1-n));

    if(n ==5 )
        return ;

    print(n+1);
}


int main()
{
    int n;
    scanf("%d",&n);

    print(n);



    return 0;
}
