#include<stdio.h>

int main()
{
    int oil = 8,alc = 0,gas = 0 ,dis = 0;

    while(oil!=4)
    {
        scanf("%d",&oil);

        if(oil==1)
            alc++;
        else if(oil==2)
        gas++;
        else if(oil == 3)
            dis++;
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n",alc);
    printf("Gasolina: %d\n",gas);
    printf("Diesel: %d\n",dis);


    return 0;
}
