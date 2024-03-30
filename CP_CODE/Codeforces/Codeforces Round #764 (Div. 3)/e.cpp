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

bool cmp(pair<pair<string, int> , pii> &a, pair<pair<string, int> , pii> &b){

    return a.ff.ff < b.ff.ff;
}

pair<pii , pii> findv(string str, vector<pair<pair<string, int> , pii>> &v){
    int low = 0, high = v.size() - 1, mid, pos = -1;

    while(low <= high){
        mid = (high + low) / 2;
        
        if(v[mid].ff.ff == str){
            pos = mid;
            break;
        }
        else if(v[mid].ff.ff < str) low = mid + 1;
        else high = mid - 1;
    }

    if(pos != -1){
        return {{1, v[pos].ff.ss}, {v[pos].ss.ff, v[pos].ss.ss}};
    }
    else{
        return {{-2, v[pos].ff.ss}, {v[pos].ss.ff, v[pos].ss.ss}};
    }
}



void solve(){
    
    int n, m;

    sc2(n, m);
    vector<pair<pair<string, int> , pii>>v;


    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < (int)str.size() - 2; j++){
            v.pb({{str.substr(j, 3), i}, {j + 1, j + 2 + 1}});
        }

        for(int j = 0; j < (int)str.size() - 1; j++){
            v.pb({{str.substr(j, 2), i}, {j + 1, j + 1 + 1}});
        }
    }
    cin >> str;

    sort(all(v), cmp);

    vector< pair<pii, pii> > res((int)str.size());

    for(int i = 0; i < res.size(); i++){
        res[i].ff.ff = -1;
    }

    
    for(int i = 1; i < (int)str.size(); i++){
        if(i != 2){
            int pos = i - 2 + 1;
            if(pos != 0){
                if(res[pos - 1].ff.ff == -2) {
                res[i].ff.ff = -2;
               } 
            }
            if(res[i].ff.ff != -2){
                res[i] = findv(str.substr(pos, 2), v);
                if(res[i].ff.ff == 1) res[i].ff.ff = pos - 1;
            }
        }
            
        if( i == 2 || (i > 3 && res[i].ff.ff == -2) ){
            int pos = i - 3 + 1;
            if(pos < 0) continue;

            res[i].ff.ff = -1;
            if(pos != 0){
               if(res[pos - 1].ff.ff == -2) {
                res[i].ff.ff = -2;
               }
            }

            if(res[i].ff.ff != -2) {
                res[i] = findv(str.substr(pos, 3), v);
                if(res[i].ff.ff == 1) res[i].ff.ff = pos - 1;
            }

        }
    }
    v.clear();
    vector<pair<int, pii>> printres;

    int indx = (int)str.size() - 1, ck = 1;

    res[0].ff.ff = -2;
    while(indx > -1){
        if(res[indx].ff.ff == -2){
            ck = 0;
            break;
        }
        printres.pb({ res[indx].ff.ss, {res[indx].ss.ff, res[indx].ss.ss }});
        indx = res[indx].ff.ff;
    }
    res.clear();

    if(ck){
        reverse(all(printres));

        printf("%d\n", (int) printres.size());
    
        for(int i = 0; i < (int)printres.size(); i++){
            printf("%d %d %d\n",  printres[i].ss.ff, printres[i].ss.ss, printres[i].ff + 1);
        }
    }
    else puts("-1");


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