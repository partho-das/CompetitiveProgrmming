#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
 
#define PI  2*acos(0.0)
#define pf  printf
#define sf  scan
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
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
 
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
//____________________________________________________________________________________________________________________________________
 
std::vector<ll> v;
ll my_sqrt(ll n)
{
	ll low = 0, high = 1e9 + 2, mid;

	int cnt = 64;
	while(cnt--)
	{	
		mid = (low + high) >> 1 ; 
		//fap(mid);
		//cout << mid * mid << endl;
		if(mid * mid <= n) low = mid;
		else high = mid;
	}

	return mid;
}




int gen()
{
	set<ll> st;
	for(ll i = 2; i <= 1e6; i++)
	{
		ll cnt = log2(1e18) / log2(i);
		cnt-= 2;
		cnt = max(0ll, cnt);
		ll agent = i * i * i;
		for(ll j = 0; j < cnt; j++ )
		{
			st.insert(agent);
			//cout << agent << endl;
			agent *= i;
		}
	}


	ll a = st.size();
	for(auto it : st)
	{
		ll sq = my_sqrt(it);
		if(sq * sq != it){
			v.pb(it);
		}
	}
	return 0;
}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
FastIO;

gen();

int q;
cin >> q;

while(q--)
{
	ll l, r;

	cin >> l >> r;
	ll sum = my_sqrt(r) - my_sqrt(l - 1);

	//cout << my_sqrt(r) << endl;

	sum += (upper_bound(all(v), r) - v.begin()) - (lower_bound(all(v), l) - v.begin());
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