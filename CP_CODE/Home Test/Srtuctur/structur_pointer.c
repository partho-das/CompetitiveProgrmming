#include<stdio.h>
#include<string.h>

struct structure
{
    char name[12];
    int value;
};

void swp(struct structure *a,struct structure *b)
{
    struct structure temp;

    strcpy(temp.name,a->name);
    temp.value = a->value;

    strcpy(a->name,b->name);
    a->value = b->value;

    strcpy(b->name,temp.name);
    b->value = temp.value;



}

int main(void)
{
    struct structure val1;
    struct structure val2;
    printf("Enter The name and value of val1 :");
    scanf("%s%d",val1.name,&val1.value);
    printf("\nEnter The name and value of val2 :");
    scanf("%s%d",val2.name,&val2.value);

    if(val2.value>val1.value)
        swp(&val1,&val2);

    printf("Val1 (%d) %s \n",val1.value,val1.name);
    printf("Val2 (%d) %s \n",val2.value,val2.name);






    return 0;
}
