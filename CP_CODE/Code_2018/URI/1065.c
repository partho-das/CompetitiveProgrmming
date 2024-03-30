#include<stdio.h>

int even()
{
    int n[6],i,s= 0;
    for(i = 0; i < 5; i++)
    {
        scanf("%d",&n[i]);
        if(!(n[i]&1))
           s++;

    }
    printf("%d valores pares\n",s);
}


int main()
{

    even();
    return 0;
}
