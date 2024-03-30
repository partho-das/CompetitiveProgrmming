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
string str;

vi freq(30), taken(30);
void solve(){
    
    cin >> str;
  	FOR(i, 0, 30){
  		taken[i] = 0;
  		freq[i] = 0;
  	}

    set<char>unq;
    for(int i = 0; i < str.size(); i++){
    	freq[str[i] - 'a']++;
    	unq.insert(str[i]);
    	//cout << freq[str[i] - 'a'] << endl;
    }

    string res;
    int indx = -1, cnt = 0;

    int c = unq.size();
    for(int x = 0; x < unq.size(); x++){
    	int mx = -1;
    	char ch = 0;
    	vi cfreq = freq;
    	for(int i = indx + 1; i < str.size(); i++){
    		if(taken[str[i] - 'a']) continue;
    		if(str[i] > ch){
    			mx = i;
    			ch = str[i];
    		}

    		if(cfreq[str[i] - 'a'] == 1){
    			break;
    		}
    		cfreq[str[i] - 'a']--;
    	}

    	res.pb(ch);
    	taken[ch - 'a'] = 1;
    	for(int i = indx + 1; i <= mx; i++){
    		freq[str[i] - 'a']--; 
    	}
    	indx = mx;
    	//break;
    	//cout << res << " "  << indx << " " << x<< endl;
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