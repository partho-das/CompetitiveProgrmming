#include<stdio.h>
#define bitFlip(n,pos)  (n^(1LL<<pos))
#define dbg(x) printf("%s = %c\n",#x,x)

int main()
{
    char ch[5];

    while(1){
        scanf("%s",ch);
        printf("%c\n",bitFlip(ch[0],5));
    }

    return 0;
}
