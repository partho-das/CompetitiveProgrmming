#include<stdio.h>

int main()

{   int a;

        for(a = 7; a <= 50000; a +=7 )
         {
            if( 10000000%a !=0)
                break;

            printf("%d//",a);
         }


    return 0;
}
