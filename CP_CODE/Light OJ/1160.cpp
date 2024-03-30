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


namespace Matrix_Expo_Utils {
    #define Matrix_Type ll
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


vi sevC4;
Matrix multiplicand;


void comb_gen(int pos, int cnt, int value){
    if(pos == 7){
        if(cnt == 4){
            sevC4.pb(value);
        }
        return;
    }

    if(cnt < 4){
        comb_gen(pos + 1, cnt + 1, value | (1 << pos));
    }
    if((7 - pos) - 1 >= (4 - cnt)){
        comb_gen(pos + 1, cnt, value);
    }
    return;
}

void ValMoveGen(int pos, int cnt, int myvalue, int nowvalue){
    if(pos == 7){
        int x = lower_bound(all(sevC4), myvalue) - sevC4.begin(), y = lower_bound(all(sevC4), nowvalue) - sevC4.begin();
        multiplicand[x][y] = 1;
        return;
    }

    if(myvalue & (1 << pos)){
        if(pos != 0){
            if( !(nowvalue & ( 1 << (pos - 1))) ){
                ValMoveGen(pos + 1, cnt + 1, myvalue, nowvalue | 1 << (pos - 1));
            }
        }
        if(pos != 6){
             ValMoveGen(pos + 1, cnt + 1, myvalue, nowvalue | 1 << (pos + 1));
        }
    }
    else ValMoveGen(pos + 1, cnt , myvalue, nowvalue);
}
void resource_gen(){
    comb_gen(0, 0, 0);
    sort(all(sevC4));
    multiplicand.resize(35, vector<Matrix_Type>(35, 0));
    for(auto it : sevC4){
        ValMoveGen(0, 0, it, 0);
    }
 
    return;
}
int tc = 1;
void solve(){
    using namespace Matrix_Expo_Utils;

    int n;
    sc1(n);

    Matrix basematrix(35, vll(1, 1));
    int sum = 0;
    for(int i = 0; i < 7; i++){
        int value;
        sc1(value);
        if(value) sum |= (1 << i);
    }


    
    Matrix multiplicand2 = multiplicand ^ (n - 1);

    Matrix res = multiplicand2 * basematrix;
    int indx = lower_bound(all(sevC4), sum) - sevC4.begin();
    
    printf("Case %d: %lld\n", tc++, res[indx][0]);

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

    resource_gen();
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