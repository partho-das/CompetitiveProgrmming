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
vi adj[maxn + 5], temp[maxn + 5];
stack<int>order;
int visit[maxn + 5], scc[maxn + 5];


void graph_input(int &n, int &m, vi *adj){
    for(int i = 0; i <= n; i++){
        adj[i].clear();
    }

    for(int i = 0; i < m; i++){
        int u, v;
        sc2(u, v);
        adj[u].pb(v);
    }
}

void graph_output(int n){
     for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(auto child : adj[i]){
            cout << child << " ";
        }
        cout << endl;
    }
}


void order_output(stack<int> &stk){
    
    cout << "Stack = ";
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void scc_output(int *scc, int n){
    cout << "scc = " << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " : " << scc[i] << endl;
    }
    cout << endl;
    return;
}
int dfs_order(int src){

    visit[src] = 1;

    for(int child : adj[src]){
        if(!visit[child]){
            dfs_order(child); 
        }
    }
    order.push(src);

    return 0;
}

void find_scc(int src, int sccNo){
    visit[src] = 1;
    for(int child : adj[src]){
        if(!visit[child]){
            find_scc(child, sccNo);
        }
    }
    scc[src] = sccNo;
}

void reverse_graph(vi *adj, vi *temp, int n){
    for(int i = 1; i <= n; i++){
        for(int child : adj[i]){
            temp[child].pb(i);
        }
    }
    for(int i = 1; i <= n ; i++){
        adj[i] = temp[i];
        temp[i].clear();
    }
    return;
}


void build_condensed(vi *adj, vi *temp, int *scc, int n){

    for(int i = 1; i <= n; i++){
        for(int child : adj[i]){
            if( scc[i] != scc[child] ) {
                temp[ scc[i] ].pb( scc[child] );
            }
        }
    }

    for(int i = 1; i <= n; i++){
        adj[i] = temp[i];
        temp[i].clear();
    }
    return;
}

int find_condensed_graph(vi *adj, vi *temp, int n, int m, int *scc){ // here I bulid a condensed graph from adj vector and then put in into also in adj 
                                                                      // By useing temp vector and n = node, m = edge, scc = is strongy connectd componensts 
    for(int i = 0; i <= n; i++){
        visit[i] = 0;
    }
    while(!order.empty()) order.pop();


    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            dfs_order(i);
        }
    }
    reverse_graph(adj, temp, n);


    for(int i = 1; i <= n; i++){
        visit[i] = 0;
    }

    int sccNo = 1;
    while(!order.empty()){
        if(!visit[order.top()]){
            find_scc(order.top(), sccNo++);
        }
        order.pop();
    }

    reverse_graph(adj, temp, n);
    build_condensed(adj, temp, scc, n );

    // graph_output(n);
    // order_output(order);
    // scc_output(scc, n);
    return sccNo - 1;
}

int t = 1, indegree[maxn + 5]; 
void solve(){
    
    int n, m;
    sc2(n, m);

    graph_input(n, m, adj);

    int res = find_condensed_graph(adj, temp, n, m, scc);


    for(int i = 1; i <= n; i++){
        indegree[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int child : adj[i]){
            if(indegree[child] == 0) res--;
            indegree[child] = 1;
        }
    }

    printf("Case %d: %d\n", t++, res);


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