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

const int maxn = 2e5;

vi graph[maxn + 5], weight[maxn + 5];
ll costa[maxn + 5], costb[maxn + 5], hcosta[maxn + 5], hcostb[maxn + 5];
int visited[2][maxn + 5];
bool horse[maxn + 5];


void digkstra(ll *cost, ll *hcost, int src){

    struct state{
        int id;
        ll cost;
        bool hasHorse;
        bool operator > (const state& a) const {
            return cost > a.cost;
        }
    };

    priority_queue<state, vector<state>, greater<state> > pq;
    if(horse[src]){
        hcost[src] = 0;
        pq.push({src, 0, 1});
    }
    else{
        cost[src] = 0;
        pq.push({src, 0, 0});

    }
    while(!pq.empty()){
        state now = pq.top();
        pq.pop();
        
        if(now.hasHorse){
            if(now.cost > hcost[now.id]) continue;
        }
        else{
            if(now.cost > cost[now.id]) continue;
        }

        for(int i = 0; i < graph[now.id].size(); i++){
            int child = graph[now.id][i];
            ll w = weight[now.id][i], next_hasHorse = now.hasHorse;
            if(next_hasHorse) w /= 2;
            if(next_hasHorse && (now.cost + w < hcost[child])){
                hcost[child] = now.cost + w;
                pq.push({child, hcost[child], 1});
            } 
            if(!next_hasHorse && (now.cost + w < cost[child])){
                cost[child] = now.cost + w;
                pq.push({child, cost[child], horse[child]});
            } 
        }
    }
}

void solve(){
    
    int n, m, h;
    sc3(n, m, h);

    for(int i = 0; i <= n; i++){
        horse[i] = 0;
        hcosta[i] = hcostb[i] = costa[i] = costb[i] = 1e12;
        graph[i].clear();
        weight[i].clear();
        visited[0][i] = visited[1][i] = 0;
    }

    for(int i = 0; i < h; i++){
        int val;
        sc1(val);
        horse[val] = 1;
    }


    for(int i = 0; i < m; i++){
        int u, v, w;
        sc3(u, v, w);
        graph[u].pb(v);
        graph[v].pb(u);

        weight[v].pb(w);
        weight[u].pb(w);
    }

    digkstra(costa, hcosta, 1);

    for(int i = 0; i <= n; i++){
        visited[0][i] = visited[1][i] = 0;
    }
    digkstra(costb, hcostb, n);

    ll res = 1e12;
    for(int i = 1; i <= n; i++){
            // cout << i << " " << costa[i] << " " << hcosta[i] << " " << costb[i] << " " << hcostb[i] << endl;
        if( (costa[i] != 1e12 || hcosta[i] != 1e12) && (costb[i] != 1e12 || hcostb[i] != 1e12)){
            ll ca = min(costa[i], hcosta[i]);
            ll cb = min(costb[i], hcostb[i]);
            res = min(res, max(ca, cb));
        }
    }

    if(res != 1e12){
        cout << res << endl;
    }
    else cout << -1 << endl;
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


