#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    int i,sq,cnt = 0;


    scanf("%d%d",&a,&b);

    if(a==0&&b==0)
        return 0;

    for(i = a;i<=b;i++)
    {
        sq = sqrt(i);

        if((sq*sq==i))
            cnt++;
    }
    printf("%d\n",cnt);

    main();

}
