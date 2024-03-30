#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
struct fenwick{
    int n, tree[MAX];

    fenwick(){}
    fenwick(int m){
        n = m;
        for (int i = 1; i <= n; i++) tree[i] = 0;
    }
    inline void update(int pos, int value) {
        while (pos <= n) tree[pos] += value, pos += pos&(-pos);
    }
    inline int query(int pos){
        int res = 0;
        while (pos) res += tree[pos], pos ^= pos&(-pos);
        return res;
    }
    inline int query(int l, int r){
        if (l > r) return 0;
        return (query(r) - query(--l));
    }
}
