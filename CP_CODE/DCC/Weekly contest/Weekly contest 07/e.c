#include<stdio.h>
#include<string.h>

int main()
{
    char arr[1000];
    int ln,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);

        ln = strlen(arr);

        if(ln>10)
        {
            printf("%c%d%c\n",arr[0],ln-2,arr[ln-1]);
        }
        else
            puts(arr);

    }

    return 0;
}
