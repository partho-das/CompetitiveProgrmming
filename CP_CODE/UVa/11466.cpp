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
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline double my_sqrt(T n)
{
    double high = n + 5, low = 0, mid, ans;
    int cnt = 100;
    while(cnt--)
    {
        mid = low + (high - low) / 2;
        if(mid * mid <= n) ans = mid, low = mid;
        else high = mid;
    }
    return ans;
}
template <class T> inline T bigmod(T b, T p)
{
    if(p <= 0 || b == 0) return 1;
    ll x = b;
    if(p & 1) return (x * bigmod(b, p - 1)) % MOD;
    x = bigmod(b, p >> 1);
    return (x * x) % MOD;
}
template <class T> inline string to_string(const pair<T,T> &p)
{
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________
const int maxn = 1e7;
bitset<maxn + 5> isprime;
vll primes;
void prime_gen()
{
    for(int i = 1; i <= maxn; i++){
        isprime[i] = 0;
    }

    for(int i = 3; i * i <= maxn; i+= 2){
        if(!isprime[i])
            for(int j = i * i; j <= maxn; j += i){
                isprime[j] = 1;
            }
    }

    primes.pb(2);

    for(int i = 3; i <= maxn; i += 2) {
        if(!isprime[i]) primes.pb(i);
    }


    return;

}

using u64 = uint64_t;
using u128 = __uint128_t;
u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
            base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2) return false;
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}


ll n;
void solve()
{

    if(n < 0) n *= -1;

    if(MillerRabin(n)){
        puts("-1");
        return;
    }
    else{
        ll res = 1, cnt = 0;

        //cout << n << endl;
        for(int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++){
            if(n % primes[i] == 0){
                res = max(res, primes[i]);
                cnt++;
                while(n % primes[i] == 0){
                    n /= primes[i];
                }
            }
        }
        if(n > 1){
            cnt++;
            res = max(res, n);
        }
        if(cnt >= 2) printf("%lld\n", res);
        else puts("-1");
    }


    return;
}



int main()
{
#ifdef PARTHO
    freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
    freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
    //FastIO;

    int test = 1;

    prime_gen();

    //sc1(test);

    while(1)
    {
        scl(n);

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
