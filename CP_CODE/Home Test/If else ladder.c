#include<stdio.h>
int main()

{
    int mark;
    scanf("%d",&mark);
        if (mark >= 80) printf("A+");
        else if (mark >= 75) printf("A");
        else if (mark >= 65) printf("A-");
        else if (mark >= 60) printf("B+");
        else if (mark >= 55) printf("B");
        else if (mark >= 50) printf("B-");
        else if (mark >= 45) printf("C+");
        else if (mark >= 40) printf("C");

        else printf("Faill");

    return 0;
}
