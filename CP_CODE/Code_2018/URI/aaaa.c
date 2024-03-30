#include<stdio.h>

int main()
{
    int st[200],test,alp,i,j,arr,s=97;

    scanf("%d",&test);

    for(i = 0;i<test;i++)
    {
        scanf("%d%d",&arr,&alp);

        for(j= 0;j<arr;j++)
        {
            if((s)>(alp+96))
                s=97;

            st[j]=s;
            s++;
         printf("%c",st[j]);
        }
        printf("\n");
    }

    return 0;
}
