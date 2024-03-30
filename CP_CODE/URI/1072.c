#include<stdio.h>

int main()

{
    int n,nu[100000],s = 0,so = 0 ,i;

    scanf("%d",&n);

    for(i = 0; i < n ; i++)
    {
        scanf("%d",&nu[i]);
        if( nu[i]>=10 && nu[i]<=20)
        s++;
        else
        so++;

    }
    printf("%d in\n",s);
    printf("%d out\n",so);

    return 0;
}
