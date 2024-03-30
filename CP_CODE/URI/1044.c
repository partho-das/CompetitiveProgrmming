#include<stdio.h>

int main()

{
    int n, m,p;

    scanf("%d%d",&n,&m);

    if(n == m)
        printf("Sao Multiplos\n");

    else if(n > m )
    {
        if((n % m) == 0)
            printf("Sao Multiplos\n");
        else
            printf("Nao sao Multiplos\n");
    }
    else
        {

        if((m%n) == 0)
              printf("Sao Multiplos\n");
        else
            printf("Nao sao Multiplos\n");
        }


    return 0;
}
