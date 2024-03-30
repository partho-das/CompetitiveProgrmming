#include<bits/stdc++.h>

using namespace std;

int main(){

char T[1000], P[1000];

scanf("%s%s", T, P);


int Tlen = strlen(T), Plen = strlen(P), K = - 1;


for(int i = 0; i < Tlen - Plen + 1; i++){

    int ck = 0;
    for(int j = i; j < Plen; j++){
        if( T[j] != P[j - i]){
            ck = 1;
            break;
        }
    }

    if(ck == 0){
    K = i + 1;
    break;
    }

}

if(K != -1)
printf("Found in pos : %d \n", K);
else puts("Not Found");


return 0;
}
