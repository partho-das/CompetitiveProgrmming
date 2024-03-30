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

struct sparse_table{

    vector<vector<int>>table;

    sparse_table(){};
    sparse_table(int n, vector<int>&v){
        table.resize(n, vector<int>(22, (1ll << 31) - 1));
        process(n, v);

    }

    void process(int n, vector<int> &v){
        for(int i = 0; i < (int)v.size(); i++){
            table[i][0] = v[i];
        }
        for(int j = 1; j <= 20; j++){
            for(int i = 0; i < (int)v.size(); i++){
                if(i + (1 << j) <= (int)v.size()){
                    table[i][j] = table[i][j - 1] & table[i + (1 << (j - 1))][j - 1];
                }
            }
        }
    }

    int query(int l, int r){
        //cout << l << " " << r << endl;
        int range = r - l + 1, result = (1ll << 31) - 1;
        //cout << result << endl;
        for(int i = 0; i <= 20; i++){
            if(range & (1 << i)){
                result &= table[l][i];
                l += (1 << i);
            }
        }
        return result;
    }
};

int get_res(int d, int indx, vector<int> &v, vector<int> &visited){
    vector<int>proc, indxv;
    int now = indx, n = v.size();
    proc.pb(v[now]);
    indxv.pb(now);

    visited[now] = 1;
    now = (now + d) % n;
    while(now != indx){
        proc.pb(v[now]);
        //cout << now << endl;
        visited[now] = 1;
        indxv.pb(now);
        now = (now + d) % n;


    }
    n = proc.size();

    for(int i = 0; i < n; i++){
        proc.pb(proc[i]);
    }
    int mxcnt = 0, cnt = 0;

    for(int i = 0; i < (int)proc.size(); i++){
        if(proc[i] == 1){
            cnt++;
            mxcnt = max(mxcnt, cnt);
        }
        else cnt = 0;
    }
    if(cnt >= n) return -1;
    return mxcnt;

}
void solve(){
    
    int n, d;
    sc2(n, d);

    vector<int>v(n), visited(n, 0);

    for(int i = 0; i < n; i++){
        sc1(v[i]);
    }
    int mxres = 0, ck = 1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int temp = get_res(d, i, v, visited);
            if(temp == -1){
                ck = 0;
                break;
            }
            mxres = max(mxres, temp);
            //break;
        }
    }

    if(ck){
        printf("%d\n", mxres);
    }
    else puts("-1");
    return;
}


int main() {
     #ifdef PARTHO
        freopen("/home/partho/Desktop/CODEFORCES/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/CODEFORCES/IO/output.txt","w",stdout);
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
