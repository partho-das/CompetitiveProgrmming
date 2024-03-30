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

const int maxn = 2e5;
vector<int>graph[maxn + 5];
int workd[maxn + 5];

bool insertinto(vi &proa, vi &prob, set<int> &seta, set<int> &setb, vector<pii> &v){

	//cout << endl;
	int i = proa.back();
	
	// for(auto it : proa) cout << it << endl;
	// cout << endl;
	
	int now1 = v[i].ff;
	proa.pop_back();
	int now2 = v[i].ss;
	//cout << now1 << " " << now2 << " " << ck << endl;

	//return 0;
	if(seta.find(now1) == seta.end() && seta.find(now2) == seta.end()){
		seta.insert(now1);
		seta.insert(now2);

		if(graph[now1].back() != i) swap(graph[now1][0], graph[now1][1]);
		if(graph[now2].back() != i) swap(graph[now2][0], graph[now2][1]);
		graph[now1].pop_back();
		graph[now2].pop_back();
		if(graph[now1].size() && !workd[graph[now1].back()] ){
			prob.push_back(graph[now1].back());
			workd[graph[now1].back()] = 1;
		}
		if(graph[now2].size() && !workd[graph[now2].back()] ){
			prob.push_back(graph[now2].back());
			workd[graph[now2].back()] = 1;

		}

		return 1;

	}
	return 0;
}

void solve(){
 
	int n;
	sc1(n);

	set<int>seta, setb;
	vector<pii> v(n);
	vi proa, prob;
	for(int i = 0; i <= n; i++){
		graph[i].clear();
		workd[i] = 0;
	}


	int ck = 1;
	for(int i = 0; i < n; i++){
		int u, ve;
		sc2(u, ve);

		if(u == ve || graph[u].size() >= 2 || graph[ve].size() >= 2){
			ck = 0;
		}
		if(ck){
			v[i] = {u, ve};
			graph[u].pb(i);
			graph[ve].pb(i);
		}
	}


	int i = 0;
	while( i < n && ck){

		if(proa.size() || prob.size()){
			while(proa.size()){
				ck = ck && insertinto(proa, prob, seta, setb, v);
			}
			while(prob.size()){
				ck = ck && insertinto(prob, proa, setb, seta, v);
			}
		}
		else{
			if(!workd[i]){
				proa.pb(i);
				workd[i] = 1;
			}
		}
		i++;
	}

	if(ck) puts("YES");
	else puts("NO");


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
