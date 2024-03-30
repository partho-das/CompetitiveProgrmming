#include<stdio.h>
int main()
{
char sen[100000],cpy[100000];
int x,i,done = 0,t,now = 0,hi = 0,xc = 0;

while(1)
{
x = 0;
done = 0;

gets(sen);
if(sen[0]=='D'&&sen[1]=='O'&&sen[2]=='N'&&sen[3]=='E'&&sen[4]=='\0')
break;


for(i = 0; sen[i]; i++)
{
   if( (sen[i] >= 'A' && sen[i] <= 'Z') ||  (sen[i] >= 'a' && sen[i] <= 'z'))
    {
        cpy[x]=sen[i];
        x++;
        xc = x;
    }

}

     x--;

    hi = xc/2;

for(i = 0;i<=x; i++)
{

    if(done==hi)
        break;

        t = (x-i);

        now = (cpy[i]-cpy[t]);



        if(now==32||now ==-32||now==0)
        {
            done ++;
        }

        else
        {
            done = 0;
             printf("Uh oh..\n");
            break;
        }

}
    if(done==hi)
    printf("You won\'t be eaten!\n");

}

return 0;
}
