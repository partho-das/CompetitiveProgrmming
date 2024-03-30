#include<stdio.h>
#include<stdlib.h>
int *arr ,*brr;
int main()
{
    int i,n,m,j,x,ck = 0;
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    for( i = 0;i<n;i++)
    scanf("%d",&arr[i]);
    scanf("%d",&m);
    brr = malloc(m*sizeof(int));
    for( i = 0;i<m;i++)
    scanf("%d",&brr[i]);

    for(i = 0;i<n;i++)
    {
        for(j = 0;j<m;j++)
        {
            if(arr[i]==brr[j])
            {
                brr[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < m ; i++){
            ck = 0;
        for(j = i; j < m; j++){
            if ( brr[i]> brr[j]){
                x=brr[i];
                brr[i]=brr[j];
                brr[j]=x;
            }
            else if(brr[i] == brr[j])
            {
                ck++;
                if(ck != 1)
                {
                    brr[j] = 0;
                }
            }
        }
    }
    for( i = 0;i<m;i++)
    {
        if(brr[i]!=0)
        {
            printf("%d",brr[i]);
            if(i!=m-1)
                printf(" ");
            else
             printf("\n");
        }
    }




    return 0;
}
