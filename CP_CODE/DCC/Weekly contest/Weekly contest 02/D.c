#include<stdio.h>

int main()
{
    int nu = 1;

    while(nu!=42)
    {
        scanf("%d",&nu);
        if(nu!=42)
        printf("%d\n",nu);
    }
    return 0;

}
