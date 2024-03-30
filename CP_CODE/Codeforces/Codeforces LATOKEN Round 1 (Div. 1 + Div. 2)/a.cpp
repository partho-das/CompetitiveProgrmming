
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

int dirx[] = {0, 0, -1, -1};
int diry[] = {-1, 1, 0,  0};

void solve(){
    
    int n, m;

    sc2(n, m);
    string str[n + 2];
    for(int i = 0; i < n; i++){
    	cin >> str[i];
    	//cout << str[i] << endl;
    }

    set<char>o, e;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(str[i][j] == '.') continue;
    		if((i + j) % 2 == 0){
    			e.insert(str[i][j]);
    		}
    		else{
    			o.insert(str[i][j]);
    		}
    	}
    }
    if(e.size() >= 2 || o.size() >= 2){
    	puts("NO");
    	return;
    }
    else{
		if((int)e.size() + (int)o.size() == 2 && *o.begin() == *e.begin()){
			puts("NO");
			return;
		}
    	puts("YES");

    	if((int)e.size() + (int)o.size()){
    		if(!(int)e.size()){
    			if(*o.begin() == 'R') e.insert('W');
    			else e.insert('R');
    		}
    		else{
    			if(*e.begin() == 'R') o.insert('W');
    			else o.insert('R');	
    		}

    		for(int i = 0; i < n;i++){
    			for(int j = 0 ;j < m; j++){
    				if( ( i + j) % 2 == 0){
    					printf("%c", *e.begin());
    				}
    				else printf("%c", *o.begin());
    			}
    			puts("");
    		}
    	}
    	else{
    		for(int i = 0; i < n;i++){
    			for(int j = 0 ;j < m; j++){
    				if( ( i + j) % 2 == 0){
    					printf("R");
    				}
    				else printf("W");
    			}
    			puts("");
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