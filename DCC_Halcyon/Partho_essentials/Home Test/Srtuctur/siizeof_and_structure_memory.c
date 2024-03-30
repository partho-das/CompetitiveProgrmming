#include<stdio.h>

struct mystructer
{
    int a;
    double bd;
    float b;/// variable dicler takes the multipal size of big data type;
    char c;
};
int main()
{
    struct mystructer obj;

    printf("%d",sizeof(obj));


    return 0;
}
