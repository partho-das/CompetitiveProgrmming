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

const int maxn = 1e3;
vi graph[maxn + 5];
string strset[maxn + 5];
int d[maxn + 5], low[maxn + 5], n, tc = 1;
void input(){

	for(int i = 0; i <= n; i++){
		graph[i].clear();
	}
	string str;
	int pos = 1;
	map<string, int> indx;
	for(int i = 0; i < n; i++){
		cin >> str;
		//cout <<str;
		strset[pos] = str;
		indx[str] = pos++;
	}

	int e;

	sc1(e);

	for(int i = 0; i < e; i++){
		string u, v;
		cin >> u >> v;

		graph[ indx[u] ].pb( indx[v]);
		graph[ indx[v] ].pb( indx[u]);

		//cout << indx[u] << " " << indx[v] << endl;
	}

	

	return;
}

int visit[maxn + 5], dv = 1, root, articulaion[maxn + 5];
void dfs(int src){
	if(visit[src]) return;
	visit[src] = 1;

	d[src] = dv++;
	low[src] = d[src];
	int child = 0;
	for(int i = 0; i < graph[src].size(); i++){
		int nxt = graph[src][i];
		if(visit[nxt]){
			low[src] = min(low[src], d[nxt]);
		}
		else{
			child++;
			dfs(nxt); 
			low[src] = min(low[src], low[nxt]);
			if(d[src] <= low[nxt] && src != root){
				articulaion[src] = 1;
			}
		}
	}
	if(src == root && child > 1){
		//cout << child << endl;
		articulaion[src] = 1;
	}

	return;
}

void solve(){
    
	//sc1(n);

	input();
	std::vector<string> res;
	memset(articulaion, 0, sizeof articulaion);
	memset(visit, 0, sizeof visit);
	for(int i = 1; i <= n; i++){
	    if(!visit[i]){
		    root = i;
			dv = 0;
			memset(d, 0, sizeof d);
			memset(low, 0, sizeof low);
			dfs(root);
	    }
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(articulaion[i]){
			 cnt++;
			 res.pb( strset[i] );
		}
	}

	sort(all(res));



	printf("City map #%d: %d camera(s) found\n", tc++, cnt);
	for(auto it : res) cout << it << endl;
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
    int ck = 0;
    while(1){
    	sc1(n);
    	//cout << n << endl;
    	if(!n) break;
    	if(!ck) ck = 1;
    	else puts("");
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