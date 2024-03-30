#include<stdio.h>
#define min(a,b) (a > b ? b : a)

int abs(int x){ return x < 0 ? -x: x;}
int main()

{
    int n,ar[200],x,s = 0,j;
    int i;
    scanf("%d",&n);

    for(i = 0;i<n;i++) scanf("%d",&ar[i]);
    int res = 2e9;
    for(x = 0; x < n; x++){
        s = 0;
        for( i = 0; i < n; i++)s += ar[i]*2*(abs(x-i) + i + x);
        res = min(res,s);
    }
    printf("%d\n",res);



    return 0;
}
