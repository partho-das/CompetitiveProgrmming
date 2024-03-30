#include<stdio.h>

int main()
{
    int n,sum = 1,x = 0,k,i,j,game = 1,ar[10000]= {0};

    scanf("%d",&n);
    for(i= 1;i<=n;i++)
    {
        sum = 1,game = 1,x = 0;
        while(i)
        {
        game += i;
       if(game>n)
        game-=n;
        if((game)==1)
        break;
         sum+=game;

        }

      for(j = 0;j<i;j++)
      {
          if(sum == ar[j])
          {
                 ar[i-1] = 0;
                 x=1;
            break;
          }


      }
        if(!x)
         ar[i-1] = sum;
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
    for(i = 0 ; i<n; i++)
    {
        if(ar[i]!=0)
        printf("%d ",ar[i]);
    }


    return 0;

}
