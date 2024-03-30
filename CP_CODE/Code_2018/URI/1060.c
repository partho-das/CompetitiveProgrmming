#include<stdio.h>

int main()

{
    double a[7];
    int s = 0,i;
    for(i = 0; i < 6; i++ )
    {
        scanf("%lf",&a[i]);
        if(a[i]>0){
            s++;
        }
    }
    printf("%d valores positivos\n",s);
    return 0;
}
