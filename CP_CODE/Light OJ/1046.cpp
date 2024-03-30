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

int t = 1, n, m, res[11][11][11][11], visit[11][11];
int dx[] = {1, 1, -1, -1, 2,  2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1,  1, -1};

bool isval(int x, int y, int nx, int ny){

	return nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny];
}
void bfs(int x, int y, int k){


	visit[x][y] = 1;
	res[x][y][x][y] = 0;


	queue<pair<pii, pii>> Q;

	Q.push( {{x, y}, {0, k}});

	while(!Q.empty()){
		pair<pii, pii> now = Q.front();
		Q.pop();

		for(int i = 0; i < 8; i++){
			int nx = now.ff.ff + dx[i], ny = now.ff.ss + dy[i];

			if(isval(x, y, nx, ny)){
				pii nxt = now.ss;
				if(nxt.ss == k){
					nxt.ff++;
					nxt.ss = 0;
				}
				nxt.ss++;
				res[x][y][nx][ny] = nxt.ff;
				visit[nx][ny] = 1;
				Q.push({{nx, ny}, nxt});
			}

		}

	}

	return;
}
void solve(){
    
    sc2(n, m);

    memset(res, -1, sizeof res);
    

    int h  = 0;
    for(int i = 0; i < n; i++){
   		getchar();
    	for(int j = 0; j < m; j++){
    		char ch = getchar();
    		if(ch != '.'){
    			//cout << ch << endl;
    			memset(visit, 0, sizeof visit);
    			bfs(i, j, ch - '0');
    			h++;
    		}
    	}
    }


    int move = inf;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){

    		int temp = 0, th = 0;

    		for(int p = 0; p < n; p++){
    			for(int q = 0; q < m; q++){
    				if( res[p][q][i][j] != -1) temp += res[p][q][i][j] , th++;
    			}
    		}

    		if(th == h){
    			move = min(move, temp);
    		}
    	}
    }

    if(move == inf) move = -1;

    printf("Case %d: %d\n", t++, move);

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