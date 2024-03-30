#include<stdio.h>

int main()
{
    double n;

    scanf("%lf",&n);
    if(n<0 || n>100)
    {
        printf("Fora de intervalo\n");
    }

   else if( 0<=n && 25 >= n){
    printf("Intervalo [0,25]\n");
   }
   else if(25<n && 50>= n){
    printf("Intervalo (25,50]\n");
   }
   else if(50<n &&75>= n){
    printf("Intervalo (50,75]\n");
   }
   else if(75<n && 100>= n){
    printf("Intervalo (75,100]\n");
   }
    return 0;
}
