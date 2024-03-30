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
const int MOD  = 10007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
template <class T> T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline string to_string(const pair<T,T> &p) {
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";  
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________


namespace Matrix_Expo_Utils {
    #define Matrix_Type int
    #define Matrix      vector<vector<Matrix_Type>>

    inline Matrix identity(int n){
        Matrix temp;
        temp.resize(n, vector<Matrix_Type>(n, 0));
        for(int i = 0; i < n; i++){
            temp[i][i] = 1;
        }
        return temp;
    }

    inline Matrix operator *(Matrix x, Matrix y) {
        Matrix temp;

        temp.resize(x.size(), vector<Matrix_Type>(y[0].size(), 0));
        if(x[0].size() != y.size()){
            
            return identity(x.size());
        }

        for(int i = 0; i < x.size(); i++){
            for(int j = 0; j < y[0].size(); j++){
                temp[i][j] = 0;
                for(int k = 0; k < y.size(); k++){
                    temp[i][j] = (temp[i][j] + x[i][k] * y[k][j]) % MOD;
                }
            }
        }
        
        return temp;
    }

    Matrix operator ^(Matrix b, ll p) {
        if(p <= 0) {
           return identity(b[0].size());
        }
        Matrix x = b; 

        if(p & 1) 
            return (x * (b ^ (p - 1))); 
        x = b ^ (p >> 1);
        return (x * x);
    }
};


int t = 1;
void solve(){

    using namespace Matrix_Expo_Utils;
    int n, a, b, c;
    sc1(n);
    sc3(a, b, c);

    if(n <= 2){
        printf("Case %d: %d\n", t++, 0);
        return;
    }
    Matrix multiplicand{
        {a, 0, b, c},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1}
    };
    Matrix base{
                {0}, 
                {0},
                {0},
                {1}
            };
    multiplicand = multiplicand ^ (n - 2);   
    Matrix res = multiplicand * base;
   printf("Case %d: %d\n", t++, res[0][0]);
   
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