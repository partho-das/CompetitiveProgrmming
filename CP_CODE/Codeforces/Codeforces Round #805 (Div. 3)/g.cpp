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

const int maxn = 2e5;
vi graph[maxn + 5];
int par[maxn + 5][35], level[maxn + 5], n;
void dfs(int src, int mypar){
	level[src] = level[mypar] + 1;
	par[src][0] = mypar;
	for(int child : graph[src]){
		if(child != mypar){
			dfs(child, src);
		}
	}
	return; 
}
void lca_process(int n){
	for(int i = 1; i < 30; i++){
		for(int j = 1; j <= n; j++){
			if(par[j][i - 1] == -1) par[j][i] = -1;
			else par[j][i] = par[ par[j][i - 1] ][i - 1];
		}
	}
	return;
}
int lca(int u, int v){
	if(level[u] < level[v]) swap(u, v);
	int dif = level[u] - level[v];
	for(int i = 0; i < 30; i++){
		if(dif & (1 << i)){
			u = par[u][i];
		}
	}

	if(u == v){
		return v;
	}
	int LCA = -1;
	int temp = level[u];
	for(int i = 29; i >= 0; i--){
		if( level[u] >= (1 << i)){
			if(par[u][i] == par[v][i]){
				LCA = par[u][i];
			}
			else u = par[u][i], v = par[v][i];
		}
	}
	return LCA;
}

void solve(){
	int n;
	sc1(n);


	for(int i = 0; i < n - 1; i++){
		int u, v;
		sc2(u, v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	level[0] = -1;

	dfs(1, 0);
	par[1][0] = -1;
	lca_process(n);

	//cout << lca(1, 1) << endl;
	int q;
	sc1(q);
	while(q--){
		int k, u, v;
		sc2(k, u);
		if(k == 1){
			puts("YES");
			continue;
		}
		int temp, ck = 1;

		for(int i = 0; i < k - 1; i++){
			sc1(temp);
			//cout << temp << endl;
			if(i == 0 || !ck){
				v = temp;
			}
			else{
				//cout << i << endl;
				if(level[u] > level[v]) swap(u, v);
				int comp = lca(u, v);
				
				int x = lca(u, temp), y = lca(v, temp);
				//cout << u << " " << v << " " << i << " " << x << " "<< y << " " << temp  << endl;
				if(comp == u || comp == v){
					if(x == u && (y != temp && y != v && y != u) ){
						ck = 0;
					}
					else if(x == temp){
						u = temp;
					}
					else if(y == v){
						v = temp;
					}
					else if( !(u == x && y == temp )){
						u = temp;
					}

				}
				else{
					if(temp == comp){
						continue;
					}
					if( (x == comp && y == comp && comp != temp) || (x == y && x != comp)){
						ck = 0;
					}
					if(x == comp){
						if((y != temp && y != v)){
							ck = 0;
						}
						else if(y == v){
							v = temp;
						}

					}
					else if(y == comp){
						if(x != temp && x != u){
							ck = 0;
						}
						else if(x == u){
							u = temp;
						}
					}
				}
			}
		}
		puts(ck ? "YES" : "NO");
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

    //sc1(test);

    while(test--){
        solve();
    }
    #ifdef PARTHO
        int end_time = clock();
        //printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
///Before submit=>	
///    *check for integer overflow,array bounds
///    *check for n=1
