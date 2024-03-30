#include<stdio.h>

int main()

{
    int x[200][200];
    int n[200],i,j,r,s= 0;

    scanf("%d",&n[0]);

    for( i = 0;i < n[0]; i++ )
    {
        scanf("%d",&n[i+1]);
        for(j = 0; j < n[i+1] ; j++)
        {
            scanf("%d",&x[i][j]);
        }

    }


    for( i = 0; i<n[1];i++ )
    {
        s= 0;
        for(j =1; j < n[0] ;j++)
        {
            for(r = 0; r < n[j+1]; r++)
            {
                if(x[0][i] == x[j][r])
                {
                    s++;

                }
            }
        }
        if((s+1) == n[0])
            printf("%d ",x[0][i]);
    }

    return 0;
}
