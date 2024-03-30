#include<stdio.h>

int main()

{
    int i;

    for(i = 0; i<= 5; i ++)
    {
        printf("%d ",i);
        if(i == 3)
        continue;
        printf("%d ",i);

    }
    return 0;
}
