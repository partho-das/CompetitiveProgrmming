/// Grading system
#include<stdio.h>

int main()

{
    int grade, score;

    scanf("%d",&score);

    grade = score/10;
    switch ( grade )
{
    case  10:
    case  9:
    case  8:
        printf("Your grade is A+");
         break;
    case  7:
        printf("Your grade is A");
        break;
    case  6:
        printf("Your grade is A-");
        break;
    case  5:
        printf("Your grade is B");
        break;
    case  4:
        printf("Your grade is C");
        break;
    default :
        printf("Your grade is F.");
        break;

}
    return 0;
}
