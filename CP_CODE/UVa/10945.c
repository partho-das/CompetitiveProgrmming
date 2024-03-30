#include<stdio.h>
#include<string.h>

void only_a2z(char *s){
    int i,n = 0;
    char cpy[1000];
    for(i = 0;s[i];i++) if('a'<=s[i]&& s[i]<='z' || 'A'<=s[i]&& s[i]<='Z') cpy[n++] = s[i];
    s[n] = '\0';
    while(n--) s[n] = cpy[n];
}

int isPalindrome(char *s){
    int i = 0,j = strlen(s)-1;
    while(i <= j) if(s[i++] != s[j--]) return 0;
    return 1;
}
void to_lower(char *s){
    int i =0;
    while(s[i]) s[i++] |= 1<<5;
}
int main()
{
    char arr[1000];
    while(1){
        scanf("%[^\n]",arr), getchar();
        if(!(strcmp(arr,"DONE"))) return 0;

        only_a2z(arr);
        to_lower(arr);
        puts( isPalindrome(arr) ? "You won't be eaten!" : "Uh oh..");
    }

    return 0;
}
