#include<stdio.h>
#include<string.h>

int main()
{
    int money,test,sum = 0;
    char arr[10];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        if(!(strcmp(arr,"donate")))
        {
        scanf("%d%*c",&money);
        sum+=money;
        }
        else
        printf("%d\n",sum);
    }

        return 0;
}
