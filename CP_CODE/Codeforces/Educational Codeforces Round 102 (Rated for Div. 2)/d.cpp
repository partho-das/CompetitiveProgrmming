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

const int maxn = 2e5;
struct node
{
	int value = 0, ps = 0, ms = 0;
	node(){}
	node(int a, int b, int c){
		value = a;
		ps = b;
		ms = c;

	}
};

int mfreq[maxn + 5], pfreq[maxn + 5];

void solve(){
    
    int n, m;

    sc2(n, m);
    string str;
    cin >> str;
    std::vector<pii> q(m);
    std::vector<node> v(n + 1);

    for(int i = 0; i < m; i++){
    	sc2(q[i].ff, q[i].ss);
    }

   int cnt = 0, mx = 0, mn = 0, res = 0;
   v[0] = node(0, 0, 0);
   for(int i = 1; i <= n; i++){
	   	if(str[i - 1] == '+')cnt++;
	   	else cnt--;

	   	mn = min(mn, cnt);
	   	mx = max(mx, cnt);
	   	v[i] =  node(cnt, mx, mn);
   }

   int pls = 0, mns = 0;
   for(int i = n - 1; i >= 0; i--){
   		if(str[i] == '+') pls++, mns--;
   		else mns++, pls--;
   		mns = max(0, mns);
   		pls = max(0, pls);
   		mfreq[i + 1] = mns;
   		pfreq[i + 1] = pls;
	   	//cout << pls << " " << mns << endl;
   }
   mfreq[n + 1] = pfreq[n + 1] = 0;

   for(int i = 0; i < m; i++){
   		int l = q[i].ff, r = q[i].ss;
   		mx = v[l - 1].ps, mn = v[l - 1].ms;
   		mx = max(mx, v[l - 1].value + pfreq[r + 1]);
   		mn = min(mn, v[l - 1].value - mfreq[r + 1]);
   		printf("%d\n", abs(mx - mn) + 1);
   }

   //puts("");

 

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
    //cout << test << endl;
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