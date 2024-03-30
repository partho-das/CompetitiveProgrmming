#include< bits/stdc++.h>
using namespace std;

inline int LIS(vector<int> &v){ // nLogn
    int ln = v.size(), mx = 0;
    vector<int> L(ln), lis(ln+2,inf);
    lis[0] = -lis[0];
    for(int i = 0; i < ln; i++){
        L[i] = lower_bound(all(lis), v[i]) - lis.begin();
        lis[ L[i] ] = min(lis[ L[i] ], v[i]);
        mx = max(mx, L[i]);
    }
    return mx;
}

int main(){
	return 0;
}