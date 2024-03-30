#include<stdio.h>

int main()
{
    int nu,i = 1,j,ans =1;

    scanf("%d",&nu);
    while(i<=nu)
    {
        ans =1;
        for(j =1 ;j<=3;j++)
        {
            ans = ans*i;
             printf("%d",ans);
             if(j!=3)
                printf(" ");
        }
        printf("\n");
        i++;
    }

    return 0;
}
