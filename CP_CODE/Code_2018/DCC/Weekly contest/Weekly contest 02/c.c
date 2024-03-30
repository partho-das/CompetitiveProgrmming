#include<stdio.h>

int main()
{

    int n,p,q,i,def,cnt=0;


    scanf("%d",&n);

    for(i = 1; i<=n;i++)
    {
        scanf("%d%d",&p,&q);

        def=q-p;
        if(def>=2)
            cnt++;
    }

    printf("%d\n",cnt);


    return 0;
}
