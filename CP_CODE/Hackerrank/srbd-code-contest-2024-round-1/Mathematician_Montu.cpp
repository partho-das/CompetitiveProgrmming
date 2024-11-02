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

const int maxn = 1e6;
bitset<maxn + 5>trackPrime(0);
vector<ll>primes;
void prime_gen(){
    for(int i = 3; i * i <= maxn; i += 2){
        if(!trackPrime[i]){
            for(int j = i * i; j <= maxn; j += 2 * i){
                trackPrime[j] = 1;
            }
        }
    }
    primes.pb(2);

    for(int i = 3; i <= maxn; i += 2){
        if(!trackPrime[i]) primes.pb(i);
    }
    return;
}
int tc = 1;
void solve(){

    ll n, q, ncpy;
    scll(n, q);
    ncpy = n;

    unordered_map<long long, int> prime_freq, temp;

    for(int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= n; i++){
        while(n % primes[i] == 0){
            n /= primes[i];
            prime_freq[primes[i]]++;
        }
    }
    if(n > 1) prime_freq[n]++;

    n = ncpy;


    // for(auto it : prime_freq){
    //     cout << it.ff << " " << it.ss << endl;
    // }
    printf("Case %d:", tc++);
    while(q--){
        ll m, mcpy;
        scl(m);
        mcpy = m;
        if(n % m == 0){
                // cout <<  " m = " << m << endl;
            temp = prime_freq;
            for(auto &p : temp){
                while(m % p.ff == 0) m /= p.ff, p.ss--;
            }

            ll phi = n / mcpy;
            for(auto p : temp){
                if(p.ss > 0){
                    phi = (phi / p.ff) * (p.ff - 1);
                    // cout << p.ff << " " << p.ss << " " << m << endl;
                }
            }
            printf(" %lld", phi);
        }
        else{
            printf(" 0");
        }
    }
    puts("");
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

    prime_gen();

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


