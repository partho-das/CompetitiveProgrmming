#include<stdio.h>

int main() {
   


    int n;
    scanf("%d", n);

    int now = 1, state = 1;

    for(int i = 0; i < n; i++){
        int cmd;
        scanf("%d", cmd);
        if(cmd == 1) state ^= 1;
        else if(cmd == 11) now = (now % 10) + 1;
        else now = (now % 10) + 1, state ^= 1;
    }

    printf("%d %c\n", now, state == 1 ? 'D' : 'H');

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

