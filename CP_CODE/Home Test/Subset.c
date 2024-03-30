#include<stdio.h>

int arr[15];

int main()
{
    int i,j,n,x,y,sum;

    scanf("%d",&n);
   // for(i = 0;i<n;i++) scanf("%d",&arr[i]);

    x = 1<<n;
    for(i = 0;i<x;i++){
      //  sum = 0;
        for(j =0;j<n;j++)  (i&(1<<j)) ? printf("%d",(j+1)) : printf("") ;
        printf(" ") ;
//        if(sum%360==0) {
//            puts("YES");
//            return 0;
//        }
//        }
    }
    //puts("NO");
    return 0;
}
