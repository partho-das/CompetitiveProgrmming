#include<stdio.h>
 char arr[100][100],cpy[100];
 int i,j,k,ina[100],x = 0,roll[20];
 float cgpa[20],ex;
int cmpp(char *a, char *b){ /// return a == b ? 0 : (a > b ? 1 : -1);
    int i = 0, j = 0;
    while(a[i] && b[i] && a[i]==b[i]) i++,j++;

    if(a[i] < b[i]) return -1;
    if(a[i] > b[i]) return 1;
    return 0;
}

void cppy(char *a,char *b){ /// a = b
    int i;
    for(i = 0; b[i]; i++) a[i] = b[i];
    a[i] = '\0';
}
 void name()
{

    for(i = 0;i<10;i++)
    {
        for(j = i;j<10;j++)
        {
            k = cmpp(arr[i],arr[j]);

            if(k>0)
            {
            cppy(cpy,arr[i]);
            cppy(arr[i],arr[j]);
            cppy(arr[j],cpy);

            x = ina[i];
            ina[i] = ina[j];
            ina[j] = x;
            }

        }
    }
    for(i = 0;i<10;i++)
    {
        x = ina[i];
        printf("%s %d %.2f\n",arr[i],roll[x],cgpa[x]);

    }


}
void rolll()
{
     for(i = 0;i<10;i++)
    {
        for(j = i;j<10;j++)
        {
            if(roll[i]>arr[j])
            {
                x = roll[i];
                roll[i] = roll[j];
                roll[j] = x;

            x = ina[i];
            ina[i] = ina[j];
            ina[j] = x;
            }

        }
    }
    for(i = 0;i<10;i++)
    {
        x = ina[i];
        printf("%d %s %.2f\n",roll[i],arr[x],cgpa[x]);

    }
}
void cgpaa()
{
     for(i = 0;i<10;i++)
    {
        for(j = i;j<10;j++)
        {
            if(cgpa[i]>cgpa[j])
            {
                ex = cgpa[i];
                cgpa[i] = cgpa[j];
                cgpa[j] = ex;

            x = ina[i];
            ina[i] = ina[j];
            ina[j] = x;
            }

        }
    }
    for(i = 0;i<10;i++)
    {
        x = ina[i];
        printf("%.2f %d %s\n",cgpa[i],roll[x],arr[x]);

    }
}


int main()
{
   for(i = 0;i<10;i++)
    {
        gets(arr[i]);
        scanf("%d%f%*c",&roll[i],&cgpa[i]);
        ina[i] = i;
    }
   cgpaa();
    return 0;

}
