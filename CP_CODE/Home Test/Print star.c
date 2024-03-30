#include<stdio.h>
#define dbg(x) printf("%s = %d\n", #x, x)

int main()
{
    int j ,n  ;
    scanf("%d", &n);
    int i ;
    for(i = 1 ; i <=n ; i += 2)
    {


        for( j = 1   ;  j <= i ; j ++)

        {

            printf("*");


        }
    printf("\n");
       /* for( j = 2   ;  j <= i ; j ++)
        {
            printf("*");
        }
        printf("\n");*/
    }
    return 0;
}
