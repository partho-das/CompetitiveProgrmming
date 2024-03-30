#include<stdio.h>

int main()
{
    char arr[10020];

    int i,j,ln = 0,test,ok = 0;
    scanf("%d%*c",&test);
    while(test--)
    {
    ln = 0,ok = 0;
    gets(arr);

    for(ln = 0;arr[ln];ln++);
    if(ln%2!=0)
        ok = 1;
    else
    {

    for(i =0,j = ln;i<j;i++,j--)
    {
        if(arr[i]=='{' ||arr[i]=='('||arr[i]=='['||arr[i]=='<')
            {


              if(arr[i] == '{'&& (arr[i+1] != '[' ||arr[i+1] != '<'))
                {
                    if(arr[j] == '}')
                    ok = 0;
                     else
                        ok = 1;
                }
                else  if(arr[i] == '('&& (arr[i+1] != '{' || arr[i+1] != '<'))
                {
                    if(arr[j] == ')')
                    ok = 0;
                    else
                        ok = 1;
                }
                else if(arr[i] == '['&& (arr[i+1] != '{' || arr[i+1] != '('))
                {
                    if(arr[j] == ']')
                    ok = 0;
                     else
                        ok = 1;
                }
                else if(arr[i] == '<'&& (arr[i+1] != '{' || arr[i+1] != '['|| arr[i+1] != '{'))
                {
                    if(arr[i+1] == '3')
                    ok = 0;
                     else
                        ok = 1;
                }

            }
            else
            {
                ok = 1;
                break;
            }
            if(ok != 0)
            {
            ok = 1;
            break;
            }

    }
    }
        for(i = 0;i<ln;i++)
        {
        if(arr[i] == '<')
                {
                    if(arr[i+1] == '3')
                    ok = 0,i++;
                     else
                        ok = 1;
                }

        }
    if(ok == 0)
            printf("Balanced <3\n");
    else printf("Not Balanced :'(\n");
    }


    return 0;
}
