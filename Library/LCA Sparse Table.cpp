
int lev[maxn],par[maxn],dis[maxn],sparse[maxn][16],sparse_mx[maxn][16],n,m;

void Build(){
    CLR(sparse,-1);
    CLR(sparse_mx,0);
    FOR(i,0,n) sparse[i][0] = par[i], sparse_mx[i][0] = dis[i];
    for(int j = 1; (1<<j) < n; j++){
        FOR(i,0,n){
            if(~sparse[i][j-1]){
                sparse[i][j] = sparse[ sparse[i][j-1] ][j-1];
                sparse_mx[i][j] = max(sparse_mx[ sparse[i][j-1] ][j-1], sparse_mx[i][j-1]);
            }
        }
    }
}
int Query(int p, int q){
    if(lev[p] < lev[q]) swap(p,q);
    int log = 0;
    while(1LL<<(log+1) <= lev[p]) log++;

    int mx = 0;
    for(int i = log; i >= 0; i--){
        if(lev[p]-(1<<i) >= lev[q]){
            mx = max(mx, sparse_mx[p][i]);
            p = sparse[p][i];
        }
    }
    if(p == q) return mx;

    for(int i = log; i >= 0; i--){
        if(~sparse[p][i] && sparse[p][i] != sparse[q][i]){
            mx = max(mx, sparse_mx[p][i]);
            mx = max(mx, sparse_mx[q][i]);
            p = sparse[p][i];
            q = sparse[q][i];
        }
    }
    mx = max({mx, sparse_mx[p][0], sparse_mx[q][0]});
    return mx;
}