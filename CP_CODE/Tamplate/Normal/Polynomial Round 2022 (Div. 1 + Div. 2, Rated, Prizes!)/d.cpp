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

const int maxn = 1e5;
vector<int>grid[maxn + 5], good[maxn + 5], bad[maxn + 5], allgood(maxn + 1);
void solve(){
	
	int n, m;
	sc2(n, m);

	ll sum = 0;
	for(int i = 0; i <= m; i++){
		bad[i].clear();
		good[i].clear();
	}
	for(int i = 1; i <= n; i++){
		allgood[i] = 0;
		grid[i].resize(m + 1);
		grid[i][0] = 0;
		for(int j = 1; j <= m; j++){
			sc1(grid[i][j]);
			if(grid[i][j]){
				grid[i][0]++;
				sum++;
			}
		}
	}

	ll opt = 0;
	if(sum % n){
		puts("-1");
	}
	else{
		sum /= n;

		for(int i = 1; i <= n; i++){
			if(grid[i][0] < sum){
				opt += (sum - grid[i][0]);
				for(int j = 1; j <= m; j++){
					if(grid[i][j] == 0) {
						bad[j].pb(i);
					}
				}
			}
			else if(grid[i][0] > sum){
				for(int j = 1; j <= m; j++){
					if(grid[i][j] == 1) {
						good[j].pb(i);
					}
				}
			}
		}


		printf("%lld\n", opt);
		for(int i = 1; i <= m && opt; i++){
				
			int j = 0, k = 0, x, y;

			while(j < good[i].size() && k < bad[i].size()){
				x = good[i][j], y = bad[i][k];

				if(allgood[x]){
					j++;

				}
				else if(allgood[y]){
					k++;
				}
				else{
					grid[x][0]--;
					grid[y][0]++;
					if(grid[x][0] == sum) allgood[x] = 1;
					if(grid[y][0] == sum) allgood[y] = 1;
					j++, k++;
					printf("%d %d %d\n", x, y, i);
					//cout << grid[x][0] << " " << grid[y][0] << endl;
					opt--;
				}
			}


		}

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
