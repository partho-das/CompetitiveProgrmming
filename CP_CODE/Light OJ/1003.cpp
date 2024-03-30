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

const int maxn = 2e4;
int t = 1, m, visit[maxn + 5];
vector<int>adj[maxn + 5];

bool dfs(int src){

	visit[src] = 1;
	int ck = 1;
	for(int i = 0; i < adj[src].size() && ck; i++){
		if(!visit[adj[src][i]]){
			ck = ck & dfs(adj[src][i]);
		}
		else if( visit[adj[src][i]] == 1) ck = 0;
	}
	visit[src] = 2;
	return ck;
}

void solve(){
    
	cin >> m;

	for(int i = 0; i <= 2 * m; i++) {
		adj[i].clear();
		visit[i] = 0;
	}
	map<string, int>id;
	set<pii>unq;

	int indx = 0, uid, vid;

	for(int i = 0; i < m; i++) {
		string u, v;

		cin >> u >> v;
		if(id.find(u) == id.end()) {
			id[u] = indx++;
		}
		if(id.find(v) == id.end()) {
			id[v] = indx++;
		}

		uid = id[u], vid = id[v];
		if(unq.find({uid, vid}) != unq.end()) continue;
		unq.insert({uid, vid});
		adj[uid].pb(vid);
	}

	int visitcnt = 1, ck = 1;

	for(int i = 0; i < indx && ck; i++) {
		if(!visit[i]){
			ck = ck & dfs(i);
		}
	}


	if(ck) {
		cout << "Case " << t++ << ": Yes\n";
	}
	else {
		cout << "Case " << t++ << ": No\n";
	}


    return;
}



int main() {
    #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    FastIO;

    int test = 1;

    cin >> test;

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