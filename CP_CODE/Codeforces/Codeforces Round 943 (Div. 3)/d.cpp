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

void solve(){
    
    int n, k, pa, pb;

    sc2(n, k);
    sc2(pa, pb);

    vi a(n + 1), p(n + 1), visita(n + 1, 0), visitb(n + 1, 0);

    for(int i = 1; i <= n; i++){
        sc1(p[i]);
    } 
    for(int i = 1; i <= n; i++){
        sc1(a[i]);
    }
    pair<ll, ll> sa, sb;

    sa = {0, 0};
    sb = {0, 0};

    for(int i = 1; i <= k; i++){
        ll rem = k - i;
        sa.ff += a[pa];
        // cout << visita[pa] << " " << k << endl;
        // return;
        sa.ss = max(sa.ss, sa.ff + a[pa] * rem); 
        visita[pa] = 1;
        pa = p[pa];
        if(visita[pa]) break;

    }
    sa.ff = max(sa.ff, sa.ss);


     for(int i = 1; i <= k; i++){
        ll rem = k - i;
        sb.ff += a[pb];
        sb.ss = max(sb.ss, sb.ff + a[pb] * rem); 
        visitb[pb] = 1;
        pb = p[pb];
        if(visitb[pb]) break;
    }
    sb.ff = max(sb.ff, sb.ss);

    if(sa > sb) printf("Bodya\n");
    else if(sa < sb) printf("Sasha\n");
    else printf("Draw\n");


    return;
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

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

