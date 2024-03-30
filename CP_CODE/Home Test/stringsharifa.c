#include<stdio.h>

void get_line(char *ch){
    scanf("%[^\n]",ch);
    getchar();
}

int isEmpty(char *ch){
 return ch[0] == '\0';

}
void fillall(char *ch)
{
    int i = 0;

    for(i = 0; i<50000; i++)
    {
        ch[i] = '\0';
    }
}

int main()

{
    char a[50000],b[56525];

    while(1)
{

    fillall(a);

    get_line(a);

    if(isEmpty(a))
        break;
        printf("%s\n",a);

}


    return 0;
}
