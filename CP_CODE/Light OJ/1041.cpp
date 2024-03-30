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


const int maxn = 50;
vector<pair<pii, int>> edge;
map<string, int> id;
char S[50];
int par[maxn + 5], t = 1;
int input(int e){
    edge.clear();
    id.clear();
    int vcnt = 0;
    for(int i = 0; i < e; i++){
        string str, str2;
        int w, u, v;
        
        getchar();
        scanf("%s", S);
        str = S;
        getchar();
        scanf("%s", S);
        str2 = S;
        sc1(w);

        if(id.find(str) != id.end()){
            u = id[str];
        }
        else u = id[str] = vcnt++;
        if(id.find(str2) != id.end()){
            v = id[str2];
        }
        else v = id[str2] = vcnt++;
        edge.pb( {{u, v}, w} );
    }

    return vcnt;
}

bool cmp(pair<pii, int> &a, pair<pii, int> &b){
    return a.ss < b.ss;
}

int get(int x){
    return par[x] < 0 ? x : par[x] = get(par[x]);
}

bool update(int a, int b){
    a = get(a), b = get(b);

    if(a == b) return 0;
    if(par[a] > par[b]) swap(a, b);
    par[a] += par[b];
    par[b] = a;
    return 1;
}
void solve(){
    
    int e;
    cin >> e;
    int vcnt = input(e);

    sort(all(edge), cmp);
    memset(par, -1, sizeof par);

    int taken = 0, res = 0;
    for(int i = 0; i < edge.size(); i++){
        if(update(edge[i].ff.ff, edge[i].ff.ss)){
            res += edge[i].ss;
            taken++;
        }
    }

    if(taken == vcnt - 1)
        printf("Case %d: %d\n", t++, res);
    else printf("Case %d: Impossible\n", t++);

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