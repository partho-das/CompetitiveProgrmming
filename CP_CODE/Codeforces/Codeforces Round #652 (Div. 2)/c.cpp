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
#define sc1(n)      sc("%d",&n);
#define sc2(n, m)   sc("%d%d", &n, &m);
#define scf(f)      sc("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++) 
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
//____________________________________________________________________________________________________________________________________

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;


int test;


sc1(test);

while(test--)
{
	int n, k;

	sc2(n, k);
	vi v(n), w(k);
	int value;
	for(int i = 0; i < n; i++)
	{
		sc1(value);
		v[i] = value;
	}
	sort(all(v), cmp);

	ll sum = 0;
	int l = 0;
	for(int i = 0; i < k; i++)
	{
		sc1(value);
		w[i] = value;	
	}   sort(all(w));

	for(int i = 0; i < k ; i++)
	{
		if(w[i] == 1) sum += (long long)( 2 * v[l++]);
		else sum += v[l++];
		w[i]--;
	}
		//cout << sum << endl;



	for(int i = 0; i < k; i++)
	{
		ll mn = INF;
		for(int j = l; j < v.size() && w[i]; j++, l++, w[i]--)
		{
			mn = min(mn, (long long)v[j]);
			//mx = max(mx, (long long)v[j]);
		}
		//cout << w[i] << " " << l << " " << sum << endl;

		if(mn != INF) sum += mn;
	}

	cout << sum << endl;

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