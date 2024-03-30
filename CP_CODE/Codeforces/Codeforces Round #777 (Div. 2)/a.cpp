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
const int maxn = 100;
int visit[maxn + 5][maxn + 5], r[maxn + 5][maxn + 5], c[maxn + 5][maxn + 5], grid[maxn + 5][maxn + 5], n, m;
vector<pair<pii, pii> >temp;
bool isvisit(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m && !visit[i][j] && grid[i][j];
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void dfs(int i, int j){
	visit[i][j] = 1;

	int il = i, ir = i, jl = j, jr = j;

	while(il >= 0 && grid[il][j]){
		il--;
	}
	while(ir < n && grid[ir][j]){
		ir++;
	}

	while(jl >= 0 && grid[i][jl]){
		jl--;
	}
	while(jr < m && grid[i][jr]){
		jr++;
	}
	il++, ir--;
	jl++, jr--;

	//cout << i << " " << j << " " << il << " " << ir << " " << jl << " " << jr << endl;
	temp.pb({{il, ir}, {jl, jr}});

	for(int p = 0; p < 4; p++){
		int nx = dx[p] + i, ny = j + dy[p];
		if(isvisit(nx, ny)){
			dfs(nx, ny);
		}
	}

	return;
}

void solve(){
    


	sc2(n, m);    

	for(int i = 0; i < n; i++){
			getchar();
		for(int j = 0; j < m; j++){
			char ch = getchar();
			grid[i][j] = ch - '0';
			//cout << n << " " << m << " " << grid[i][j]<< endl;
			visit[i][j] = 0;
			r[i][j] = 0;
			c[i][j] = 0;
		}
	}

	int ck = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] && !visit[i][j]){
				temp.clear();
				dfs(i, j);
				for(int x = 1; x < temp.size(); x++){
					if(temp[x].ff != temp[0].ff || temp[x].ss != temp[0].ss){
				//cout << i << " " << j << temp.size() << endl;
						ck = 1;
						break;
					}
				}
			}
		}
	}

	if(ck){
		puts("NO");
	}
	else puts("YES");

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