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
const int maxn = 1e6 + 10;

std::vector<int>prime_divisor[maxn + 2];
std::vector<int> primes;
int visit[maxn + 5], n;

void prime_generate(){


    for(ll i = 3; i * i <= maxn; i+= 2){
        if(!visit[i]){
            for(ll j = i * i; j <= maxn; j += i){
                visit[j] = 1;
            }
        }
    }

    primes.pb(2);
    for(int i = 3; i <= maxn; i += 2){
        if(!visit[i]){
            primes.pb(i);
        }
    }
    for(int i = 0; i < primes.size(); i++){
        for(int j = primes[i]; j <= maxn; j += primes[i]){
            //if(j == 10){

            int cnt = 0;
            int value = j;
            while(value % primes[i] == 0) cnt++, value /= primes[i];
            if(cnt & 1) prime_divisor[j].pb( primes[i] );
        }
    }
}


void solve(){


    sc1(n);
    int value;
    map<vi, int>freq;
    int mx = 0;
    for(int i = 0; i < n; i++){
        sc1(value);

        mx = max( ++freq[ prime_divisor[value] ], mx);
    }
    vi res(2);
    res[0] = mx;
    int q;
    sc1(q);
    std::vector<ll> query(q);

    for(int i = 0; i < q; i++){
        scl(query[i]);
    }
    int cnt = 0;
    vi v;
    int add = freq[v] ;
    if((add & 1)) cnt += add;

    for(auto it : freq){
         add = it.ss;
        if( !(add & 1) ) cnt += add;
    }
    freq.clear();
    res[1] = max(cnt, mx);
    int c = 2;
    for(int i = 0; i < q; i++){
        if(query[i] >= 1) printf("%d\n", res[1]);
        else printf("%d\n", res[ 0 ]);
    }


    return;
}



int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    sc1(test);

    prime_generate();
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