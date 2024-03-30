#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i, j;
    scanf("%d", &n);
    char products[n][50], tag[n][50];
    for(i = 0; i < n; i++)
    {
        scanf("%s", products[i]);
        scanf("%s", tag[i]);
        fflush(stdin);
    }
    scanf("%d", &m);
    char mtag[m][50];
    for(i = 0; i < m; i++) scanf("%s", mtag[i]);
    for(i = 0; i < m; i++)
    {
        int cmma = 0;
        for(j = 0; j < n; j++)
        {
            if(strcmp(mtag[i], tag[j]) == 0)
            {
                if(cmma != 0) printf(",");
                printf("%s", products[j]);
                cmma = 1;
            }
        }
        if(cmma == 1 && j == n) printf("\n");
        if(j == n && cmma == 0) printf("Sorry the product is not available :(\n");
    }
    return 0;
}
