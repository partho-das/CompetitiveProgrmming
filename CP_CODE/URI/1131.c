#include<stdio.h>

int main()
{
    int inter,gremio,cnt=0,wini=0,wing=0,draw=0,t = 1;

    while(t!=2)
    {
        cnt++;
        scanf("%d%d",&inter,&gremio);
        if(inter>gremio)
            wini++;

        else if(inter<gremio)
            wing++;

        else if(inter==gremio)
            draw++;

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d",&t);
    }

    printf("%d grenais\n",cnt);
    printf("Inter:%d\n",wini);
    printf("Gremio:%d\n",wing);
    printf("Empates:%d\n",draw);
    if(wini>wing)
        printf("Inter venceu mais\n");
    else if(wini<wing)
        printf("Gremio venceu mais\n");
    else if(wini==wing)
        printf("Nao houve vencedor\n");
    return 0;
}
