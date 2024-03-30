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
#define FOR(i,a,n)   for( ll i = a; i < n; i++)
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r){
    int diff = r - l + 1;
    return l + rng() % diff;
}


bool ispal(char *str){
    int len = strlen(str);

    for(int i = 0, j = len - 1; i < j; i++, j--){
        if(str[i] != str[j]) return 0;
    }
    return 1;
}

int mxint = 2147483647, maxn = 4e5;
void solve(){



    //sc2(n, q);

    // n = min(n, maxn);
    // q = min(q, maxn);

    // vi v(n), sv(n), qv(q);

    // int l = 1, r = get_rand(1, mxint);
    // if(l > r) swap(l, r);

    // for(int i = 0; i < n; i++){
    //    v[i] = get_rand(l, r);
    // }

    // int indx = 0;
    // for(int i = 0; i < q; i++){
    //     int cmd = rng() % 2;
    //     if(cmd && sv.size()){
    //        qv[indx++] = v[ get_rand(0, n - 1) ];
    //     }
    //     else{
    //         qv[indx++] = get_rand(l, r + 10000);
    //     }
    // }


    // printf("%d\n", n);
    // sort(all(v));
    // for(int i = 0; i < v.size(); i++){
    //     printf("%d", v[i]);
    //     if(i == n - 1) puts("");
    //     else printf(" ");
    // }
    // //printf("%d\n", q);

    // for(int i = 0; i < qv.size(); i++){
    //     printf("%d", qv[i]);
    //     if(i == n - 1) puts("");
    //     else printf(" ");
    // }
    int t = 1000000;
    cout << t * 2 << endl;
    ll n = 10000000 - 2000000;
    while(t--){
            cout << 1 << " " << n * n << endl << 1 << " " << n * n + 1 << endl;
            n--;
            // while(1){
            //     int value = get_rand(1, n);
            //     if(taken.find(value) == taken.end()) {
            //         taken.insert(value);

            //         cout << value << " ";

            //         break;
            //     }
            // }            

       
         
        
    }
    return;
 }


int main() {
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\OneDrive\\Desktop\\IO\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\OneDrive\\Desktop\\IO\\input.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    //sc1(test);

    while(test--){
        solve();
    }
    #ifdef PARTHO
        //int end_time = clock();
        //printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1