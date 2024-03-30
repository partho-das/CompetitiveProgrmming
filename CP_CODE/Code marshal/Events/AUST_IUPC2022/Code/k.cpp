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

const int maxn = 5e4;
int par[maxn + 5];

int get(int x){
    return par[x] < 0 ? x : par[x] = get(par[x]);
}

bool update(int x, int y){
    x = get(x), y = get(y);
    if(x == y) return 0;

    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return 1;
}

struct edge{
    int u, v;
    ll w;

    edge(){}
    edge(int _u, int _v, ll _w){
        u = _u, v = _v, w = _w;
    }

};

bool cmp( edge &a, edge &b){
    return a.w < b.w;
}
int t = 1;
vector<int> graph[maxn + 5];
vll weight[maxn + 5];

vi nodes;
ll res = -1; 
int n;
void dfs(int src, int dest, int par, ll agent){
    //cout << src << endl;
    if(src == dest){
        res = agent;
        return;
    }
    for(int i = 0; i < graph[src].size(); i++){
        int child = graph[src][i];
        ll w = weight[src][i];

        if(child != par){
            dfs(child, dest, src, max(agent, w));
        }
    }
    return;
}


void solve(){
    int m, q;
    sc2(n, m);

   
    vector<edge>edge_list(m);

    for(int i = 0; i <= n; i++){
        par[i] = -1;
        graph[i].clear();
        weight[i].clear();
    }
    res = -1;

    for(int i = 0; i < m; i++){
        sc2(edge_list[i].u, edge_list[i].v);
         scl(edge_list[i].w);
    }
    sort(all(edge_list), cmp);

  

    for(int i = 0; i < edge_list.size(); i++){
        int u = edge_list[i].u, v = edge_list[i].v;
        ll w = edge_list[i].w;

        if(update(u, v)){
            graph[u].pb(v);
            graph[v].pb(u);
            weight[v].pb(w);
            weight[u].pb(w);
        }
    }

    sc1(q);

    printf("Case %d\n", t++);
    while(q--){
        int src, dest;
        sc2(src, dest);
        dfs(src, dest, -1, 0);
        printf("%lld\n", res);

    }







    return;
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

    while(test--){
        solve();
        puts("");
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
