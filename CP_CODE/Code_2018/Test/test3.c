#include<stdio.h>

int idx(char c){
    if('0'<=c&&c<='9') return c-'0';
    return 10+c-'A';
}
int main()
{
    char i;

    for(i = '0';i<='9';i++) printf("%d = %c\n",idx(i),i);
    for(i = 'A';i<='Z';i++) printf("%d = %c\n",idx(i),i);


    return 0;
}
