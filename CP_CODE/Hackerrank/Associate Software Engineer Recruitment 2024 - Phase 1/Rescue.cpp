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

const int maxn = 1000;
ll grid[maxn + 5][maxn + 5], n, m;
ll result[maxn + 5][maxn + 5];
vector<pii>border;

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

struct node{
   ll x, y, cost;
   node(){}
   node(int _x, int _y, int _cost){
       x = _x, y = _y, cost = _cost;
   }
   bool operator>(const node& a) const {
       return cost > a.cost;
   }
};
bool isval(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dijkstra(){
    priority_queue<node, vector<node>, greater<node> > pq;
    for(int i = 0; i < (int)border.size(); i++){
        pq.push(node(border[i].ff, border[i].ss, 0));
        result[border[i].ff][border[i].ss] = 0;
    }

    while(!pq.empty()){
       node now = pq.top();
       pq.pop();
       for(int i = 0; i < 4; i++){
            int nextx = now.x + dirx[i], nexty = now.y + diry[i];
            if( isval(nextx, nexty)){
                ll temp_cost = now.cost + grid[now.x][now.y];
                if(temp_cost < result[nextx][nexty]){
                    pq.push(node(nextx, nexty, temp_cost));
                    result[nextx][nexty] = temp_cost;
                }
            }
       }
    }
    return;
}

void solve(){

    scll(n, m);

    border.clear();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scl(grid[i][j]);
            result[i][j] = INF;
        }
    }
    int b;
    sc1(b);
    for(int i = 0; i < b; i++){
        int x, y;
        sc2(x, y);
        border.pb({x, y});
    }

    dijkstra();

    int t;
    sc1(t);
    while(t--){
        int x, y;
        sc2(x, y);
        // cout << x << " " << y << endl;
        printf("%lld\n", result[x][y]);
    }
}


int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/Code/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/Code/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    // sc1(test);

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


