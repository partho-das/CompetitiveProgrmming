#include<stdio.h>

int main()
{
    int t,i,p1,p2;
    double g1,g2;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lf%lf",&p1,&p2,&g1,&g2);
        g1 /= 100.0, g1 += 1;
        g2 /= 100.0, g2 += 1;
        int done = 0;
        for(int y = 1; y <= 100; y++){
            p1 *= g1;
            p2 *= g2;
            if(p1 > p2){
                printf("%d anos.\n", y);
                done = 1;
                break;
            }
        }
        if(!done) puts("Mais de 1 seculo.");
    }


    return 0;
}

