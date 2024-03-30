#include<stdio.h>
#include<string.h>
int main()
{
    char mystr[100],justr[100],myc[100],ch;
    int test,i,x ,t = 0;
    scanf("%d%*c",&test);
    while(test--)
    {
        t++;
        x = 0;
        gets(mystr);
        gets(justr);
    if(!(strcmp(mystr,justr)))
        printf("Case %d: Yes\n",t);

    else
    {
    for(i = 0;mystr[i];i++)
    {
        if((mystr[i]>='a'&&mystr[i]<='z')||(mystr[i]>='A'&&mystr[i]<='Z'))
        {
            myc[x] = mystr[i];
            x++;
        }
            myc[x] ='\0';

    }
    if(!(strcmp(myc,justr)))
    printf("Case %d: Output Format Error\n",t);
    else
        printf("Case %d: Wrong Answer\n",t);
    }

}
    return 0;
}
