#include<stdio.h>

int arr[15];

int main()
{
    int i,j,n,x,y,sum;

    scanf("%d",&n);
   for(i = 0;i<n;i++) scanf("%d",&arr[i]);

    x = 1<<n;
    for(i = 0;i<x;i++){
        sum = 0;
        for(j =0;j<n;j++)  (i&(1<<j)) ? printf("%d",(j+1)) : printf("") ;
        printf(" ") ;
        if(sum%360==0) {
            puts("YES");
            return 0;
        }



    }
    puts("NO");

    i= 2;
    while(i--)
        printf("%d ",i);
    return 0;
}


#include<stdio.h>


int main()
{
    int test,n,k,i,j,cnt = 0,ar[5050],x,pr[5000];

    scanf("%d%d",&test,&k);

    for(i = 0;i<test;i++) scanf("%d",&ar[i]);

    n = test;
    for (i = 0; i < n ; i++){
        for(j = i; j < n; j++){ /// if j i start  j= o it will short in dicreacing order.
            if ( ar[i]> ar[j]){
                x=ar[i];
                ar[i]=ar[j];
                ar[j]=x;
            }
        }
    }

    for (i = 0; i < n ; i++){
        cnt = 0;
        for(j = i; j < (i+k+1); j++){
              if(ar[i]==ar[j])
              cnt++;

        if(cnt>k)
        {
            printf("NO");
            return 0;
        }

        }
        if(cnt==(pr[i-1]))
        {
            cnt++;
            if(cnt>k)
            {
                cnt=(k-cnt);
            }
        }

   pr[i]  = cnt;
    }
    for (i = 0; i < n ; i++){
        for(j = i; j < n; j++){
            if ( ar[i] == ar[j]&&pr[i]>pr[j]){
                x=pr[i];
                pr[i]=pr[j];
                pr[j]=x;
            }
        }
    }

    for (i = 0; i < n ; i++)
        printf("%d ",pr[i]);

    printf("\n");


    return 0;
}
#include<stdio.h>
#include<string.h>

int cmp(char *a, char *b){
    int i = 0, j = 0;
    while(a[i] && b[i] && a[i]==b[i]) i++,j++;

    if(a[i] < b[i]) return -1;
    if(a[i] > b[i]) return 1;
    return 0;

}

int main(int a)
{

    int i = cmp("1234","1234");
    printf("%d",a);


    return 0;
}


*/


