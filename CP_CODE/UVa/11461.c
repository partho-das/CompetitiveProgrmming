#include<stdio.h>
#include<math.h>
int main()
{

    int a,b,ck = 0,cnt= 0;
    float ckf = 0;

    while(1)
    {
        cnt= 0;
    scanf("%d%d",&a,&b);
    if(a==0&&b==0)
        break;
    int i;
    for(i = a;i<=b;i++)
    {
        ck = sqrt(i);
        ckf = sqrt(i);

        if((ckf-ck)==0)
            cnt++;
    }

    printf("%d\n",cnt);
    }

    return 0;
}
