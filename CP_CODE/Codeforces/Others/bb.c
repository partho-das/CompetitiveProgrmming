#include<stdio.h>

int main()
{

    int n,i,j,ar[200],x,sum =0;

    scanf("%d",&n);


    for(i = 0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
     for (i = 0; i < n ; i++){
        for(j = i; j < n; j++){ /// if j i start  j= o it will short in dicreacing order.
            if ( ar[i]> ar[j]){
                x=ar[i];
                ar[i]=ar[j];
                ar[j]=x;

              }
        }
    }


    for(i=0;i<n;i+=2)
    {
        sum+=(ar[i+1]-ar[i]);
    }
        printf("%d",sum);

    return 0;
}
