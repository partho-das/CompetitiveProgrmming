#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool prime[50];
bool takeen[20];
int output[30], n;

inline void solve(){
    for(int i = 0; i < n; i++) cout << output[i] << " "; cout << endl;
}
void backtrack(int pos = 0){
    if(pos >= n){
        solve();
        return;
    }
    for(int i = 1; i <= n; i++) if(!takeen[i]){
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
    
    n = 4;
    backtrack();
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}