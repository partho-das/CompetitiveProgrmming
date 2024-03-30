#include<stdio.h>

int main()

{
    int n,value[1000], i;

    scanf("%d",&n);

    for(i = 0; i<n; i++)
    {
        scanf("%d",&value[i]);
         if(value[i] == 0)
            printf("NULL\n");

        else if(value[i]%2 == 0 )
        {
            if(value[i]<0)
                printf("EVEN NEGATIVE\n");
            else
                printf("EVEN POSITIVE\n");

        }
            else
        {
            if(value[i]<0)
                printf("ODD NEGATIVE\n");
            else
                printf("ODD POSITIVE\n");

        }
    }

    return 0;

}
