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

const int maxn = 3e4;

vector<int>node[maxn + 5], weight[maxn + 5];
vector<pii>dp(maxn + 5);//ff == first_max, ss = second_max
int t = 1, n, u, v, w, temp;


void changefor(int src, int temp){
	if(temp > dp[src].ff){
		dp[src].ss = dp[src].ff;
		dp[src].ff = temp;
	}
	else if(temp > dp[src].ss){
		dp[src].ss = temp;
	}
	return;
}
int dfs(int src, int par){

	FOR(i, 0, node[src].size()){
		if(node[src][i] != par){
			temp = weight[src][i] + dfs(node[src][i], src);
			changefor(src, temp);
		}
	}
	return dp[src].ff;
}



int bfs(int root){

	queue<pii>Q;
	Q.push({root, -1});

	while(!Q.empty()){
		pii nowp = Q.front();
		Q.pop();
		int now = nowp.ff;
		for(int i = 0; i < node[now].size(); i++){
			int next = node[now][i];
			if(next != nowp.ss){
				if(dp[now].ff == dp[now].ss){
					changefor(next, dp[now].ff + weight[now][i]);
				}
				else{
					if(dp[next].ff + weight[now][i] == dp[now].ff) changefor(next, dp[now].ss + weight[now][i]);
					else changefor(next, dp[now].ff + weight[now][i]);
				}
				Q.push({next, now});
			}
		}
	}
	return 0;
}



void solve(){
    
    sc1(n);

    FOR(i, 0, n) node[i].clear(), weight[i].clear(), dp[i] = {0, 0};
    FOR(i, 0, n - 1) {
    	sc3(u, v, w);
    	node[u].pb(v);
    	node[v].pb(u);
		weight[u].pb(w);
		weight[v].pb(w);
    }


    dfs(0, -1);
    bfs(0);

    printf("Case %d:\n", t++);
    for(int i = 0; i < n; i++){
    	printf("%d\n", dp[i].ff);
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