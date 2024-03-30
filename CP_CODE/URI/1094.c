#include<stdio.h>

int main()
{
    int t= 1,n,frog = 0,rat = 0,rabbit = 0,i = 1;
    float a,b,c;
    char name;
    scanf("%d",&t);
    for( i = 1; i <= t;i++)
    {
        scanf("%d %c",&n,&name);
        switch(name)
        {
        case 'C':
             rabbit += n;
             break;
        case 'R':
            rat += n;
            break;
        case 'S':
            frog += n;
            break;
        }
    }

    a = (float)(rabbit*100)/(rabbit+rat+frog);
    b = (float)(rat*100)/(rabbit+rat+frog);
    c = (float)(frog*100)/(rabbit+rat+frog);
    printf("Total: %d cobaias\n",(rat+rabbit+frog));

    printf("Total de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\n",rabbit,rat,frog);

    printf("Percentual de coelhos: %.2f %%\nPercentual de ratos: %.2f %%\nPercentual de sapos: %.2f %%\n",a,b,c);
    return 0;
}
