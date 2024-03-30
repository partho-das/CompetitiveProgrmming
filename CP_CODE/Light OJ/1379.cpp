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
struct node{
    int id, cost;

    node(){}
    node(int _id, int _cost){
        id = _id, cost = _cost;
    }

    bool operator >( const node &a ) const {
        return cost < a.cost;
    }
};

vi adj[maxn + 5], radj[maxn + 5], weight[maxn + 5], rweight[maxn + 5];
int mnsrc[maxn + 5], mndis[maxn + 5], tc = 1;


void dijkstra(int src){
    priority_queue<node, vector<node>, greater<node> > pq;

    mnsrc[src] = 0;

    pq.push({src, 0});


    while(!pq.empty()){
        node now = pq.top();
        pq.pop();

        for(int i = 0; i < adj[now.id].size(); i++){
            int next = adj[now.id][i];
            //cout << next << " " << now.id << " " << mnsrc[next] << endl;
            if(mnsrc[next] > now.cost + weight[now.id][i]){
                mnsrc[next] = now.cost + weight[now.id][i];
                pq.push({next, mnsrc[ next ]});
            }
        }
    }
    return;
}
    


void solve(){
    
    int n, m, s, t, p;

    sc2(n, m);
    sc3(s, t, p);


    for(int i = 0; i <= n; i++){
        radj[i].clear();
        rweight[i].clear();
        adj[i].clear();
        weight[i].clear();
        mnsrc[i] = inf;
        mndis[i] = inf;
    }

    for(int i = 0; i < m; i++){
        int u, v, w;
        sc3(u, v, w);

        adj[u].pb(v);
        weight[u].pb(w);
        radj[v].pb(u);
        rweight[v].pb(w);
    }

    for(int i = 0; i <= n; i++){
        swap(mnsrc[i], mndis[i]);
        swap(adj[i], radj[i]);
        swap(weight[i], rweight[i]);
    }
    dijkstra(t);

    // for(int i = 1; i <= n; i++){
    //     cout << mnsrc[i] << endl;
    // }

    for(int i = 0; i <= n; i++){
        swap(mnsrc[i], mndis[i]);
        swap(adj[i], radj[i]);
        swap(weight[i], rweight[i]);
    }
    
    dijkstra(s);

    int res = -1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            if(mnsrc[i] + weight[i][j] + mndis[ adj[i][j] ] <= p){
                res = max(res, weight[i][j]);
            }
        }
    }


    printf("Case %d: %d\n", tc++, res);

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