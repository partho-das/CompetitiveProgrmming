#include <bits/stdc++.h>
using namespace std;
//____________________________________________________________________________________________________________________________________
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc1(n)         sc("%d",&n)
#define sc2(n, m)      sc("%d%d", &n, &m)
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o)
#define scl(n)         sc("%lld", &n)
#define scll(n, m)     sc("%lld%lld", &n, &m)
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o)
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
template <class T> inline string to_string(const pair<T,T> &p) {
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";  
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________


struct QTREE {
    struct edge {
        int id, d, w;
        edge() {}
        edge(int _id, int _d, int _w) {
            id = _id, d = _d, w = _w;
        }
    };

    int n, chainindx = 1, dtime = 1;
    const int MAX = 14;
    vector<vector<int>> par;
    vector< vector<edge> >adj;
    vector<int> sz, chainhead, seg, depth, pos, arr, edge_pos;

    void init() {
        sc1(n);

        par.resize(n + 1, vector<int>(15, 0) );
        adj.resize(n + 1);
        chainhead = vi(n + 1, -1);
        edge_pos = arr = pos = depth = sz = vi(n + 1, 0);
        seg = vi(4 * n + 5, -inf);

        for(int i = 0; i < n - 1; i++) {
            int a, b, c;
            sc3(a, b, c);
            adj[a].pb(edge(i + 1, b, c));
            adj[b].pb(edge(i + 1, a, c));
        }

        dfs(1, 0, 0);
        HLD(1, 0, 1);
        segment_tree_build(1, 1, n);
    }

    int dfs(int vertex, int parent, int dpth) {
        par[vertex][0] = parent;
        depth[vertex] = dpth;

        for(int i = 1; i <= MAX; i++) {
            if(par[vertex][i - 1] != 0) {
                par[vertex][i] = par[ par[vertex][i - 1] ][i - 1];
            }
        }
        sz[vertex] = 1;
        for(auto child : adj[vertex]) {
            if(child.d != parent) {
                sz[vertex] += dfs(child.d, vertex, dpth + 1);
            }
        }
        return sz[vertex];
    }

    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u], bit = 0;
        while(diff) {
            if(diff & 1) {
                v = par[v][bit];
            }
            bit++;
            diff /= 2;
        }
        int LCA = 0;
        for(int i = MAX; i >= 0; i--) {
            if(u == v){
                LCA = u;
                break;
            }
            if(par[u][i] != par[v][i]) {
                u = par[u][i], v = par[v][i];
            }
            else LCA = par[u][i];
        }
        return LCA;
    }


    void HLD(int vertex, int parent, int head) {
        pos[vertex] = dtime++;
        chainhead[vertex] = head;

        int mx = -inf, havy = -1, eid = -1, w = -1;
        for(auto child : adj[vertex]){
            if(child.d != parent && mx < sz[child.d]){
                mx = sz[child.d];
                havy = child.d;
                eid = child.id;
                w = child.w;
            }
        }

       
        if(havy != -1){
            arr[dtime] = w;
            edge_pos[eid] = dtime;
            HLD(havy, vertex, head); 
            
            for(auto child : adj[vertex]){
                if(child.d != parent && child.d != havy) { 
                    arr[dtime] = child.w;
                    edge_pos[child.id] = dtime;
                    HLD(child.d, vertex, child.d);
                }
                
            }
        }
    }

   void segment_tree_build(int indx, int l, int r) {
        if(l == r){
            seg[indx] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        segment_tree_build(indx << 1, l, mid);
        segment_tree_build( (indx << 1) + 1, mid + 1, r);
        seg[indx] = max(seg[indx << 1], seg[(indx << 1) + 1]); 
        return;
    }

   void segment_tree_update(int indx, int l, int r, int i) {
        if(l > r || i < l || i > r) return;

        if(l == r && l == i){
            seg[indx] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;

        segment_tree_update(indx << 1, l, mid, i);
        segment_tree_update( (indx << 1) + 1, mid + 1, r, i);
        seg[indx] = max(seg[indx << 1], seg[(indx << 1) + 1]); 
        return;
    }
    int segment_tree_query(int indx, int l, int r, int i, int j) {
        if(l > r || j < l || i > r) return -inf;

        if(i <= l && r <= j){
            return seg[indx];
        }
        int mid = l + (r - l) / 2;
            
        int a = segment_tree_query(indx << 1, l, mid, i, j);
        int b = segment_tree_query( (indx << 1) + 1, mid + 1, r, i, j);
        return max(a, b); 

    }
char S[20];
   void solve() {
        init();
        string str;
        while(1){
            getchar();
            scanf("%s", S);
            str = S;
            if(str == "DONE") break;
            else if(str == "QUERY") {
                int a, b;
                sc2(a, b);
                int LCA = lca(a, b);
                int res = 0;
                while(chainhead[a] != chainhead[LCA]) {
                    res = max(res, segment_tree_query(1, 1, n, pos[chainhead[a]], pos[a]));
                    a = par[chainhead[a]][0];
                }
                res = max(res, segment_tree_query(1, 1, n, pos[LCA] + 1, pos[a]));

                while(chainhead[b] != chainhead[LCA]) {
                    res = max(res, segment_tree_query(1, 1, n, pos[chainhead[b]], pos[b]));
                    b = par[chainhead[b]][0];
                }
                res = max(res, segment_tree_query(1, 1, n, pos[LCA] + 1, pos[b]));

                printf("%d\n", res);
            }
            else {
                int id, w;
                sc2(id, w);
                arr[edge_pos[id]] = w;
                segment_tree_update(1, 1, n, edge_pos[id]);
            }
        }
        return;
    }

};
void solve() {
    QTREE s1;
    s1.solve();
}


int main() {
    #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    sc1(test);

    while(test--) {
        solve();
    }
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
