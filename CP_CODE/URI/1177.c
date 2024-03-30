#include<stdio.h>

int main()
{
    int i,j = 0,value;
    scanf("%d",&value);
    for(i = 0, j = 0; i<1000;i++, j = (j+1)%value) printf("N[%d] = %d\n",i,j);
    return 0;
}
