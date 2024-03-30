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

int lim = 100000031;
const int maxn = 3125000;
unsigned int primes[3125005], qsum[3125005];

void primegen_bitmask(){
    memset(primes, 0, sizeof primes);

    
    for(unsigned int i = 3; i * i <= lim; i += 2){
        if( !(primes[i >> 5] & (  1ll << (i & ((1ll << 5) - 1)))) ){
            for(unsigned int j = i * i; j <= lim; j += i){
                primes[j >> 5] |= (1ll << (j & (( 1ll << 5)  - 1)));
            }
        }
    }
    primes[0] |= 2;
    for(unsigned int i = 0; i <= maxn; i++){
        for(unsigned int j = 0; j <= 31; j++){
            if(!(j & 1)) primes[i] |= (1ll << j); 
        }
    }
    primes[0] &= ~4;

    //cout << primes[0] << endl; 
    int cnt = 0;
    for(int i = 0; i <= maxn; i++){
        cnt = 0;
        for(int j = 0; j <= 31; j++){
            cnt += (primes[i] & (1 << j)) == 0;
        }
        qsum[i] = cnt;
        if(i != 0) qsum[i] += qsum[i - 1];
        //cout << cnt << " " << qsum[i] << endl;
    }

    return;
}

int n;
void solve(){
    int indx = n >> 5, ex = (n & ((1 << 5) - 1));

    int cnt = 0;
    if(indx != 0) cnt += qsum[indx - 1];


    for(int i = 0; i <= ex; i++){
        cnt += (primes[indx] & (1 << i)) == 0;
        //cout << sum << endl;
    }
    
    double perc = abs(cnt - n/log(n))/double(cnt) * 100;

    printf("%.1lf\n", perc);



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

    //sc1(test);

    primegen_bitmask();

    while(1){
        sc1(n);
        if(!n) break;
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