#include<stdio.h>

struct structure
{
    int x;
    float y;

};

void print(struct structure pr)
{
    printf("x = %d \n",pr.x);
    printf("y = %.2f \n",pr.y);
    return;
}

struct structure add(struct structure a,struct structure b)
{
    struct structure result;
    result.x = a.x+b.x;
    result.y = a.y+b.y;

    return result;

};

int main()
{
   // freopen("C:\\Users\\parth\\OneDrive\\Code\\IO\\input.text","r",stdin);
    //freopen("C:\\Users\\parth\\OneDrive\\Code\\IO\\output.text","w",stdout);

    struct structure mem,mem1,sum;
    printf("Before assingn : \n");
    mem.x = 5;
    mem.y = 6.6;
    print(mem);
    print(mem1);
    mem1 = mem;
     printf("After assingn : \n");
    print(mem);
    print(mem1);
    printf("sum :");
    sum = add(mem,mem1);
    print(sum);

    return 0;
}
