#include <bits/stdc++.h>
#include <stdio.h>

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

ll find_cnt(vector<int>v){
	ll possum = 0;
	for(ll i = 1; i < v.size(); i++){
		ll mypos = i;
		ll now = v[i];
		int ev = 0, odd = 0;
		while(v[mypos] != mypos){
			ll diff = abs(v[mypos] - mypos);
			swap(v[mypos], v[ v[mypos] ]);
			possum++;
		}
		if(ev && odd) return -1; // good;
		// cout << now << endl << endl;
	}
	return possum;
}
void solve(){
	int n;
	sc1(n);

	vi a(n + 1, 0), b(n + 1, 0), as, bs;

	for(int i = 1; i <= n; i++){
		sc1(a[i]);
	}
	for(int i = 1; i <= n; i++){
		sc1(b[i]);
	}
	as = a;
	bs = b;
	int ck = 1;
	sort(as.begin() + 1, as.end());
	sort(bs.begin() + 1, bs.end());
	for(int i = 1; i <= n; i++){
		int pos = lower_bound(all(as), a[i]) - as.begin();
		a[i] = pos;
		pos = lower_bound(all(bs), b[i]) - bs.begin();
		b[i] = pos;
		if(as[i] != bs[i]) ck = 0;
		// cout << a[i] << " " << b[i] << endl;
	}


	if(!ck){
		cout << "NO" << endl;
		return;
	}
	// cout << " HI " << endl;
	ll acnt = find_cnt(a);
	ll bcnt = find_cnt(b);
	// cout << acnt << " " << bcnt << endl;
	if(abs(acnt - bcnt) % 2) ck = 0;
	// cout << acnt << " " << bcnt  << endl;
	if(ck || acnt < 0 || bcnt < 0) puts("YES");
	else puts("NO");


}



int main() {
   
    //FastIO;
     #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\IO\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\IO\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    int test = 1;

    sc1(test);


    while(test--){
        solve();
    }
    // puts("HI");

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

