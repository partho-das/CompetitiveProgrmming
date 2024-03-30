#include<stdio.h>

int main()
{
    int ck = 0,i,j,n;

    while(scanf("%d",&n) !=EOF)
    {
         ck = 0;
        for(i = 2;i<n;i++)
        {
            if(n%i == 0)
            {
                printf("Friendzoned!\n");
                ck = 1;
                break;
            }

        }
        if(ck != 1)
        printf("Oh love!\n");
    }


    return 0;
}
