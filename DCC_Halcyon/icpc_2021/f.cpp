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

struct node{
    int x, y;
    ll w;
    node(){}
    node(int _x, int _y, ll _w){
        x = _x, y = _y, w = _w;
    }
    bool operator < (node const &a)const{
        return w > a.w;
    }
};

vector<vector<bool>>obs;
vector<vector<vector<node>>>tunnel;
vector<vector<ll>>cost;
vector<vector<pii>>path;

vector< vector<vector<int>> > moves;

ll mcost[10];
int n, m, p, q, t = 1;
int dirx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int diry[] = {-1, 0, +1, -1, +1, -1, 0, +1};


bool isval(int x, int y, int movetype){
    return x >= 1 && x <= n && y >= 1 && y <= m && !moves[x][y][movetype] && !obs[x][y]; 
}
ll dijkstra(pii s, pii d){

    priority_queue<node>pq;

    cost[s.ff][s.ss] = 0;

    pq.push(node(s.ff, s.ss, 0));


    //cout << pq.size() << endl;
    while(!pq.empty()){
        node now = pq.top();
        pq.pop();
        //cout << now.x << " " << now.y << " " << cost[now.x][now.y] << endl;
        if(now.x == d.ff && now.y == d.ss) {
            
            pii var = d;
            while(1){

                cout << to_string(var) << endl;
                if(var == s) break; 
                var = path[var.ff][var.ss];
            }
      
            return cost[d.ff][d.ss];
        }


        for(int k = 0; k < (int)tunnel[now.x][now.y].size(); k++){
            node temp = tunnel[now.x][now.y][k];
            if(cost[temp.x][temp.y] > cost[now.x][now.y] + temp.w && !obs[temp.x][temp.y]){
                cost[temp.x][temp.y] = cost[now.x][now.y] + temp.w;
                pq.push(node(temp.x, temp.y,cost[now.x][now.y] + temp.w));
                path[temp.x][temp.y] = {now.x, now.y};
            }

        }

        for(int i = 0; i < 8; i++){
            pii nxt = {now.x, now.y};
            while(1){

                nxt = {nxt.ff + dirx[i], nxt.ss + diry[i]};
                if(!isval(nxt.ff, nxt.ss, i)) break;
                moves[nxt.ff][nxt.ss][i] = 1;

                if(cost[nxt.ff][nxt.ss] > cost[now.x][now.y] + mcost[i]){
                    cost[nxt.ff][nxt.ss] = cost[now.x][now.y] + mcost[i];
                    pq.push(node(nxt.ff, nxt.ss, cost[now.x][now.y] + mcost[i]));
                    path[nxt.ff][nxt.ss] = {now.x, now.y};

                }
            
            }
        }
    }

    return -1;
}
void solve(){
    
    sc2(n, m);
    sc2(p, q);


    moves.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(8, 0)));
    obs.assign(n + 1, vector<bool>(m + 1, 0));
    cost.assign(n + 1, vector<ll>(m + 1, INF));
    path.assign(n + 1, vector<pii>(m + 1, {-1, -1}));


    //tunnel.clear();

    tunnel.assign(n + 1, vector< vector<node> >(m + 1));

    for(int i = 0; i <= n; i++){
        //cout << obs[i].size() << endl;
        for(int j = 0; j <= m; j++){
            tunnel[i][j].clear();
            obs[i][j] = 0;
            cost[i][j] = INF;
        }
    }

    //return;

    pii s, d;

    sc2(s.ff, s.ss);
    sc2(d.ff, d.ss);

    for(int i = 0; i < 8; i++){
        scl(mcost[i]);
    }

    for(int i = 0; i < p; i++){
        pii u, v;
        int w;
        sc2(u.ff, u.ss);
        sc2(v.ff, v.ss);
        sc1(w);
        tunnel[u.ff][u.ss].pb(node(v.ff, v.ss, w));
        //tunnel[v.ff][v.ss].pb(node(u.ff, u.ss, w));

    }
    for(int i = 0; i < q; i++){
        int x, y;
        sc2(x, y);
        //cout << x << " " << y << endl;
        obs[x][y] = 1;
    }

    ll res = dijkstra(s, d);
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
