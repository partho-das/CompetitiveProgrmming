#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    while(scanf("%s", str) != EOF)
    {
        int i;
        for(i = 0; i < strlen(str); i++)
        {
            if(str[i] != 'm' && str[i] != 'a' && str[i] != 'r' && str[i] != 'z' && str[i] != 'i')
            {
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
