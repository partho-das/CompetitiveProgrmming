#include<stdio.h>

int main()

{
    int n,k,a[100000],i,x = 1000000,j,s = 0;

    scanf("%d%d",&n,&k);

    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=0)
        if(a[i]<x)
            x = a[i];
    }


    for(i = 1;i<=k;i++)

    {
            printf("%d\n",x);
        for(j = 0; j< n; j++)
        {
            if(a[j]!=0)
            a[j]= a[j] - x;
        }

        s = 0;

        for(j = 0; j< n; j++)
        {

            if(a[j] == 0)
                s++;
        }
         x = 100000000;
        if(s == n)
            x = 0;


        for(j = 0; j< n; j++)
        {
            if(a[j]!=0)
            if(a[j]<x)
            x = a[j];
        }
    }

    return 0;
}
