#include<stdio.h>

int main()
{
    char ar[100000];
        int n,i,s = 0,j = 0,c= 0;

    scanf("%d",n);

    for(i = 0; i < n; i++)
    {
        scanf("%c",ar[i]);

        }

     for(i = 0; i < n; i++)
    {
        if(ar[i] == 'S')
        {
            s++;
            j = i;
            goto ax;
        }
    }
    ax:
         for(i = 0; i < n; i++)
    {
        if(ar[i] == 'G')
        {
            c++;
            j = i;

        }
    }
        if(s == 0)
        {
            printf("%d",n);
        }
        if(c== n)
        {

        }







    return 0;
}
#include<stdio.h>

int main()
{
    char ar[100000];
        int n,i,s = 0,j = 0,c= 0;

    scanf("%d",n);

    for(i = 0; i < n; i++)
    {
        scanf("%c",ar[i]);

        }

     for(i = 0; i < n; i++)
    {
        if(ar[i] == 'S')
        {
            s++;
            j = i;
            goto ax;
        }
    }
    ax:
         for(i = 0; i < n; i++)
    {
        if(ar[i] == 'G')
        {
            c++;
            j = i;

        }
    }
        if(s == 0)
        {
            printf("%d",n);
        }
        if(c== n)
        {

        }







    return 0;
}
