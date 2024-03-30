// string reverse

#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    int i;
    scanf("%s",str);


    int len  = strlen(str);

    printf("The reverse mood of %s = ",str);
    for(i = len-1;i>=0;i--)
        printf("%c",str[i]);

    return 0;
}
