//https://codeforces.com/contest/1547/problem/F
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

int mx_primediv[maxn + 5];
void prime_gen(){

    for(int i = 2; i <= maxn; i++){
        if(!mx_primediv[i])
        for(int j = i; j <= maxn; j += i){
            mx_primediv[j] = i;
        }
    }
    for(int i = 0; i <= maxn; i++){
        if(!mx_primediv[i]) mx_primediv[i] = i;
    }

}
void solve(){
    
    int n;
    sc1(n);

    vi v(n);
    int common = 0;
    for(int i = 0; i < n; i++){
        sc1(v[i]);
        common = gcd(v[i], common);
    }

    for(int i = 0; i < n; i++){
        v[i] /= common;
    }

    vector<set<int>> fact(n);

    for(int i = 0; i < v.size(); i++){
        while(mx_primediv[ v[i] ] != 1){
            fact[i].insert( mx_primediv[ v[i] ]);
            v[i] /= mx_primediv[v[i]]; 
        }
    }
    //cout << v[i] << " " << mx_primediv[ v[i] ] << endl;
    
    ll res = 0;

    for(int i = 0; i < n; i++){
        for(auto it : fact[i]){
            ll cnt = 1, l = i - 1, r = i + 1;
            if(l < 0) l = n - 1;
            r = r % n;
            //fact[i].erase(it);
            while( l != i && fact[l].count(it) > 0){
                cnt++;
                fact[l].erase(it);
                l--;
                if(l < 0) l = n - 1;
            }
            while( r != i && fact[r].count(it) > 0){
                cnt++;
                fact[r].erase(it);
                r++;
                r = r % n;
            }
            //cout << it << " " << l << " " << r << endl;

            res = max(cnt, res);
        }
        fact[i].clear();
    }

    cout << res << endl;

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
//https://codeforces.com/contest/1547/problem/F