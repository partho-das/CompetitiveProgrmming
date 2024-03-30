#include<stdio.h>
#include<string.h>
int main()
{
    char ar[200],st[200],arr[200];
    int i,x = 0;

    while( gets(ar))
    {

        x = 0;

        for(i = 0;ar[i];i++)
        {
            if(ar[i]!='m' && ar[i] != 'a'&& ar[i]!='z'&& ar[i]!='i'&&ar[i]!='r')
            {
                st[x]= ar[i];
                x++;
            }
        }
        for(i= 0;i<x;i++)
            printf("%c",st[i]);

        printf("\n");

    }


    return 0;
}
