#include<stdio.h>

int main()
{
    int n,i=0,x = 0,j,k,value,cnt = 0,value1;
    scanf("%d%d",&n,&k);
    int ar[10100];
    while(n>i){
        scanf("%d",&ar[i]);
        i++;
    }
    for (i = 0; i < n ; i++){
        for(j = i; j < n; j++){
            if ( ar[i]> ar[j]){
                x=ar[i];
                ar[i]=ar[j];
                ar[j]=x;
            }
        }
    }
    value1 = (k*2);
    value =value1 + ar[0];
    for(i = 0 ; i<n; i++)
    {
        if(ar[i]<=value);
        else
        {
            cnt++;

            value =value1 + ar[i];
            i--;
        }
    }
    cnt++;
    printf("%d\n",cnt);
    return 0;
}
