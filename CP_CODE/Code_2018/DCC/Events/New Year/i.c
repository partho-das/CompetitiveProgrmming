#include<stdio.h>
#include<string.h>

int idx(char c){
    if('0'<=c&&c<='9') return c-'0';
    return 10+c-'A';
}
int hex2int(char *num, int i){
    int exp = 1,res = 0;
    while(i--) res += idx(num[i])*exp, exp *= 16;
    return res;
}
int main()
{
    int test;
    char num1[5],num2[5];
    scanf("%d",&test);
    while(test--){
        scanf("%s%s",num1,num2);

        int n1 = hex2int(num1,strlen(num1));
        int n2 = hex2int(num2,strlen(num2));

        printf("%d %d ",n1,n2);
        puts((n1==1 || n2==1) ? "Odd" : "Even");
    }
    return 0;
}
