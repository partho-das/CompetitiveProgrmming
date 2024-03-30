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
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
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

string words[][20] = { {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"} };


void p12999(char a, char b, char c){
	int ck = 0;
	if(a != '0'){
		cout << words[0][a - '0'] << " " << "Hundred";
		ck = 1;
	}
	if( b != '0' || c != '0'){
		if(ck) cout << " ";

		if(b >= '2'){
			cout << words[2][b - '0'];
			if(c >= '1') cout << " " << words[0][c - '0'];
		}
		else if(b >= '1'){
			cout << words[1][c - '0'];
		}
		else{
			cout << words[0][c - '0'];
		}
	}
	return;

}

const int maxn = 1e5;
int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

string str;
cin >> str;
str.insert(0,10 - str.size(), '0');
int ck = 0, ck1 = 0, ck2 = 0;
if(str[0] != '0'){
	ck = 1;
	cout << words[0][str[0] - '0'] << " " << "Billion";
}
if(str[1] != '0' || str[2] != '0' || str[3] != '0'){
	if(ck) cout << " "; ck = 1;
	p12999(str[1], str[2], str[3]);
	cout << " " << "Million";

}
if(str[4] != '0' || str[5] != '0' || str[6] != '0'){
	if(ck) cout << " "; ck = 1;
	p12999(str[4], str[5], str[6]);
	cout << " " << "Thousand";

}
if(str[7] != '0' || str[8] != '0' || str[9] != '0'){
	if(ck) cout << " ";
	p12999(str[7], str[8], str[9]);
}
puts("");

#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1