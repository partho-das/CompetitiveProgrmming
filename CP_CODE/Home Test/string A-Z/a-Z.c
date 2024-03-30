#include<stdio.h>
#include<string.h>
//#include<strtoke
void only_a2z(char *s){
    int i,n = 0;
    char cpy[1000];
    for(i = 0;s[i];i++) if('a'<=s[i]&& s[i]<='z' || 'A'<=s[i]&& s[i]<='Z') cpy[n++] = s[i];
    s[n] = '\0';
    while(n--) s[n] = cpy[n];
}
