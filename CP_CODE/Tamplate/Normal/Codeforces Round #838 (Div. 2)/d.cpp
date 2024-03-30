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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r){
    int diff = r - l + 1;
    return l + rng() % diff;
}
inline int query(int a, int b){
	fflush(stdout);
	printf("? %d %d\n", a, b);
	int GCD;
	sc1(GCD);
	fflush(stdout);
	return GCD;
}
void solve(){
	
	int n;

	fflush(stdout);
	sc1(n);


	vi take(n);
	map<int, int>yn[n + 1];

	for(int i = 1; i <= n; i++){
		take[i - 1] = i;
	}
	shuffle(all(take), rng);

	int cnt = 2 * n, now = 0, res = -1;
	while(take.size()){
		set<int>unq;
		vi uniqindx(n);

		for(int i = 1; i <= n; i++){
			uniqindx[i - 1] = i;
		}
		std::shuffle(all(uniqindx), rng);
		now = take.back();
		//cout << take.size() << endl;
		take.pop_back();

		int cnt2 = 0;

		for(auto it : yn[now]){
			if(unq.find(it.ss) == unq.end()){
				unq.insert(it.ss);
			}
			else{
				cnt2 = -1;
			}
		}
		if(cnt2 == -1) {
			continue;
		}

		while((int)uniqindx.size() && cnt--){
			int second = uniqindx.back(), GCD;
			uniqindx.pop_back();
			if(now == second || (yn[now].find(second) != yn[now].end()) ) {
				cnt++;
				if(now == second)
				GCD = now;
				else GCD = yn[now][second];
			}
			else{
				GCD = query(now, second);
				yn[second][now] = GCD;
			}

			if(unq.find(GCD) != unq.end()){
				break;
			}
			unq.insert(GCD);
			cnt2++;
			if(cnt2 > 80 || cnt2 == (n - 1)){
				res = now;
				break;
			}
		}

		if(res != -1){
			break;
		}

	}
	//cout << res << endl;

	if(res == -1){
		res = take.back();
		take.pop_back();
	}
	int second = res;
	if((int)take.size()){
		take.back();
	}

	printf("! %d %d\n", res, second);

	fflush(stdout);
	int verdict;
	sc1(verdict);
	//cout << verdict << endl;

	if(verdict == -1){
		puts("Wrong answer");
		return;
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
