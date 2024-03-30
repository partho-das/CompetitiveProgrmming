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

const int maxn = 3e4;
vi graph[maxn + 5];
ll weight[maxn + 5], depth[maxn + 5], sump = 0, sumn = 0, pcnt = 0, ncnt = 0;
int n, t = 1;

void dfs(int src, int d, int par){
    //cout << src << " " << par << " " << d << endl;
    if(d == 0){
        sump += weight[src];
        pcnt++;
    }
    else sumn += weight[src], ncnt++;
    
    depth[src] = d;


    for(auto child : graph[src]){
        if(par != child){
            dfs(child, (d + 1) % 2, src);
        }
    }
    return;
}

void solve(){
    
    sc1(n);

    sump = 0, sumn = 0, pcnt = 0, ncnt = 0;
    for(int i = 0; i <= n; i++){
        graph[i].clear();
    }


    for(int i = 1; i <= n; i++){
        scl(weight[i]);
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc2(u, v);
        //cout << u << " " << v << endl;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, 0, -1);

    ll mx = -INF, res = -INF;
    //cout << sump << " " << sumn <<  " " << pcnt << " " << ncnt << endl;
    for(int i = 1; i <= n; i++){
        ll temp;
        if(depth[i] == 0){
            temp = (pcnt * weight[i] - sump) + ((ncnt * weight[i] - sumn) * -1);
        }
        else{
            temp = ((pcnt * weight[i] - sump) * -1) + (ncnt * weight[i] - sumn);
        }

        if(temp > mx){
            mx = temp;
            res = i;
        }
        //cout << temp << endl;
    }
    printf("Case %d: %lld\n", t++, res);


    return;
}


int main() {
    #ifdef PARTHO
        freopen("IO/input.txt","r",stdin);
        freopen("IO/output.txt","w",stdout);
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
