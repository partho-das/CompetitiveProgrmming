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
    
    int n, a, b;

    sc3(n, a, b);

    vi v(n);
    int ck = 0; // ck == 0 means YES
    //if(n & 1) ck = 1;
    map<int, int> freq, taken; 
    FOR(i, 0, n){
        sc1(v[i]);
        freq[v[i]] = 1;
    }

    for(int i = 0; i < n; i++){
        if(!freq[a - v[i]] && !freq[b - v[i]]) {
            ck = 1;
        }
        taken[v[i]] = 1;
    }

    if(ck){
        puts("NO");
        return;
    }

    FOR(i, 0, n){
        freq[v[i]] = 0;
    }
    vi vc = v;
    sort(all(v));
    reverse(all(v));

     for(int i = 0; i < n; i++){
        if(taken[v[i]]){
            if(taken[a - v[i]] && taken[b - v[i]] && a != b) continue;
            else if(taken[a - v[i]]){
            //cout <<  taken[v[i]] << endl;
                taken[a - v[i]] = 0;
                taken[v[i]] = 0;
                freq[v[i]] = 0;
                freq[a - v[i]] = 0;
                int x = b - (a - v[i]);
                 while(taken[x]){
                    int y = a - x;
                    int xc = x;
                    if(taken[y]){
                        taken[x] = 0;
                        taken[y] = 0;
                        freq[x] = 0;
                        freq[y] = 0;
                    }
                    x = b - y;
                    if(xc == x) break;
                }
            }
            else if(taken[b - v[i]]){
                taken[b - v[i]] = 0;
                taken[v[i]] = 0;
                freq[v[i]] = 1;
                freq[b - v[i]] = 1;
                int x = a - (b - v[i]);
                while(taken[x ]){
                    int y = b - x;
                    int xc = x;
                    if(taken[y]){
                        taken[x] = 0;
                        taken[y] = 0;
                        freq[x] = 1;
                        freq[y] = 1;
                    }
                    x = a - y;
                    if(xc == x) break;
                //cout << taken[x] << " " << y << endl;
                }
            }
        }
    }




    for(int i = 0; i < n; i++){
        if(taken[v[i]]) ck = 1;
    } 
    if(ck ) puts("NO");
    else{
        puts("YES");
        FOR(i, 0, n){
            cout << freq[vc[i]] << " ";
        }
        puts("");
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

    //sc1(test);

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