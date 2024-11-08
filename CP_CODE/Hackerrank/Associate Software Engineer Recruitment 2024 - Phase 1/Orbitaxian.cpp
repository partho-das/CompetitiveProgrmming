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

ll n, k;

void f(vector<deque<pll>> &dp, vector<ll> &sums, int indx, int i){
    while((int)dp[indx - 1].size() && i - dp[indx - 1][0].ff > k){
        sums[indx - 1] = ( sums[indx - 1] - dp[indx - 1][0].ss + MOD) % MOD ;
        dp[indx - 1].pop_front();
        // cout << sums[indx - 1] << endl;
    }
    dp[indx].pb({i, sums[indx - 1]});
    sums[indx] = ( sums[indx] + sums[indx - 1] + MOD) % MOD;
    
}
void solve(){
    scll(n, k);

    string str;
    cin >> str;
    
    vector<deque<pll>> dp(12);
    vector<ll>sums(12, 0);

    for(int i = 0; i < n; i++){
        if(str[i] == 'o'){
            dp[0].pb({i, 1});
            sums[0]++;
        }
        else if(str[i] == 'r'){
            f(dp, sums, 1, i);
            // cout << sums[1] << endl;

        }
        else if(str[i] == 'b'){
            f(dp, sums, 2, i);
        }
        else if(str[i] == 'i'){
            f(dp, sums, 3, i);
            f(dp, sums, 7, i);
        }
        else if(str[i] == 't'){
            f(dp, sums, 4, i);
        }
        else if(str[i] == 'a'){
            f(dp, sums, 5, i);
            f(dp, sums, 8, i);

        }
        else if(str[i] == 'x'){
            f(dp, sums, 6, i);

        }
        else if(str[i] == 'n'){
            f(dp, sums, 9, i);
        }
    }
    for(int i = 0; i < 10; i++){
    }
    cout << sums[9] << endl;
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


