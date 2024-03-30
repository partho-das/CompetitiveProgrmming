#include<stdio.h>

int value(int x)
{
    int st, end, key;
        int j, arr[500]={0},i;
        for(j = 1; j<=x; j++ )
    {


        scanf("%d%d%d",&st,&end,&key);
        if(key>500){
            for(i = 0;i<350;i++)
        {
            printf("%d",arr[i]);

        }
         return 0;
        }

        for(i = st;i <= end;i++ )
        {
        arr[100+i] = arr[i+100] + key;
        }

    }

}
int main()
{
    int x;
    scanf("%d",&x);

    value(x);


    return 0;
}
