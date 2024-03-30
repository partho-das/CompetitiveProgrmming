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
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

int tc = 1;
vll pr, tpr;
bool check(vi &v, int mid, int lim){
	ll sum = 0, cnt = 1;

    tpr.clear();

	for(int i = 0; i < v.size(); i++){
		if(sum + v[i] > mid ){
			cnt++;
            tpr.pb(-2);
			sum = v[i];
            tpr.pb(v[i]);
			
            if(cnt > lim) return 0;
		}
		else{
			sum += v[i];
            tpr.pb(v[i]);
		}

	}
    tpr.pb(-2);
    sum = 0;
   
    
	pr.clear();
    pr.resize(lim);
    // for(auto it : tpr) cout << it << " " << endl;

    int indx = lim - 1, indx2 = tpr.size() - 1;
    
    while(indx >= 0 && indx2 >= 0){

        if(tpr[indx2] == -2){
            indx2--;
            cnt--;
            continue;
        }
        // cout << cnt  << " "<< tpr[indx2] << " "  << indx << " " << pr[indx] << endl;
        if(indx + 1 == cnt + 1) break;

        if(tpr[indx2] != -2){
            pr[indx--] = tpr[indx2];
            tpr[indx2] = -1;
        }
        indx2--;
    }
    sum = 0, indx2 = 0;
    for(int i = 0; i < tpr.size(); i++){
        if(tpr[i] == -1) continue;
        if(tpr[i] == -2){
            if(sum)
            pr[indx2++] = sum;
            sum = 0;
            continue;
        }
        sum += tpr[i];
    }
    if(sum)
    pr[indx2] = sum;


	return 1;

}
void solve(){
    
    int n, m;
    sc2(n, m);
    m++;
    n++;
    vi v(n);

    ll sum = 0, res = -1, mx = 0;
    for(int i = 0; i < n; i++){
    	sc1(v[i]);
    	sum += v[i];
    	mx = max(mx, (ll)v[i]);
    }

    ll low = mx, high = sum, mid;

   
    while(low <= high){
    	mid = low + (high - low) / 2;
        //mid = 8;
    	if(check(v, mid, m)){
    		high = mid - 1;
    		res = mid;

    	}
    	else low = mid + 1;
    	//break;

    }

    printf("Case %d: %lld\n", tc++, res);
    for(int i = 0; i < m; i++){
    	if(pr.size() <= i) puts("0");
    	else printf("%lld\n", pr[i]);
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