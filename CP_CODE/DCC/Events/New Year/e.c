#include<stdio.h>

int main()
{
    int i,n,t,kr,ko,ans;
    char ro[100],oz[100];


    scanf("%d",&t);

    for(i= 0;i<t;i++)
    {
        scanf("%s",ro);
        scanf("%d",&kr);
        scanf("%s",oz);
        scanf("%d",&ko);



        ans= kr^ko;

        printf("Case %d: %d\n",(i+1),ans);
    }

    return 0;
}
