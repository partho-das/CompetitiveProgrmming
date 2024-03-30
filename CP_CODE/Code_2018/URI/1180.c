#include<stdio.h>

int main()
{
    int arr[1200],i,n,value = 100000000,pos =  0;

    scanf("%d",&n);

    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        if(value>=arr[i])
        {
            value = arr[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\n",value);
    printf("Posicao: %d\n",pos);


    return 0;
}
