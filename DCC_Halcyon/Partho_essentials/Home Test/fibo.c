#include<stdio.h>

int main()
{
    int t , n , i, j, first = 0 , second = 1, value;

    scanf("%d",&n);
    while(n-- ){
        scanf("%d",&t);
        first = 0 , second = 1;

    for( i = 1 ; i <= t ; i++ )
    {
        if(i == t)
     printf("%d\n",first);
     printf("%d\n",first);

     value = first + second ;

     first = second;
     second = value;

    }

    }


    return 0;
}
