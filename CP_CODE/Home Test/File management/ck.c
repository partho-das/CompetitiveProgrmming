#include<stdio.h>

int main()
{
    FILE *fac, *ck;
    int a,b;

    fac = fopen("acoutput.txt","r");
    ck = fopen("output.txt","r");

   while(fscanf(fac,"%d",&a)!= EOF)
    {
        fscanf(ck,"%d",&b);
        if(a!=b)
        {
        printf("Wrong ans\n");
            return 0;
        }
    }
    printf("Accepted\n");

    fclose(ck);
    fclose(fac);



    return 0;
}
