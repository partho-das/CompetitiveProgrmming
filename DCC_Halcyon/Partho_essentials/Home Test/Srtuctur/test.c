#include<conio.h>
#include<stdio.h>

void pass_gen(char *pass)
{
    int i  = 0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch==13)
            break;
        putchar('*');
        pass[i++] = ch;
    }
    pass[i] = '\0';
}

int main()
{
    char password[50];
    pass_gen(password);
    printf("%s",password);

    return 0;
}
