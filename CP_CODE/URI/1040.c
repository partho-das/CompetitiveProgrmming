#include<stdio.h>

int main()

{
    double N[5],avarage;

    int i ;

    for( i = 0 ; i < 4; i++ )
    {
        scanf("%lf",&N[i]);
    }

    avarage = ((N[0]*2) + N[1]*3 + N[2]*4 + N[3]*1)/(1+2+3+4);


    printf("Media: %.1lf\n",avarage);

    if (avarage >= 7.0)
    {
        printf("Aluno aprovado.\n");
    }
    else if(avarage < 5.0)
    {
        printf("Aluno reprovado.\n");
    }
    else if(5.0 <= avarage && 6.9 >= avarage)
    {
        printf("Aluno em exame.\n");
    }


    scanf("%lf",&N[4]);


    avarage = (avarage + N[4])/2;

    printf("Nota do exame: %.1lf\n",N[4]);

    if(avarage>= 5.0)
        printf("Aluno aprovado.\n");

    else if(avarage <= 4.9)
        printf("Aluno reprovado.\n");

        printf("Media final: %.1lf",avarage);

    return 0;
}
