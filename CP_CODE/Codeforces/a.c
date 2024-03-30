#include<stdio.h>

int main()
{
    int test,l1,r1,l2,r2;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);


        if(l1==r2)
            printf("%d %d\n",r1,l1);

        else
             printf("%d %d\n",l1,r2);
    }

    return 0;
}
