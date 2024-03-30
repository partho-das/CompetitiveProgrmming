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

const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
//template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
template <class T> inline string to_string(const pair<T,T> &p) {
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";  
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

#define base 31
#define type 'a'
#define NUM_OF_HASH 4
#define MAX (int)2e5

ll Hash[NUM_OF_HASH][MAX + 5];
ll power[NUM_OF_HASH][MAX + 5];
ll MOD[] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};
string str;
int len;

void pre()
{
	len = str.size();
	for(int i=0;i<NUM_OF_HASH;i++){
	    power[i][0] = 1;
		Hash[i][0] = str[0]-type+1;
		for(int j=1;j<=len;j++) {
			//cout << str[i] << endl;
			power[i][j] = (power[i][j-1]*base)%MOD[i];
			if(j != len)
			Hash[i][j] = (Hash[i][j-1]*base + str[j]-type+1)%MOD[i];
			//cout << Hash[i][j] << " " << j << endl;
		}
	}
	return;
}

ll getHash(int i,int j,int k){
    if(!i) return Hash[k][j] % MOD[k];
    return ((Hash[k][j] - (Hash[k][i - 1] * power[k][j - i + 1]) % MOD[k]) + MOD[k] + MOD[k] + MOD[k] + MOD[k] + MOD[k]) % MOD[k];
}

ll cngHash(int pos, char ch, int len, int k){
    return (((Hash[k][pos - 1] * base + ch - type + 1) * power[k][len - pos - 1]) % MOD[k] + getHash(pos + 1, len - 1, k) ) % MOD[k];
}
ll singleHash(string &str, int k){
	ll hashv = str[0] - type + 1;

	for(int i = 1; i < str.size(); i++){
		hashv = (hashv * base + str[i] - type + 1) % MOD[k];
	}
	return hashv;
}


void solve(){
	
	int n;
	sc1(n);

	cin >> str;
	pre();

	set<pii>hvset;
	int modn1 = 2, modn2 = 3;
	for(int i = 0; i < n - 1; i++){
		ll a = 0, b = 0, c = 0, d = 0;
		if(i){
			a = getHash(0, i - 1, modn1);
			c = getHash(0, i - 1, modn2);

		}
		if(i + 2 < n){
			b = getHash(i + 2, n - 1, modn1);
			d = getHash(i + 2, n - 1, modn2);
		}
		ll newhash1 = (a * power[modn1][n - (i + 2)] + b) % MOD[modn1];
		ll newhash2 = (c * power[modn2][n - (i + 2)] + d) % MOD[modn2];

		//cout << a << " " << b << " " << " " << newhash2 << " " << i << endl;
		hvset.insert({newhash1, newhash2});
	}

	cout << (int)hvset.size() << endl;


	return;
}


int main() {
     #ifdef PARTHO
        freopen("/home/partho/Desktop/CODEFORCES/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/CODEFORCES/IO/output.txt","w",stdout);
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
