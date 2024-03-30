/// count char in a strung.
/**
    input       output

    sharif a      1
    sharif z      0

    till EOF

*/

#include<stdio.h>
int cont(char *arr,char c)
{
    int i = 0,cnt  = 0;
    for(i = 0;arr[i];i++)
    {
        if(arr[i] ==  c)
            cnt++;
    }
    return cnt;
}

int main()
{
    char str[100],ch;

    int cnt  = 0;

    while(scanf("%s%*c",str) !=EOF) /// while(scanf("%s%*c",str) == 1)
    {                               /// while(scanf("%s %c",str) !=EOF) /// all are same for the test given test cases...
                                    /// while(scanf("%s %c",str) == 2)
    scanf("%c",&ch);

    cnt = cont(str,ch);

    printf("%d",cnt);
    }

    return 0;
}
