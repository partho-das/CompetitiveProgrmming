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
int arr[100010];
void solve(){
    
    int n;
    fflush(stdout);

    sc1(n);
    arr[0] = arr[n + 1] = 1e9;
    int high = n + 1, low = , move = 100;
    int ck = 0;
    while(low <= high && move >= 1){
    	fflush(stdout);
    	
    	int mid = low + (high - low) / 2;
    	

    	if(move >= (high - low + 1)){
    		int indx = -1, mn = inf;
    		move -= (high - low + 1);
    		for(int i = low; i <= high; i++){
    			fflush(stdout);
    			printf("? %d\n", i);

    			fflush(stdout);
    			int value;

    			sc1(value);
    			arr[i] = value;
    			fflush(stdout);

    			if(value < mn){
    				mn = value;
    				indx = i;
    			}

    		}
    		if(move >= 1){
    			if(low - 1 >= 1 && !arr[low - 1]){

	    			printf("? %d\n", low - 1);
	    			int value;
	    			sc1(value);
	    			arr[low - 1] = value;
	    			fflush(stdout);
	    			move--;
    			}
    		}
    		if(move >= 1){
    			if(high + 1 <= n){
    				printf("? %d\n", high + 1);
					fflush(stdout);

    				int value;
    				sc1(value);
    				arr[high + 1] = value;
    			}
    		}

    		for(int i = low; i <= high; i++){
    			if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){
    				printf("! %d\n", i);
    				fflush(stdout);
		    		return;
    			}
    		}

    		
    	}

    	// dbg(mid);
    	// puts("HI");
    	int mc = move;
    	int l = mid - 1, r = mid + 1, a, b, c;
    	if(l > 0 && !arr[l] && move > 0){

	    	printf("? %d\n", l);
	    	fflush(stdout);
	    	sc1(a);
	    	arr[l] = a;
	    	move--;
    	}

    	if(!arr[mid] && move > 0){

	    	printf("? %d\n", mid);
	    	fflush(stdout);
	    	sc1(b);
	    	arr[mid] = b;
	    	move--;
    	}

    	if( r <= n && !arr[r] && move > 0){

	    	printf("? %d\n", r);
	    	fflush(stdout);
	    	sc1(c);
	    	arr[r] = c;
	    	move--;
    	}
    	fflush(stdout);
    	a = arr[l] , b = arr[mid], c = arr[r];
    	
    	if(a > b && b < c){
    		ck = 1;
    		printf("! %d\n", mid);
			fflush(stdout);
    		
    		return;
    	}
    	else if( a > b && b > c) low = mid;
    	else  high = mid; 
    	//cout << a << " " << b << " " << c << " " << endl;
    	//move -= 3;
    	//if(mc == move) break;
    }

    for(int i = 1; i <= n; i++){
			if( arr[i] && arr[i - 1] && arr[i + 1] && arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){
				printf("! %d\n", i);
				fflush(stdout);
	    		return;
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

    //sc1(test);

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