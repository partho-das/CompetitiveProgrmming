#include <bits/stdc++.h>
using namespace std;

namespace KMP {
    const int maxn = 1e6+6;
    char txt[maxn],p[maxn];
    int fail[maxn],i,j;

    void fail_function(){
        fail[0] = fail[1] = 0;
        for(i = 1; p[i]; i++){
            j = fail[i];
            while(j && p[i] != p[j]) j = fail[j];
            fail[i+1] = j+(p[i] == p[j]);
        }
    }
    int solve(){
        fail_function();
        int cnt = 0;
        for(i = 0, j = 0; txt[i]; i++){
            while(j && txt[i] != p[j]) j = fail[j]; // j-1 = j as fail starts from 1
            j += txt[i] == p[j];
            cnt += !p[j];
        }
        return cnt;
    }
}

int main()
{
    return 0;
}