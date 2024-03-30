#include<stdio.h>

int main()
{
    int arr[150],n,i = 0,ex = 0,ey = 0,ax[150],x = 0,j,ck = 0;
    ax[0] = 0;

    scanf("%d",&n);

    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
            if(arr[i]>ex)
                ex = arr[i];
    }
    for(i = 0;i<n;i++)
    {
        if(ex%arr[i] == 0)
            {
                for(j = 0;j<x;j++)
                {
                    if(arr[i]!=ax[j])
                        {
                        ck = 0;
                }
                else
                    {
                        ck = 1;
                        break;
                        }

                    }
                if(ck==0)
                {
                    ax[x] = arr[i];
                    x++;
                    arr[i] = -1;
                }

            }
    }
    for(i = 0;i<n;i++)
    {
            if(arr[i]>ey)
                ey = arr[i];
    }

    printf("%d %d",ex,ey);


    return 0;
}

