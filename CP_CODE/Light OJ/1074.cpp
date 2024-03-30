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

const int maxn = 2e2;
int weightN[maxn + 5], visit[maxn + 5], t = 1, n, m, q, neg[maxn + 5], tempsum[maxn + 5], res[maxn + 5];
vi adj[maxn + 5], temp[maxn + 5];

void find_neg(int src, int weightSum){

    visit[src] = 1;
    tempsum[src] = weightSum;

    for(int child : adj[src]){
        if(!visit[child]){
            find_neg(child, weightSum + pow(weightN[child] - weightN[src], 3) ) ;
        }
        else if(visit[child] == 1){
            if( (weightSum + pow(weightN[child] - weightN[src], 3)) -  tempsum[child] < 0){
                neg[child] = 1;
                neg[src] = 1;
            } 
        }
    }
    visit[src] = 2;
    return;

}
void markneg(int src){
    visit[src] = 1;
    neg[src] = 1;
    for(int child : adj[src]){
        if(!visit[child]){
            markneg(child);
        }
    }
    return;
}

struct node{

    int id, cost;

    node(){ id = 0, cost = 0;}
    node(int _id, int _cost){
        id = _id, cost = _cost;
    }
    
    bool operator >(const node &a) const {
        return cost > a.cost;
    }
};
void dijkstra(int src){

    priority_queue<node, vector<node>, greater<node> >pq;

    res[1] = 0;
    pq.push(node(1, 0));

    while(!pq.empty()){
        node now = pq.top();
        pq.pop();

        if(!visit[now.id])
        for(int child : adj[now.id]){
            int temp = now.cost + pow(weightN[child] - weightN[now.id], 3);
            if(res[child] > temp){
                res[child] = temp;
                pq.push(node(child, temp));
            }
        }
        visit[now.id] = 1;
    }


}
void solve(){
    

    sc1(n);

    for(int i = 0; i <= n; i++){
        visit[i] = 0;
        adj[i].clear();
        temp[i].clear();
        neg[i] = 0;
        res[i] = inf;
    }

    for(int i = 1; i <= n; i++){
        sc1(weightN[i]);
    }

    sc1(m);

    for(int i = 0; i < m; i++){
        int u, v;
        sc2(u, v);
        adj[u].pb(v);
    }

    find_neg(1, 0);


    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visit[i]) res[i] = -1;
        visit[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        if(neg[i] && !visit[i]){
            markneg(i);
        }
    }

    for(int i = 1; i <= n; i++){
        if(res[i] != -1 && !neg[i]){
            for(int child : adj[i]){
                if(res[child] != -1 && !neg[child]){
                    temp[i].pb(child);
                }
            }
            adj[i] = temp[i];
        }
        visit[i] = 0;
    }

    dijkstra(1);


    int q;
    sc1(q);
    printf("Case %d:\n", t++);
    while(q--){
        int i;
        sc1(i);
        if(res[i] < 3 || neg[i] ){
            printf("?\n");
        }
        else printf("%d\n", res[i]);
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