#include<stdio.h>

#define PI 3.1416
#define pf printf
#define pfi(a) printf("%d\n",a);
#define max(a,b) (a>b) ? (a) : (b)
#define add(a,b) (a+b)
#define  FOR(ind,a,b) for(ind=a;ind<b;ind++)


int main()
{
    int j;
   // printf("%d\n",sizeof(PI));
    //pf("%f",PI);

    FOR(j,1,10){
        pfi(j);
    }


    return 0;
}
