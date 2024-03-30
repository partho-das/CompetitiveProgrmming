#include<stdio.h>
#include<string.h>
int main()
{
    char ar[10000][100],st[10000][100];
    int i,x = 0,n,cnt = 0,ln[10000],j,k,cntw = 0;

    scanf("%d",&n);

    for(i = 0;i<n;i++ )
    {
        cnt = 0;
        cntw =0;

        gets(ar[i]);

    if(i>0)
    {
        cntw =0;
        for(j = 0;j<=i;j++)
        {

            x = strcmp(ar[i],ar[j]);
            if(x== 0)
               cntw++
            printf("%d\n",x);
            if(cnt)
            {
               // st[cnt] = ar[i];
            }
        }
    }

    }
    printf("%d\n",cnt);
    for(i = 0;i<=cnt;i++)
    {
        printf("%s",st[i]);
    }


    return 0;
}
