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

const int maxn = 5e4;


int par[maxn + 5];
stack< pair<pii,int> > updates; 
vector<pii>edge;
vector<pair<pii, int>> qrs[230];

int ans[maxn + 5];

int get(int x){
	return par[x] < 0 ? x : get(par[x]);
}

int union_set(int x, int y){
	x = get(x), y = get(y);

	if(x == y){
		updates.push({{-1, -1}, -1});
		return 0;
	}
	if(par[x] > par[y]) swap(x, y);
	updates.push({ {x, y}, par[y]} );

	par[x] += par[y];
	par[y] = x;
	return 1;
}

int rollback(){
	int cnt = 0;
	while(!updates.empty()){
		pair<pii, int> now;

		now = updates.top();
		updates.pop();

		if(now.ff.ff == -2) break;
		if(now.ff.ff != -1){
			cnt++;
			par[now.ff.ff] -= now.ss;
			par[now.ff.ss] = now.ss;
		}
	}

	return cnt;
}

bool cmp(pair<pii, int> &a, pair<pii, int> &b){
	return a.ff.ss < b.ff.ss ||
	 (a.ff.ss == b.ff.ss && a.ff.ff < b.ff.ff);
}
void solve(){
    int n, m;

    sc2(n, m);

    edge.resize(m);
    for(int i = 0; i < m; i++){
    	int u, v;
    	sc2(u, v);
    	edge[i] = {u, v};
    }


    int q = 0;
    sc1(q);

    int sq = sqrt(q);

    for(int i = 0; i < q; i++){
    	int l, r;
    	sc2(l , r);
    	l--, r--;
    	qrs[l / sq].pb({{l, r}, i});
    }

    for(int i = 0; i < sq + 1; i++){
    	sort(all(qrs[i]), cmp);
    }



    for(int i = 0; i <= sq + 1; i++){

    	for(int t = 0; t <= n; t++) par[t] = -1;
 	  	while(!updates.empty()) updates.pop();
    	int res = n;
    	int rn = (i + 1) * sq;
    	

    	for(int j = 0; j < qrs[i].size(); j++){
    		int low = i * sq, high = (i + 1) *  sq - 1;
    		
    		if(low <= qrs[i][j].ff.ff  && qrs[i][j].ff.ss <= high){

    			for(int x = qrs[i][j].ff.ff; x <= qrs[i][j].ff.ss; x++){
    				res -= union_set(edge[x].ff, edge[x].ss);
    			}
    			ans[qrs[i][j].ss] = res;
    			res += rollback();
    		}
    		else{

    			pair<pii, int> now = qrs[i][j];
    			while(rn <= now.ff.ss){
    				res -= union_set(edge[rn].ff, edge[rn].ss);
    				rn++;
    			}
    			updates.push({{-2, -2}, -2});
    			int ln = (i + 1) * sq - 1;
    			while(ln >= now.ff.ff){
    				res -= union_set(edge[ln].ff, edge[ln].ss);
    				ln--;
    			}
    			ans[now.ss] = res;
    			res += rollback();

    		}
    	}
    }


    for(int i = 0; i < q; i++){
    	printf("%d\n", ans[i]);
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