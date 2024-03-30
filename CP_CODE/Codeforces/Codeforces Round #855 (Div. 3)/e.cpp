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

int par[maxn + 5], n;


int get(int x){
	return par[x] < 0 ? x : par[x] = get(par[x]);
}
int update(int u, int v){

	if(v >= n) return 0;

	u = get(u), v = get(v);

	if(u == v) return 0;

	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return 1;
}

vector<string>group(maxn + 5), group2(maxn + 5);

void solve(){
	
	int k;
	sc2(n, k);


	for(int i = 0; i <= n; i++){
		par[i] = -1;
		group[i].clear();
		group2[i].clear();

	}
	string str, t;
	cin >> str >> t;

	for(int i = 0; i < n; i++){
		update(i, i + k);
		update(i, i + k + 1);
	}


	for(int i = 0; i < n; i++){
		int p = get(i);
		
		group[p].pb(str[i]);
		group2[p].pb(t[i]);

	}

	int ck = 1;
	for(int i = 0; i < n; i++){
		sort(all(group[i]));
		sort(all(group2[i]));

		if(group2[i] != group[i]){
			ck = 0;
			break;
		}

	}

	puts(ck ? "YES" : "NO");


	return;
}


int main() {
     #ifdef PARTHO
        freopen("/home/partho/Desktop/CODEFORCES/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/CODEFORCES/IO/output.txt","w",stdout);
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
