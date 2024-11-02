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

vi vr;
int find_min(int add, int sm, int mx){
    // cout << sm << " " << mx << " " << add << endl;
    int diff = mx - sm;
    int mul = (mx - sm) / add;
    int c = abs(mx - (sm + mul * add + add)) ;

    int b = diff % add;
    // cout << diff << " " << b << " " << c << endl; 
    if(diff <= b && diff < c){
        vr.pb(sm);
    }
    else if(b < diff && b <= c){
        vr.pb(sm + (add * mul));
    }
    else{
        // cout << sm + (add * mul)<< endl; 
        vr.pb(mx + c);
    }
    // cout << diff << " " << mx - (sm + mul * add + add) << endl;
    return min({diff, b, c});
}
int f(int a, int b, int gcdv, int val, int mx){
    int mn = min({find_min(gcdv, val, mx)});
    return mn;
}
void solve(){
	
    int n, a, b;
    sc3(n, a, b);

    vi v(n);
    vr.clear();
    int mx = 0;
    for(int i = 0; i < n; i++){
        sc1(v[i]);
        mx = max(mx, v[i]);
    }
    int gcdv = gcd(a, b);
    int res = 0;

    for(int i = 0; i < n; i++){
        res = max(res, f(a, b, gcdv, v[i], mx));
        // break;
    }
    sort(all(vr));
    res = vr.back() - vr.front();
    cout << res << endl;

    return;
}



int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/Code/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/Code/IO/output.txt","w",stdout);
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




