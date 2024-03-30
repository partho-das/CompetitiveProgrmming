#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isprime[50];
bool takeen[20];
int output[30], n;

inline void generatePrime(){
    int ck  = 0;
    for(int i = 2; i <= 35; i++){
        ck = 0;
        for(int j = 2;j < i; j++){
            if(i%j == 0){ ck = 1; break; }
        }
        if(!ck) isprime[i] = 1;
    }
}

inline void solve(){
    if(!isprime[1 + output[n-1]]) return;
    for(int i = 0; i < n-1; i++) printf("%d ", output[i]);
    printf("%d\n", output[n-1]);
}
void backtrack(int pos = 1){
    if(pos >= n){
        solve();
        return;
    }
    for(int i = 2; i <= n; i++) if(!takeen[i] && isprime[ output[pos-1] + i]){
        takeen[i] = 1;
        output[pos] = i;
        backtrack(pos+1);
        takeen[i] = 0;
    }
}

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    generatePrime();
    isprime[1] = 1;
    output[0] = 1;
        
    int Case = 0,cnt = 0;
    while(scanf("%d",&n) == 1){
        if(Case) putchar('\n');

        printf("Case %d:\n",++Case);
        backtrack();
    }
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}