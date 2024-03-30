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

const int maxn = 5e2;
int par[maxn + 5];

int get(int x) {
    return par[x] < 0 ? x : par[x] = get(par[x]);
}

bool update(int a, int b) {
    a = get(a), b = get(b);
    if(a == b) return 0;

    if(par[a] > par[b]) swap(a, b);
    par[a] += par[b];
    par[b] = a;

    return 1;
}


struct edge {
    int u, v, w;

    edge(){
        u = v = w = 0;
    }
    edge(int _u, int _v, int _w){
        u = _u, v = _v, w = _w;
    }

    bool operator < (edge &a){
        return w < a.w;
    }
};
vector<int>graph[maxn + 5], w[maxn + 5], res;

int tc = 1;


void dfs(int src, int par, int sum){
    res[src] = sum;

    for(int i = 0; i < graph[src].size(); i++){
        if(graph[src][i] != par){
            dfs(graph[src][i], src, max(sum , w[src][i]) );
        }
    }
    return;
}
void solve(){
    
    int n, m, t;
    sc2(n, m);
    vector<edge>el(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        sc3(u, v, w);
        el[i] = edge(u, v, w);
    }

    sc1(t);
    for(int i = 0; i < n; i++){
        graph[i].clear();
        w[i].clear();
    }

    sort(all(el));

    memset(par, -1, sizeof par);
    for(int i = 0; i < el.size(); i++) {
        edge temp = el[i];
        if(update(temp.u, temp.v)) {
            graph[temp.u].pb(temp.v);
            graph[temp.v].pb(temp.u);
            w[temp.u].pb(temp.w);
            w[temp.v].pb(temp.w);
        }
    }

    
    res.resize(n);
    for(int i = 0; i < n; i++){
        res[i] = -1;   
    }


    dfs(t, -1, 0);

    printf("Case %d:\n", tc++);


    for(int i = 0; i < n; i++){
        if(res[i] >= 0)
            printf("%d\n", res[i]);
        else puts("Impossible");
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