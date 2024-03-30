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


ll Get(vi &parents, ll a){
    return parents[a] = (parents[a] == a ? a : Get(parents, parents[a]));
}


void Union(vi &parents, vi &rank, int a, int b){
    a = Get(parents, a), b = Get(parents, b);
    if(rank[a] == rank[b]) rank[a]++;
    if(rank[a] > rank[b]) parents[b] = a;
    else parents[a] = b; 
}

void solve(){
    
    int n, m, k;

    sc3(n, m, k);

    vi parents(n + 1);
    vi rank(n + 1, 1);

    FOR(i, 0, n + 1){
        parents[i] = i;
    }
    FOR(i, 0, m){
        int a, b;
        cin >> a >> b;
    }

    std::vector<pii> queary_value(k);
    std::vector<int> queary_type(k);

    FOR(i, 0, k){
        string str;
        cin >> str;
        int a, b;
        cin >> a >> b;

        queary_value[i] = {a,  b};
        if(str == "cut") queary_type[i] = 1;
        else queary_type[i] = 2;
    }
    reverse(all(queary_type));
    reverse(all(queary_value));

    std::vector<string> res;

    FOR(i, 0, k){
        if(queary_type[i] == 1){
            Union(parents, rank, queary_value[i].ff, queary_value[i].ss);
        }
        else{

            int a = Get(parents, queary_value[i].ff);
            int b = Get(parents, queary_value[i].ss);
            if(a == b) res.pb("YES");
            else res.pb("NO");
        }
    }


    reverse(all(res));
    for(auto it : res) cout << it << " ";
    puts("");
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