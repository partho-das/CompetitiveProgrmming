#include<stdio.h>

int main()
{
    int n=1,i =  0;


    while(scanf("%d",&n),n)
    {
    for(i = 1;i<= n;i++)
    {
        printf("%d",i);
        if(i!=n)
            printf(" ");
    }

    printf("\n");
}

    return  0;
}
