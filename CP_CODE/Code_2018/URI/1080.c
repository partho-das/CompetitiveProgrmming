#include<stdio.h>

int main()
{
    int n[200],i,pl = 0;

    for(i = 0; i<100 ; i++ )
    {
        scanf("%d",&n[i]);
    }
    n[100]=0;
    for( i = 0; i <100;i++ )
    {
        if(n[i]<n[1+i])
        {

            pl = i + 1;
        }
        else
        {
             n[i+1]=n[i];
        }
    }
     printf("%d\n%d\n",n[99],(pl+1));




    return 0;
}
