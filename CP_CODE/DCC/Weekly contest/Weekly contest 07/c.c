#include<stdio.h>
int main()
{
    char arr[10000];
    int ln,cnt = 0,val = 0,i,j;

    scanf("%s",arr);

    scanf("%d",&cnt);

   for(ln = 0;arr[ln];ln++);

   if(ln%cnt!=0)
   {
        puts("NO");
        return 0;
   }
   cnt = ln/cnt;


    while(val<ln)
    {
        for(i = val,j=(val+cnt-1);i<j;)
        {
            if(arr[i++]!=arr[j--])
                {
                    printf("NO\n");
                    return 0;
                }
        }
        val+=cnt;
    }
    printf("YES\n");

    return 0;
}
