#include<stdio.h>

int main()
{
    int n[7],i,se,so,sn,sp;

    se = so = sp = sn = 0;

    for(i = 0;i < 5; i++)
    {
        scanf("%d",&n[i]);

        if(n[i]%2 == 0 )
            se++;
        else
            so++;
        if(n[i] < 0)
            sn++;
       else if(n[i]>0)
            sp++;
    }
    printf("%d valor(es) par(es)\n",se);
    printf("%d valor(es) impar(es)\n",so);
    printf("%d valor(es) positivo(s)\n",sp);
    printf("%d valor(es) negativo(s)\n",sn);

    return 0;
}
