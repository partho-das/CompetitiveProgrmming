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

string nw, str;
int mv = 1;
bool zerock(string &str){
    int  i = 0;
    while(i < str.size()){
        if(str[i] != '0') return 1;
        i++;
    }
    return 0;
}
void divby2(){

    if(mv % 2 == 0){

        str.clear();
        int rem = 0;
        for(int i = 0; i  < nw.size(); i++){
            rem = rem * 10 + nw[i] - '0';
            str.pb( (char)((rem / 2) + '0') );
            rem = (rem & 1);
        }
    //cout << str  << " " << nw  << " " <<  mv  << endl;
    }
    else{
        nw.clear();
        int rem = 0;
        for(int i = 0; i < str.size(); i++){
            rem = rem * 10 + str[i] - '0';
            nw.pb( (rem / 2) +  '0');
            rem = (rem & 1);
        }
    }
}
char s[3000];
int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/coutput.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;



while(scanf("%s", s) == 1)
{
	str = s;
 	nw.clear();
int res = 0;
mv = 1;
while(1){
    //cout << str  << " " << nw  << " " << res << " " <<  mv  << endl;
 	//cout << str << nw << endl;
    if(mv % 2) {
	//dbg(str);
        if(zerock(str) == 0) break;
    }    
    else {
        if(zerock(nw) == 0) break;
    }
    if(mv % 2){ 
        if( (str.back() - '0') % 2) res++, str.back()--;
    }
    else{
        if( (nw.back() - '0') % 2) res++, nw.back()--;
    } 

    //if(mv>= 3) break;

    divby2();
    mv++;
}

cout << res << endl;
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