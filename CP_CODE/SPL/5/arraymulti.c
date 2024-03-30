//multiplication of two dimensional array in c
#include<stdio.h>

int main()
{
    int  a[10][10],b[10][10],c[10][10]= {{0,0}};
    int i ,j,k,m,n,p;
    ///a  =(m*p) and b =(p*n)
    scanf("%d%d%d",&m,&p,&n);

    for(i = 0;i<m;i++) for( j = 0;j<p;j++)  scanf("%d",&a[i][j]);
    for(i = 0;i<p;i++) for( j = 0;j<n;j++)  scanf("%d",&b[i][j]);

    for(i = 0;i<m;i++){
        for(j = 0;j<n;j++){
            c[i][j] = 0;
            for(k = 0;k<p;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(i = 0;i<m;i++){
        for( j = 0;j<n;j++) printf("%d ",c[i][j]);
        putchar('\n');
    }
    return 0;
}
