#include<stdio.h>
#include<math.h>
int main()
{
    int t,i,p1,p2;
    double g1,g2,x,y,res;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lf%lf",&p1,&p2,&g1,&g2);
        x = (1+g1)/(1+g2);
        y = (p2+p1-1)/p1;
        //res = log10(y)/log10(x);
        res = 0;
        printf("%lf %lf %lf\n", x, y, res);

//        if(re1<=100.0)  printf("%d anos.\n",ceil(re1));
//        else            printf("Mais de 1 seculo.\n");

    }
    return 0;
}
