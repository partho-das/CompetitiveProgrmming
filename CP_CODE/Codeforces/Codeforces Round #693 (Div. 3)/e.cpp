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
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
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

struct node{
	int indx, ff, ss;
	node(){}
	node(int i, int nh, int nw){
		indx = i, ff = nh, ss = nw;
	}
};

bool cmp(node &a, node &b){
	return a.ff < b.ff || (a.ff == b.ff && a.ss < b.ss) || ( a.ff == b.ff && a.ss == b.ss && a.indx < b.indx);
}

const int maxn = 2e5;

void sovle(){

	int n;

	sc1(n);
	std::vector<node> v(n);
	vector<pii>  mnh(n), mnw(n), mv(n);
	vi h(n);

	for(int i = 0; i < n; i++){
		sc2(mv[i].ff, mv[i].ss);
		h[i] = mv[i].ff;
		v[i] = node(i + 1, mv[i].ff, mv[i].ss);
	}
	sort(all(v), cmp);
	sort(all(h));
	
	int mn = inf, indx = -1;
	for(int i = 0; i < n; i++){
		if(mn > v[i].ss){
			mn = v[i].ss;
			indx = v[i].indx;
		}
		mnw[i] = {indx, mn};
	}

	for(int i = 0; i < n; i++){
		int ck = -1;

		int indx = lower_bound(all(h), mv[i].ff) - h.begin();
		indx--;
		
		if(indx >= 0 && mnw[indx].ss < mv[i].ss){
			ck = mnw[indx].ff;
		}

		if(ck == -1){
			indx = lower_bound(all(h), mv[i].ss) - h.begin();
			indx--;
			if(indx >= 0 && mnw[indx].ss < mv[i].ff) {
				ck = mnw[indx].ff;
			}
		}

		printf("%d ", ck);
	}
		puts("");

}

int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test;

    sc1(test);

    while(test--){
    	sovle();
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