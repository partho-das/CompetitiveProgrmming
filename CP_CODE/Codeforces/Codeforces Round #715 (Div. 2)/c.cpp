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

vll v;
map<ll, pll> pos;
ll cmp(int indx){

	int l = pos[v[indx]].ff - 1, r = pos[v[indx]].ss + 1;

	ll lv = 0, rv = inf, mx = v[indx], mn = v[indx];

	if( l >= 0 && l < v.size()) lv = v[l];
	if( r >= 0 && r < v.size()) rv = v[r];
	ll sum = 0;
	//cout << " " << lv << " " << rv << endl;
	while( (l >= 0 && l < v.size()) && (r >= 0 && r < v.size()) ){
	
		// cout <<  (pos[lv].ss - pos[lv].ff + 1) * (mx - lv) + (rv - lv) * (pos[rv].ss - pos[rv].ff + 1) << " indx " << indx << " l " << l << " r " << r << endl;
		// cout << lv << " rv " << rv << " mn " << mn << " mx " << mx << endl;
		if( (pos[lv].ss - pos[lv].ff + 1) * (mx - lv) + (rv - lv) * (pos[rv].ss - pos[rv].ff + 1)
		<=  (pos[rv].ss - pos[rv].ff + 1) * (rv - mn) + (rv - lv) * (pos[lv].ss - pos[lv].ff + 1)){
			sum +=  (pos[lv].ss - pos[lv].ff + 1) * (mx - lv);
			indx = pos[lv].ff;
			l = indx - 1;
		}
		else{
			sum += (pos[rv].ss - pos[rv].ff + 1) * (rv - mn) ;
			indx = pos[rv].ss;
			r = indx + 1;
		}

		mx = max(mx, v[indx]);
		mn = min(mn, v[indx]);		

		if( l >= 0 && l < v.size()) lv = v[l];
		if( r >= 0 && r < v.size()) rv = v[r];

	}

	//cout << l << endl;
	while( (l >= 0 && l < v.size()) ){
		//cout << v[l] << endl;
		sum += mx - v[l];
		l--;
	}
	while(  (r >= 0 && r < v.size()) ){
		sum +=  v[r] - mn;
		r++;
	}

	//cout << sum << endl;
	return sum;

}

void solve(){
    
    int n;
    sc1(n);

    v.resize(n);
    for(int i = 0; i < n; i++){
    	scl(v[i]);
    	pos[v[i]] = {1e4, -1e4};
    }
    sort(all(v));
   	for(ll i = 0; i < n; i++){
   		pos[v[i]].ff = min(pos[v[i]].ff, i);
   		pos[v[i]].ss = max(pos[v[i]].ss, i); 
   	}
   	//cout << pos[889921234].ff << " " << pos[889921234].ss << endl;
    ll res = INF;
    for(int i = 0; i < n; i++){
    	res = min(res, cmp(i));
    	cout << "HI = " << cmp(i) << endl;
    	//break;

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