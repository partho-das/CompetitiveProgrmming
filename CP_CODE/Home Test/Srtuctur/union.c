#include<stdio.h>

struct mystructer
{
    double a;
    int b;
    char c;
};

union myunion
{
    double a;
    int b;
    char c;
};


int main()
{
    union myunion ob;



     ob.a = 78.4545654; ob.c = 'a'; ob.b = 3;
    printf("double = %lf\n",ob.a);
    printf(" int = %d\n",ob.b);
    printf("char = %c\n",ob.c);




    return 0;
}
