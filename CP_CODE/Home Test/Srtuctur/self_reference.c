#include<stdio.h>

struct self_ref{

    int a;
    float b;

    struct self_ref *next;
};
void pri(struct self_ref pr)
{
     if(pr.a==0)
        return;
        printf("%d ",pr.a);
     pri(*pr.next);

}

int main()
{
    struct self_ref var1;
    struct self_ref var2;
    struct self_ref *var3;
    struct self_ref var4;

    var1.a = 5;
    var3->next = &var2;
    var1.next = var3;
    var2.a = 8;
    var2.next = &var4;
    var3->next = &var2;
    var3->a = 10;
    var4.a = 0;
printf("%d %d",var3->next,&var2);
   /// pri(var1);

    return 0;
}
