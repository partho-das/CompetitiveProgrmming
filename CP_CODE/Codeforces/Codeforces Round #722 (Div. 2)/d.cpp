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

const int maxn = 1e7;
bool isprime[maxn + 2];
map<ll, int> freq;
vll primes, fact;
set<ll> v; 

void f(int pos, ll agent){
    if(pos == fact.size()){
        v.insert(agent);
        return;
    }
    int lim = freq[ fact[pos] ];
    ll ex = 1;
    f(pos + 1, agent);
    for(int i = 0; i < lim; i++){
    //cout << pos << " " << agent << " " <<  fact[pos] << " " << 0<< endl;
        f(pos + 1, agent * ex * fact[pos]);
        ex *= fact[pos];
    }
    return;
}

void gen(){

    for(int i = 3; i * i <= maxn; i+= 2){
        if(isprime[i] == 0)
        for(int j = i * i; j <= maxn; j += i){
            isprime[j] = 1;
        }
    }

    primes.pb(2);
    for(int i = 3; i <= maxn; i += 2){
        if(isprime[i] == 0) primes.pb(i);
    }

    //cout << primes.size() << endl;
}
int tc = 1;
void solve(){
    
    ll n;
    scl(n);
    freq.clear();
    fact.clear();
    v.clear();
    ll cnt = 0, sum = 0, i = 1, agent = 1;

    while(n % 2 == 0){
        agent *= 2;
        if(n % (agent * 2)) break;
    }
    //cout << agent << endl;
    ll nc = n;
    for(int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++){
        if(n % primes[i] == 0){
            fact.pb(primes[i]);
            while(n % primes[i] == 0){
                freq[primes[i]]++;
                n /= primes[i];
            }
        }
    }
    if(n > 1){
        freq[n]++;
        fact.pb(n);
    }

    f(0, 1);

    n = nc;
    //cout << v.size() << endl;
    for(auto it : v){
        if(it & 1 && (it * it + it) / 2 <= n && (it * it + it) / 2 > 0) cnt++;
        //cout << it << " " << cnt << endl;
        if(it % agent == 0) {
            it *= 2;
            if( (it * it + it) / 2<= n && (it * it + it) / 2 > 0) cnt++;
        }
    }
    cnt--;
    

    
    printf("Case %d: %lld\n", tc++, cnt);
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
    gen();
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