#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
 
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%f",&f);
#define pn(n)        printf("%d\n", n);
#define ps(str)      printf("%s\n", str);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define TEST(test)   for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
ll MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template<class T> inline T bigmod(T b, T p){ if(p <= 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________


int n;
const int maxn = 1e5;
ll table[maxn + 5][32];
vll v(maxn + 5);

void preprocess()
{
	for(int i = 0; i < n; i++){
		table[i][0] = v[i];
	}

	int lim = log2(n) + 1;

	for(int j = 1; j < lim; j++)
	{
		int now = 1 << j;

		if(now > n ) break;

	//cout << now << endl;

		for(int i = 0; i < n; i++)
		{
			if(i + now > n) break;
			//cout << i + now << endl;

			int a = table[ i ][j - 1], b = table[i + (now >> 1)][j - 1];
			table[i][j] = min(a, b);
		}
	}



	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < lim; j++)
	// 		cout << table[i][j] << " ";
	// 	cout << endl;
	// }

}

ll queary(int l, int r)
{

	int dist = r - l + 1;

	ll mn = INF;
	for(int i = 0; i < 32; i++)
	{
		int agent = 1 << i;
		if(agent & dist)
		{
			mn = min(mn, (ll)table[l][i]);
			//cout << table[l][i] << " " << l << " " << i << endl;
			l += (1 << i);
		}
	}


	return mn;
}

int main()
{
  #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
   #endif
//FastIO;


sc1(n);



for(int i = 0; i < n; i++)
	scl(v[i]);

preprocess();


int q;
sc1(q);

while(q--){
	int l, r;
	sc2(l, r);
	//l--, r--;
	if(l > r) swap(l, r);
	cout << queary(l, r) << endl;
}



 

#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
 
// //____________________________________________________________________________________________________________________________________
// #define PI  2*acos(0.0)
// #define pf  printf
// #define sc  scanf
// #define ff  first
// #define ss  second
// #define mp  make_pair
// #define pb  push_back
// typedef long long ll;
// typedef unsigned long long ull;
// typedef std::vector<int> vi;
// typedef vector<long long> vll ;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// #define sc1(n)         sc("%d",&n);
// #define sc2(n, m)      sc("%d%d", &n, &m);
// #define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
// #define scl(n)         sc("%lld", &n);
// #define scll(n, m)     sc("%lld%lld", &n, &m);
// #define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
// #define scf(f)         sc("%f",&f);
// #define pn(n)        printf("%d\n", n);
// #define ps(str)      printf("%s\n", str);
// #define FOR(i,a,n)   for( int i = a; i < n; i++)
// #define TEST(test)   for(int cse = 1; cse <= test; cse++)
// #define all(x) (x).begin(), (x).end()
// #define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
// #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// const ll INF = 2000000000000000000LL;
// const int inf = 0x3f3f3f3f;
// ll MOD =  1e9 + 7;
// const long double EPS = 1e-9;
// template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
// template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
// template<class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
// //____________________________________________________________________________________________________________________________________
// const int maxn = 1e5;
// int memo[maxn + 5][20];
// void preprocess(vi &v)
// {
//     for(int i = 0; i < v.size(); i++) memo[i][0] = v[i];

//     for(int j = 1; j <= 20; j++){
//         int ageent = 1 << j;
//         if( v.size() < ageent) break;
//         for(int i = 0; i < v.size(); i++){
//             if( v.size() - i < ageent) break;
//             memo[i][j] = max(memo[i][j - 1], memo[i + ageent / 2][j - 1]);
//             cout << memo[i][j] << " ";
//         }
//         puts("");
//     }
// }

// int Queary(int l, int r)
// {
//     int res = -inf;
//     int dist =  r - l + 1;

//     for(int i = 0; i < 20; i++){
//         if(1 << i > dist) break;
//         if( (1 << i) & dist) res = max(res, memo[l][i]), l += 1 << i;
//     }

//     return res;
// }

// int main()
// {
// #ifdef PARTHO
//     freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
//     freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
//     int start_time = clock();
// #endif
// //FastIO;

// int n;

// sc1(n);

// vi v(n);

// FOR(i, 0, v.size()) sc1(v[i]);
// preprocess(v);
// int l, r;
// sc2(l, r);
// int res = Queary(l - 1, r - 1);
// printf("%d\n", res);
 

// #ifdef PARTHO
//     int end_time = clock();
//     printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
// #endif

//     return 0;
// }
// ///Before submit=>
// ///    *check for integer overflow,array bounds
// ///    *check for n=1