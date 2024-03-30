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

const int maxn = 400;
int freq[maxn + 5][maxn + 5];
char ch;
void solve(){
    
    
	int n, m;
	
	sc2(n, m);

	for(int i = 1; i <= n; i++){
		getchar();
		for(int j = 1; j <= m; j++){
			sc("%c", &ch);
			//cout << ch;
			freq[i][j] = freq[i - 1][j] + freq[i][j - 1] - freq[i - 1][j - 1] + (ch == '1');
			//cout << freq[i][j] << " ";
		}
		//puts("");
	}

	int res = inf;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int x = i + 4; x <= n; x++){
				for(int y = j + 3; y <= m; y++){
					int fa = freq[i][y - 1] - freq[i - 1][y - 1] - freq[i][j] + freq[i - 1][j];
					int fb = freq[x - 1][j] - freq[x - 1][j - 1] - freq[i][j] + freq[i][j - 1];
					int fc = freq[x][y - 1] - freq[x - 1][y - 1] - freq[x][j] + freq[x - 1][j];
					int fd = freq[x - 1][y] - freq[x - 1][y - 1] - freq[i][y] + freq[i][y - 1];
					int zerocnt = freq[x - 1][y - 1] - freq[i][y - 1] - freq[x -1][j] + freq[i][j];
					int add = (2 * (x - i - 1) - fa - fc) + (2 * (y - j - 1) - fb - fd) + zerocnt;
					res = min(add, res);
				}
			}
		}
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