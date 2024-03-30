#include<stdio.h>

int main()
{

   long int a,b;

    while(scanf("%li%li",&a,&b) ==2)
    {
        if(a<=b)
            b = b-a;

        else
            b = a-b;

        printf("%li\n",b);
    }

    return  0;
}
