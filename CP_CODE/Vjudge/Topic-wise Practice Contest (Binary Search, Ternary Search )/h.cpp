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
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________
void print_point(pair<double, double> a){
    printf("%lf %lf\n", a.ff, a.ss);

}
double distance(pair<double, double> a, pair<double, double> b){
	return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}

pair<double, double> ret_pos(pair<double, double> a, pair<double, double> b, double r, double now){
	pair<double, double> p = a;
	if(!r) return p;


	p.ff = a.ff + ((b.ff - a.ff) / r) * now;
	p.ss = a.ss + ((b.ss - a.ss) / r) * now;
	return p;
}
int tc = 1;
void solve(){
    
    vector<pair<double, double>> point(4);

    for(int i = 0; i < 4; i++){
    	scanf("%lf%lf", &point[i].ff, &point[i].ss);

    }

    double r1 = distance(point[0], point[1]), r2 = distance(point[2], point[3]);

    double low = 0, high = r1, mid1, mid2, d1, d2;
    
    int cnt = 200;
    while(cnt--){
    	mid1 = low + (high - low) / 3;
    	mid2 = high - (high - low) / 3;
    	
    	pair<double, double> p1_m1{0, 0}, p2_m1{0, 0}, p1_m2{0, 0}, p2_m2{0, 0};

    	p1_m1 = ret_pos(point[0], point[1], r1, mid1);
    	p2_m1 = ret_pos(point[2], point[3], r2, mid1 * (r2 / r1));

    	p1_m2 = ret_pos(point[0], point[1], r1, mid2);
    	p2_m2 = ret_pos(point[2], point[3], r2, mid2 * ((r2 / r1)));

    	d1 = distance(p1_m1, p2_m1), d2 = distance(p1_m2, p2_m2);

    	if(d1 <= d2){
    		high = mid2;
    	}
    	else low = mid1;

    }

    printf("Case %d: %.6lf\n", tc++, my_sqrt(d1));


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