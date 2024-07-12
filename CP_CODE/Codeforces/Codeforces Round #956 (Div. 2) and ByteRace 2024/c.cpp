#include <bits/stdc++.h>
#include <stdio.h>

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
ll n, sum = 0, take = 0, maxn = 2e5;
vector<ll>weight[3];
vector<pii>res(3), temp(3);


int f(int pos, int mask){
    if(mask == 0){
        res = temp;
        return 1;
    }
    if(pos >= n){
        return -1;
    }
    int ret = -1;
    for(int i = 0; i < 3 && ret == -1; i++){
        if(mask & (1 << i)){
            ll sum = 0, indx = -1;
            for(int j = pos; j < n; j++){
                sum += weight[i][j];
                if(sum >= take){
                    indx = j;
                    break;
                }
            }
            if(indx != -1){
                temp[i] = {pos, indx};
        // cout <<temp.size() << endl;
                ret = max(ret, f(indx + 1, mask ^ (1 << i)));
            }
        }
    }
    // cout << pos << " " << mask << " " << ret << endl;
    return ret;
}
void solve(){
   scl(n);
   sum = 0;
   for(int i = 0; i < 3; i++){
        sum = 0;
        weight[i].resize(n);
        for(int j = 0; j < n; j++){
            scl(weight[i][j]);
            sum += weight[i][j];
        }
   }
   take = (sum + 2) / 3;
   // cout << take << endl;
   // return;
   int flag = f(0, 7);
   if(flag == 1){
   // cout << res.size() << endl;
        for(auto it : res){
            cout << it.ff + 1 << " " << it.ss + 1 << " ";
        }
        cout << endl;
   }
   else cout << -1 << endl;
}



int main() {
   
    //FastIO;
     #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\IO\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\IO\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    int test = 1;

    sc1(test);


    while(test--){
        solve();
    }
    // puts("HI");

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

