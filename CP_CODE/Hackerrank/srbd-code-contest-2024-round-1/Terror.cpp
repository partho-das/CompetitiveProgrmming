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
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

const int maxn = 1e5;
vector<int>graph[maxn + 5];
int par[maxn + 5][20], depth[maxn + 5];

void dfs(int src, int prv, int level){
    depth[src] = level;
    par[src][0] = prv;
    for(int child : graph[src]){
        if(child != prv){
            dfs(child, src, level + 1);
        }
    }
    return;
}

int Lift(int u, int k){
    for(int i = 0; i <= 18; i++){
        if(k & (1 << i)) u = par[u][i];
    }
    return u;
}
int Lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);

    v = Lift(v, depth[v] - depth[u]);
    if(u == v) return v;
    int lca = 1;
    for(int i = 18; i >= 0; i--){
        if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
        else lca = par[u][i];
    }
    return lca;
}

int find_res(int u, int v){
    int commonParent = Lca(u, v);


    int distance = depth[u] + depth[v] - 2 * depth[commonParent];
    int du = depth[u] - depth[commonParent];
    int dv = depth[v] - depth[commonParent];

    if(distance % 2 == 0){
        if(du > dv) swap(u, v), swap(du, dv);
    // cout << u << " " <<  << " " << distance << endl;
        return Lift(v, distance / 2);
    }
    else{
        if(du > dv) return Lift(u, distance / 2);
        else return Lift(v, (distance + 1) / 2);
    }
    return -1;
}
void solve(){

    int n, q;
    sc1(n);

    for(int i = 0; i <= n; i++){
        graph[i].clear();
        depth[i] = 0;
        for(int j = 0; j < 20; j++){
            par[i][j] = 0;
        }
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc2(u, v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0, 0);

    for(int i = 1; i <= 18; i++){
        for(int j = 1; j <= n; j++){
            par[j][i] = par[par[j][i - 1]][i - 1];
            // cout << j << " " << i << " " << par[j][i] << endl;
        }
    }

    sc1(q);
    while(q--){
        int u, v;
        sc2(u, v);
        // cout << u << " " << v << endl;
        int res = find_res(u, v);
        printf("%d\n", res);
    }

    return;
}
int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/Code/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/Code/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    sc1(test);

    while(test--){
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


