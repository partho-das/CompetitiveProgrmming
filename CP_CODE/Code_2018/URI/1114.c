#include<stdio.h>

int main()
{
    int pass;
    while(1)
    {
    scanf("%d",&pass);
    if(pass == 2002)
    {
        printf("Acesso Permitido\n");
        return 0;
    }
    else
    {
    printf("Senha Invalida\n");

    }

    }
    return 0;
}
