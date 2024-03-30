#include<stdio.h>

int main()
{
    freopen("C:\\Users\\parth\\OneDrive\\Desktop\\input.txt","r",stdin);
    int h1, h2, m1, m2,h, rh, rm;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d%d",&h1,&m1,&h2,&m2,&rh,&rm);
        if(h1>=h2)  h = h2 - h1 + 24;
        else        h = h2 - h1;

        if( m1 > m2 )   m2 = m2 - m1 + 60, --h;
        else            m2 = m2 - m1;

        if(m2 == 60) {
            ++h2;
            m2 -=60;
        }
        if(((h2+24) - h1) < 0) {
            m2 = m2 - 60;
            ++h;
        }
        ///printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",h,m2);
        if(h != rh || m2 != rm){
            printf("%d %d - %d %d :: %d %d\n",h1,m1,h2,m2,rh,rm);
            printf("WA :: %d %d\n\n",h,m2);
            //break;
        }
    }
    return 0;
}
