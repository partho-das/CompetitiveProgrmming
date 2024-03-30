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
const int maxn = 1e4;
string str[maxn + 5];
int n, m;

void f(int b, int a, int c, int m){

	int work = m / 4;
	vi res;
	if(m % 4){
		res.pb(a);
	}

	res.pb(b);

	while(work--){
		res.pb(a);
		res.pb(b);
		res.pb(c);
		res.pb(b);
	}
	if(m % 4) res.pb(c);

    puts("YES");
	FOR(i, 0, res.size()) printf("%d ", res[i] + 1);
	puts("");

	return;

}
void solve(){
    

    sc2(n, m);


    FOR(i, 0, n) cin >> str[i];

    if(m & 1){
    	puts("YES");
    	int a, b;

    	a = 1, b = 2;

    	printf("1 2 ");

    	m--;

    	while(m--){
    		printf("%d ", a);
    		swap(a, b);
    	}
    	puts("");
    }
    else{
    	int ck = 0, a = -1, b = -1;
    	FOR(i, 0, n){
    		FOR(j, 0, n){
    			if(i == j) continue;
    			//cout << str[i][j] << " " << i << " " << j << " " << str[j][i] << endl;
    			if( str[i][j] == str[j][i]){
    			//cout << str[i][j] << " " << i << " " << j << " " << str[j][i] << endl;
    				a = i + 1, b = j + 1;
    				ck = 1;
    				break;
    			}
    		}
    		if(ck) break;

    	}

    	if(ck){
    		puts("YES");
			printf("%d %d ", a, b);
	    	m--;
	    	while(m--){
	    		printf("%d ", a);
	    		swap(a, b);
	    	}
	    	puts("");
		}
		else{
			int ck2 = 0;
			vi ain(n + 1, -1), aout(n + 1, -1), bin(n + 1, -1), bout(n + 1, -1);
			FOR(i, 0, n){
				FOR(j, 0, n){
					if(i == j) continue;
					if(str[i][j] == 'a')aout[i] = j, ain[j] = i;
					else bout[i] = j, bin[j] = i;

				}
			}

			FOR(i, 0, n){
				FOR(j, 0, n){
					if(aout[i] != -1 && ain[i] != -1){
						f(i, aout[i], ain[i], m);
						ck2 = 1;
						break;
					}
					else if(bout[i] != -1 && bin[i] != -1){
						f(i, bout[i], bout[j], j);
						ck2 = 1;
						break;
					}
				}
				if(ck2) break;
			}

			if(!ck2) puts("NO");

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