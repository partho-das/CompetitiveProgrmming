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

const int maxn = 2e5;
int taken[maxn + 5], n;
void find_graph(int par, int size, int last){
    if(!taken[0]){
        puts("YES");
        taken[0] = 1;
    }
    if(size == 1){
        printf("%d %d\n", par, last);
        return;
    }

    for(int i = par + 1; i <= n; i++){
        if(i != 2 && i != 3 && !taken[i]){
            printf("%d %d\n", par, i);
            taken[i] = 1;
            find_graph(i, size - 1, last);
            return;
        }
    }
    return;
}
void solve(){
 
    int v12, v13, v23;

    sc1(n);
    sc3(v12, v23, v13);
    for(int i = 0; i <= n; i++){
        taken[i] = 0;
    }
    int ck = 1;
    if(v12  + v13 == v23){
        if(v23 + 1 > n){
            ck = 0;
        }
        else{
            find_graph(1, v12, 2);
            find_graph(1, v13, 3);
        }
    }
    else if(v12 + v23 == v13 || v13 + v23 == v12){
        if(v12 + v23 == v13){
            if(v13 + 1 > n){
                ck = 0;
            }
            else{
                find_graph(1, v12, 2);
                find_graph(2, v23, 3);
            }
        }
        else if(v13 + v23 == v12){
            if(v12 + 1 > n){
                ck = 0;
            }
            else{
                find_graph(1, v13, 3);
                find_graph(3, v23, 2);
            }
        }
    }
    else{

        int edge = min(v12, v13) + v23 - 1;
        //cout << edge << endl; 
        if(edge + 1 > n || (min(v12, v13) - 1 +  v23 - 1) != max(v12, v13) ){
            ck = 0;
        }
        else{
            if(v12 < v13){
                find_graph(1, v12, 2);
                int pos = v12 + 1 + 1;
                find_graph(pos, v23 - 1, 3);
            }
            else{
                find_graph(1, v13, 3);
                int pos = v13 + 1 + 1;
                find_graph(pos, v23 - 1, 2);
            }
        }
    }

    if(!ck){
        puts("NO");
    }
    else{
        for(int i = 4; i <= n; i++){
            if(!taken[i]){
                printf("1 %d\n", i);
            }
        }
    }

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