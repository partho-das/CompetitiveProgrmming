#include<stdio.h>

int main()


{
    int score;

    scanf("%d",&score);
     if((score >= 90) && (score <= 100))
        printf("%d you get A grade\n",score);

    else if((score < 90) && (score >= 80))
        printf("%d you get B grade\n",score);
    else if((score < 80) && (score >= 70))
        printf("%d you get C grade\n",score);
    else if((score < 70) && (score >= 60))
        printf("%d you get D grade\n",score);
    else
        printf("%d you get a F grade\n",score);


    return 0;
}

