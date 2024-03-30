#include<stdio.h>

int main()
{

    int m, n,r,s,mul[100][100],k,c;
    scanf("%d%d",&m,&n);
    int a[m][n];
    int i = 0 , j = 0 ;

    for( i = 0; i < m; i ++ )
    {
        for(j = 0;j < n;j ++ )
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d%d",&r,&s);
            int b[r][s];
    for( i = 0; i < r; i ++ )

    {
        for(j = 0;j < s;j ++ )
        {
            scanf("%d",&b[i][j]);
        }
    }
       if(n == r)
    {

    for( i = 0; i < m; i ++ )
    {

        for(j = 0;j < s;j ++ )
        {
             c = 0;
           for (k = 0 ; k < r  ; k++) {
                c = c + (a[i][k]*b[k][j]);
           }
             mul[i][j] = c;
        }


    }
    for( i = 0; i < m; i ++ )
    {
        for(j = 0;j < s;j ++ )
            printf("%d ",mul[i][j]);

        printf("\n");
    }
    }

    return 0;
}

