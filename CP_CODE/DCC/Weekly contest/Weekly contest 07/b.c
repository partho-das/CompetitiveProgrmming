#include<stdio.h>
#include<string.h>

int main()
{
    char arr[1000];
    int ln,i,j,val =0;

    while (gets(arr))
    {
        ln = strlen(arr);


        for(i = 0;i<ln;i++)
        {
            if((arr[i]==' ')|| (i == (ln-1)))
            {
                if(arr[i]==' ')
                    val = i-1;
                else
                    val = i;

                for(j=val; j>=0 ;j--)
                {
                    if(arr[j] ==' ')
                        break;
                 printf("%c",arr[j]);
                }
                if(i !=(ln -1))
                printf(" ");
            }
        }
        printf("\n");
    }


    return 0;
}
