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

const int maxn = 1e5;

int a[maxn + 5], b[maxn + 5];

int marge(int l, int mid, int r, vi &v){

    if( l > r) return 0;

    for(int i = 0; i < (mid - l + 1); i++){
        a[i] = v[l + i];
    }
    for(int i = 0; i < (r - (mid + 1) + 1); i++){
        b[i] = v[mid + 1 + i];
    }
    int n = mid - l + 1, m = r - (mid + 1) + 1, i = 0, j = 0, indx = l;
     
    ll cnt = 0;
    while(indx <= r){

        if(i >= n){
            v[indx++] = b[j++];
            continue; 
        }
        else if(j >= m){
            v[indx++] = a[i++];
            cnt += abs(indx - l - i);
            continue; 
        }
        if(a[i] < b[j]){
            v[indx++] = a[i++];
            cnt += abs(indx - l - i);
        }
        else{
            v[indx++] = b[j++];
        }
    }

    
    return cnt;

}

ll marge_sort(int l, int r, vi &v){
	if(l > r) return 0;
	if(l == r){
		return 0;
	}

    int mid = l + (r - l) / 2;

    ll res = 0;

    res = marge_sort(l, mid, v);
    res += marge_sort(mid + 1, r, v);

    res += marge(l, mid, r, v);
    return res;
}
void solve(){
    
    int n;
    sc1(n);


    vi v(n);
    for(int i = 0; i < n; i++){
    	sc1(v[i]);
    }

    printf("%lld\n", marge_sort(0, n - 1, v) );
    //for(auto it : v) cout << it << " " << endl;


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
///    *check for n=1f