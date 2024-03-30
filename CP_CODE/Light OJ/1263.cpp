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

const int maxn = 1000;
int t = 1, wight[maxn + 5], par[maxn + 5], childWeightsum[maxn + 5], childcnt[maxn + 5];

int get(int x){
	return par[x] < 0 ? x : par[x] = get(par[x]);
}
void update(int a, int b){
	a = get(a), b = get(b);
	if(a == b) return;

	if(par[a] > par[b]) swap(a, b);
	par[a] += par[b];
	par[b] = a;
	return;
}
void solve(){
    
    int n, m;
    sc2(n, m);


    for(int i = 0; i < n; i++){
    	sc1(wight[i + 1]);
    	par[i + 1] = -1;
    	childWeightsum[i + 1] = 0;
    	childcnt[i + 1] = 0;
    }
    
    for(int i = 0; i < m; i++){
    	int u, v;
    	sc2(u, v);
    	update(u, v);
    }
    for(int i = 1; i <= n; i++){
    	int x = get(i);
    	childcnt[x]++;
    	childWeightsum[x] += wight[i];
    }

    int ck = 1, psum = -1;

    for(int i = 1; i <= n; i++){
    	if(childcnt[i]){
    		if(childWeightsum[i] % childcnt[i]){
    			ck = 0;
    			break;
    		}

    		if(psum == -1) psum = childWeightsum[i] / childcnt[i];
    		else if(psum != childWeightsum[i] / childcnt[i]){
    			ck = 0;
    			break;
    		} 
    	}
    }

    if(ck){
    	printf("Case %d: Yes\n", t++);
    }
    else {
        printf("Case %d: No\n", t++);
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