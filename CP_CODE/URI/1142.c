#include<stdio.h>

int main()
{
    int num,i,is=1,end1,start, ie=3;
    scanf("%d",&end1);
    start = 1;
    while(start<=end1)

        for(i = is ; i<=ie;i++)
        {
            printf("%d ",i);
        }
        printf("PUM\n");
        is = 4+is;
        ie = 4+ie;
        start++;
    }
    return 0;
}
