#include<stdio.h>

int main()
{
    char sen[1000];
    int i,cnt = 0,done = 0,t,now = 0;

    while(1)
    {
        done = 0;
        cnt = 0;
        gets(sen);
        if(sen[0]=='D'||sen[1]=='O'||sen[2]=='N'||sen[3]=='E')
            return 0;

    for(i = 0;sen[i];i++)
    {
        cnt++;
    }
    if(sen[cnt-1] == ' ')
            cnt --;


    for(i = 0;i<cnt;i++)
    {
        t = (cnt-i-1);
        if(done==2)
            break;

        if(sen[cnt-1] == '.'||sen[cnt-1] == ','||sen[cnt-1] == '?'||sen[cnt-1] == '!'||sen[cnt-1] == ' ')
        {

            t= t - 1;
           if(sen[i]!=' '||sen[i]!=','||sen[i]!='.')
            {
                now = (sen[i]-sen[t]);

                if(now==32||now ==-32||now==0)
                done ++;
                 else
                {
                    done = 0;
                break;
                }

            }
            else
                break;
        }
        else
            if(sen[i]!=' '||sen[i]!=','||sen[i]!='.')
            {
                now = (sen[i]-sen[t]);
                if(now==32||now ==-32||now==0)
                 done ++;
                else
                {
                    done = 0;
                break;
                }
            }
            else
                break;
    }

        if(done==2)
         printf("You won't be eaten!\n");
        else
        printf("Uh oh..\n");

    }

    return 0;
}
