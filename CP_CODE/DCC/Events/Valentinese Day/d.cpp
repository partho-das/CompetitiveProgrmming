#include<stdio.h>
int main ()
{
   char arr[200],i,ln = 0;

    while(gets(arr))
    {
        ln = 0;


    for(i = 0;i<arr[i];i++)
        ln++;
    for(i = ln-1;i>=0;i--)
    printf("%c",arr[i]);

    printf("\n");
    }

return 0;
}
