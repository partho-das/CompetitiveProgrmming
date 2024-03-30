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

const int maxn = 2e3;
int n, m, w, grid[maxn + 2][maxn + 2];
ll visit[maxn + 5][maxn + 5];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int isval(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && grid[x][y] != -1;
}
pair<ll, pll> bfs(int sx, int sy){

	pair<ll, pll> ret = {INF, {INF, INF}};
	visit[sx][sy] = 1;
	if(grid[sx][sy] > 0) ret.ff = grid[sx][sy] + 1,ret.ss = {sx, sy};
	queue<pll>q;
	q.push({sx, sy});
	while(!q.empty()){
		pll now = q.front();
		//cout << now.ff << " " << now.ss << endl;
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = dx[i] + now.ff, ny = dy[i] + now.ss;
			if(isval(nx, ny)){
				visit[nx][ny] = visit[now.ff][now.ss] + w;
				if(grid[nx][ny] > 0){
					if(ret.ff > visit[nx][ny] + grid[nx][ny]){
						ret.ff = visit[nx][ny] + grid[nx][ny];
			//cout << "nx = " << nx << " ny = " << ny << " " << ret.ff << endl;
						ret.ss = {nx, ny};
					}
				}
				q.push({nx, ny});
			}
		}
	}
	//cout << ret.ff << endl;
	return ret;

}
void solve(){
    
    sc3(n, m, w);

    int ck = 0;
    for(int i = 0; i < n; i++){
    	for(int j =  0; j < m; j++){
    		sc1(grid[i][j]);
    		if(grid[i][j] > 0) ck++;
    	}
    }

    ll res = INF;
    pair<ll, pll> sp = bfs(0, 0);

    int sd = visit[n - 1][m - 1];
    
    memset(visit, 0, sizeof visit);
    pair<ll, pll> dp = bfs(n - 1, m - 1);
    if(sd != 0) res = min(res, (ll) visit[0][0] - 1);
    

    if(dp.ff != INF && sp.ff != INF)
    res = min(res, dp.ff + sp.ff - 2);

	if(res <= 1e16) cout << res << endl;
	else cout << -1 << endl;
   
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

    //sc1(test);

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