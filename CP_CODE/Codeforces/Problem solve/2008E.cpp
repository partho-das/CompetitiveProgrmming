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

    int n;
    sc1(n);
    string str;
    
    cin >> str;
    
    vector<int>v[2], prefv[2];
    v[0].resize(26);
    v[1].resize(26);
    for(int i = 0; i < 26; i++){
        v[0][i] = v[1][i] = 0;
    }
    prefv[0] = v[0];
    prefv[1] = v[1];

    for(int i = 0; i < n; i++){
        v[i & 1][str[i] - 'a']++;
    }
    int res = inf;
    if(n % 2 == 0){
        sort(all(v[0]));
        sort(all(v[1]));
        res = n - (v[0].back() + v[1].back());
    }
    else{

        for(int i = 0; i < n; i++){
            v[i & 1][str[i] - 'a']--;
            
            vector<int> tempv[2];
            tempv[0] = prefv[0], tempv[1] = prefv[1];

            for(int j = 0; j < 26; j++){
                tempv[0][j] += v[1][j];
                tempv[1][j] += v[0][j]; 
            }
            sort(all(tempv[0]));
            sort(all(tempv[1]));
            res = min(res, n - (tempv[0].back() + tempv[1].back() ));

            prefv[i & 1][str[i] - 'a']++;
        }
    }

    cout << res << endl;
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


