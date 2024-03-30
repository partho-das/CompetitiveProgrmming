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

const int maxn = 11;
int visit[maxn + 5][maxn + 5], t = 1, n;
char grid[maxn + 5][maxn + 5];
vector<pii>point(26);

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isval(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n && !visit[x][y] && grid[x][y] != '#';
}


int bfs(pii src, pii dest){



    visit[src.ff][src.ss] = 1;

    queue<pair<pii, int>>Q;

    Q.push({src, 0});


    while(!Q.empty()){
        pair<pii, int> now = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++){
            pii nxt{now.ff.ff + dx[i], now.ff.ss + dy[i]};
            if(isval(nxt.ff, nxt.ss)){
                if(grid[nxt.ff][nxt.ss] == '.'){
                    Q.push({nxt, now.ss + 1});
                    visit[nxt.ff][nxt.ss] = 1;
                }
                else if(grid[nxt.ff][nxt.ss] == grid[dest.ff][dest.ss]){
                    return now.ss + 1;
                }
              
            }
        }

    }
    return -1;
}

void solve(){
    
    int k = -1;
    sc1(n);
  
    for(int i = 0; i < n; i++){
        getchar();
        for(int j = 0; j < n; j++){
            grid[i][j] = getchar();
            if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') k = max(k, grid[i][j] - 'A'), point[grid[i][j] - 'A'] = {i, j} ;
            //cout << grid[i][j];
        }
        //puts("");
    }


    int res = 0;
    for(int i = 1; i <= k; i++){
        memset(visit, 0, sizeof visit);
        int ck = bfs( point[i - 1], point[i]);
        grid[point[i - 1].ff][point[i - 1].ss] = '.';
        if(ck == -1){
            res = -1;
            break;
        }
        else res += ck;
    }


    if(res != -1){
        printf("Case %d: %d\n", t++, res);
    }
    else{
        printf("Case %d: Impossible\n", t++);
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