#include<stdio.h>

int main()

{
    long int a,b,i;

    int t;

    scanf("%d",&t);

    for(i = 0; i<t;i++)
    {
        scanf("%ld%ld",&a,&b);

        if(a==b)
        {
            printf("=\n");
        }
        else if(a<b)
        printf("<\n");
        else
            printf(">\n");
    }

    return 0;
}
