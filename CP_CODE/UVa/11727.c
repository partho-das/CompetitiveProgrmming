#include<stdio.h>

int main()
{
    int test,i,s1,s2,s3,keep;

    scanf("%d",&test);

   for(i = 1;i<=test;i++)
    {
        scanf("%d%d%d",&s1,&s2,&s3);

        if(s1>s2&&s2>s3||s1<s2&&s2<s3)
            printf("Case %d: %d\n",i,s2);
        else if(s2>s1&&s1>s3||s2<s1&&s1<s3)
            printf("Case %d: %d\n",i,s1);
        else if(s1>s3&&s3>s2||s1<s3&&s3<s2)
            printf("Case %d: %d\n",i,s3);
    }
    return 0;
}
