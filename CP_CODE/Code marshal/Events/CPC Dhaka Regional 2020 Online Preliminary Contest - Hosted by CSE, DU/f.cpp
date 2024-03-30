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

const int maxn = 1e6;
vi v;
ll freq[maxn + 5], sq_freq[maxn + 5];

ll front_freq(int indx, int k){
    ll sum = sq_freq[indx + k] - sq_freq[indx] + (v[indx] * v[indx] * k) - (2 * v[indx] * (freq[indx + k] - freq[indx]));
    //cout << indx << " " << k << endl;
    return sum; 
}
ll back_freq(int indx, int k){
    ll sum = sq_freq[indx - 1] - sq_freq[indx - k - 1] + (v[indx] * v[indx] * k) - (2 * v[indx] * ( freq[indx - 1] - freq[indx - k - 1] ));
    return sum; 
}

int tc = 1;
void solve(){
    
    int n, k;

    sc2(n, k);
    v.clear();
    v.pb(0);
    for(int i = 0; i <= n; i++){
        freq[i] = 0;
        sq_freq[i] = 0;
    }
    int indx;
    for(int i = 1; i <= n; i++){
        int value, f;
        sc2(value, f);
        while(f--){
            v.pb(value);
        }

    }

    sort(all(v));


    for(int i = 1; i <v.size(); i++){
        freq[i] = freq[i - 1] + v[i];
        sq_freq[i] = sq_freq[i - 1] + v[i] * v[i];
    }

        
 
    ll sum = 0;

    for(int i = 1; i < k; i++){

        sum += front_freq(i, k - i);

    }
    ll mnsum = sum, cnt = 1;
    for(int i = 1, j = k + 1; j <= v.size(); i++, j++){
       // puts("HI");
        sum += (-front_freq(i, k - 1) + back_freq(j, k - 1) );
        //cout << sum << endl;
        if(sum == mnsum) cnt++;
        if(sum < mnsum){
            cnt = 1;
            mnsum = sum;
        }
    }

    printf("Case %d: %lld %lld\n", tc++, mnsum, cnt);


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