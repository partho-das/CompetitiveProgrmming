#include<stdio.h>

int main()
{
    int ar[20], i, val = 0;
    scanf("%d",&val);
    for(i = 0;i<10;i++)
    {
        ar[i] = val;
        printf("N[%d] = %d\n",i,ar[i]);
        val*=2;
    }

    return 0;
}
