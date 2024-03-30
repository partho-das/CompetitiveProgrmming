#include<stdio.h>

int main()

{
    int n,i;
    scanf("%d",&n);

    for(i = 0; i<10000; i++)
    {
        if(i%n == 0)
        printf("%d\n",2+i);
    }

    return 0;
}
