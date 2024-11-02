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

const int maxn = 5e5;

int subtree[maxn + 5], par[maxn + 5], n, degree[maxn + 5];
vector<int> graph[maxn + 5];
int dfs(int src, int prv){
    par[src] = prv;
    subtree[src] = 1;

    for(auto child : graph[src]){
        if(child != prv){
           subtree[src] += dfs(child, src);
        }
    }
    return subtree[src];
}

int find_res(){
    
    vector<int>next, now;
    next.pb(1);
    int deleted = 0;

    int res = inf;
    while(!next.empty()){
        queue<int>dq;
        now = next;
        next.clear();

        int cnt = deleted;
        for(int no : now){
            cnt += subtree[no] - 1;
            // cout << no << " " << " " << cnt << " " << subtree[no] << " " << deleted << endl;
            for(int child : graph[no]){
                if(child != par[no]){
                    next.pb(child);
                }
            }
            dq.push(no);
        }
        // cout << endl;
        res = min(res, cnt);
        while(!dq.empty()){
            int val = dq.front();
            dq.pop();
            if(degree[val] == 1 && val != 1){
            // cout << "val " <<  val << " " << degree[val] << endl;
                degree[val]--;
                degree[par[val]]--;
                dq.push(par[val]);
                deleted++;
            }
        }

    }
    return res;
}

void solve(){
    sc1(n);

    for(int i = 0; i <= n; i++){
        graph[i].clear();
        subtree[i] = degree[i] = 0;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc2(u, v);
        graph[u].pb(v);
        graph[v].pb(u);
        degree[u]++;
        degree[v]++;
    }
    dfs(1, 0);
    int res = find_res();
    cout << res << endl;
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


