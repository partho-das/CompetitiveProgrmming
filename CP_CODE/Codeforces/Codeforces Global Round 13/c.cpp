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
    
    int n;

    sc1(n);
    vi v(n);
    //cout << n << endl;
    std::vector<pii> dis(n);

    for(int i = 0; i < n; i++){
    	sc1(v[i]);
    	dis[i].ff = i, dis[i].ss = 0;
    	//cout << v[i] << endl;
    }
    ll res = 0;
    while(1){
    	int ck = 0;
    	FOR(i, 0, n){
    		if(v[i] != 1) ck = 1;
    		dis[i].ff = i, dis[i].ss = 0;
    	}
    	if(!ck) break;
    	int mxdis = 0, indx = -1;

    	for(int i = 0; i < n; i++){
    		if(v[i] > 1){

    			dis[i].ss++;
				if(mxdis <= dis[i].ss){


					if(mxdis == dis[i].ss) 
						indx = min(dis[i].ff, indx);
					else{

						indx = dis[i].ff;
				cout << i << " " << mxdis << " " << indx << endl;
					} 
					mxdis = dis[i].ss;
				}
    		}

			if(i + v[i] < n){
				if( dis[ i + v[i] ].ss <= dis[i].ss){
					dis[ i + v[i] ].ss = dis[i].ss;
					dis[i + v[i]].ff = dis[i].ff;
				} 
			}
    		
    	}

    	if(!mxdis) break;

    	if(mxdis == 1){

    		int pos = indx;
    		while(pos < n && v[pos] <= 1){
    			int x = pos;
    			//cout << v[pos] << endl;
    			pos = pos + v[pos];
    			v[x]--;
    			v[x] = max(v[x], 1);
    			//res++;
    		}
    		indx = pos;

	    	if(indx == n - 1) res += v[indx] - 1, v[indx] = 1;
	    	else{

	    		int d = n - 1 - indx;
	    		if(v[indx] <= d ){
	    			if(v[indx] > 1){
	    			v[indx]--;
	    			res++;
	    			}
	    		}
	    		else{
	    			res += v[indx] - d;
	    			v[indx] = d;
	    		}
	    	}

    	}
    	else{
    		int pos = indx;
    		while(pos < n){
    			int x = pos;
    			//cout << v[pos] << endl;
    			if(v[pos] > 1)
    			res++;
    			pos = pos + v[pos];
    			v[x]--;
    			v[x] = max(v[x], 1);
    		}

    	}

    	for(auto it : v) cout << it << " ";
    		puts("");
    	cout << indx << endl;
    	//break;
    }

    printf("%lld\n", res);

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