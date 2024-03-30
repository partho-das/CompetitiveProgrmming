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

const int maxn = 1e4;
int n, m, t = 1, cnt = 0, visit[maxn + 5], dis[maxn + 5], low[maxn + 5], Time = 1;
set<int> adj[maxn + 5];

void dfs(int src, int par){

    int ck = 0, childcnt = 0;
    visit[src] = 1;
    dis[src] = Time++;

    low[src] = inf;

    for(int child : adj[src]){
        if(!visit[child]){
            dfs(child, src); 
            childcnt++;
            low[src] = min(low[child], low[src]);
            if(low[child] >= dis[src] && src != 1) ck = 1;
        }
        else if(child != par) low[src] = min(low[src], dis[child]);
    }
   // cout << childcnt << " " << src << endl;
    //cout << src << " " << ck << " " << dis[src] << " " << low[src] << endl;
    if(src == 1){
        if(childcnt > 1) ck = 1;
    }
    cnt+= ck;
    return;
}
void solve(){
    
    sc2(n, m);

    for(int i = 0; i <= n; i++){
        adj[i].clear();
        visit[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        sc2(u, v);
        if(u == v) continue;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    Time = 1;
    cnt = 0;
    dfs(1, -1);
    printf("Case %d: %d\n", t++, cnt);


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