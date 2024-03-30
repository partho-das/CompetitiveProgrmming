#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *str;

    str = (char *)calloc(6,sizeof(char));
    strcpy(str,"abcde");
    printf("%s\n",str);

    free(str);
    str = (char *)realloc(str,3*1);
    printf("%s",str);
    return 0;
}
