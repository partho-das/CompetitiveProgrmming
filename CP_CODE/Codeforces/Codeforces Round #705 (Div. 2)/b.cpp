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

vi inv;
int MH, MM;
bool isval(int h, int m){

	//cout << h << ":" << m << endl;

	string H, M;
	H = "00";
	M = "00";

	int pos = 1;

	while(h){
		H[pos--] = '0' + h % 10;
		h /= 10;
	}

	pos = 1;

	while(m){
		M[pos--] = '0' + m % 10;
		m /= 10;
	}

	swap(H[0], M[1]);
	swap(H[1], M[0]);

	if(H[0] == '2') H[0] = '5';
	else if(H[0] == '5') H[0] = '2';

	if(H[1] == '2') H[1] = '5';
	else if(H[1] == '5') H[1] = '2';


	if(M[0] == '2') M[0] = '5';
	else if(M[0] == '5') M[0] = '2';

	if(M[1] == '2') M[1] = '5';
	else if(M[1] == '5') M[1] = '2';


	int ck = 1;


	//cout << H << ":" << M << endl;


	for(auto it : inv){
		if(H[0] == it + '0') ck = 0;
	}
	for(auto it : inv){
		if(H[1] == it + '0') ck = 0;
	}
	for(auto it : inv){
		if(M[0] == it + '0') ck = 0;
	}
	for(auto it : inv){
		if(M[1] == it + '0') ck = 0;
	}

	if(!ck) return 0;

	h = 0, m = 0;

	h = H[0] - '0';
	h *= 10;
	h += H[1] - '0';

	m = M[0] - '0';
	m *= 10;
	m += M[1] - '0';
	if(m < MM && h < MH) return 1;
	return 0;

}
void solve(){
    

    int nh, nm;

    sc2(MH, MM);
  	cin >> nh;
  	getchar();
  	cin >> nm;


  	while(1){
  		if(isval(nh, nm)){
  			if(nh < 10) cout << "0";
  			cout << nh << ":";
  			if(nm < 10) cout << "0";
  			cout << nm << endl;
  			return;
  		}

  		nm++;
  		if(nm >= MM){
  			nh++;
  			nm = 0;
  		}

  		if(nh >= MH){
  			nh = 0;
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

    inv.pb(3);
    inv.pb(4);
    inv.pb(6);
    inv.pb(7);
    inv.pb(9);

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