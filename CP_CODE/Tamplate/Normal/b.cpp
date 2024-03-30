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
 



int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
FastIO;


int test;

cin >> test;

while(test--)
{
	int n;

	cin >> n;

	vi v(n * 2);

	int odd = 0;
	for(int i = 0; i < n * 2; i++)
	{
		cin >> v[i];
		//cout << v[i] << endl;
		if(v[i] & 1) odd++;
	}



	std::vector<int> reso, rese;
	
	if(odd & 1)
	{

		for(int i = 0;i < n * 2; i++)
		{
			if(v[i] & 1)
			{
				v[i] = -1;
				break;
			}
		}

		for(int i = 0;i < n * 2; i++)
		{
			if(v[i] % 2 == 0)
			{
				v[i] = -1;
				break;
			}
		}

		
		for(int i = 0; i < n * 2; i++)
		{
			if( v[i]!= -1 && v[i] & 1)
			{
				reso.pb(i + 1);
			}
		}

		for(int i = 0; i < n * 2; i++)
		{
			if( v[i]!= -1 && v[i] % 2== 0)
			{
				rese.pb(i + 1);
			}
		}
	}
	else{
		if(odd > 1)
		{
			int ck = 0;
			for(int i = 0;i < n * 2; i++)
			{
				if(v[i] & 1 && ck != 2)
				{
					v[i] = -1;
					ck++;
				}
				if(ck == 2) break;
			}

		}
		else{

			int ck = 0;
			for(int i = 0;i < n * 2; i++)
			{
				if(v[i] % 2 == 0 && ck != 2)
				{
					v[i] = -1;
					ck++;
				}
				if(ck == 2) break;
			}


		}

		for(int i = 0; i < n * 2; i++)
		{
			if( v[i]!= -1 && v[i] & 1)
			{
				reso.pb(i + 1);
			}
		}

		for(int i = 0; i < n * 2; i++)
		{
			if( v[i]!= -1 && v[i] % 2== 0)
			{
				rese.pb(i + 1);
			}
		}
	}


	for(int i = 0, j = reso.size() - 1; i < j; i++, j--)
		cout << reso[i] << " " << reso[j] << endl;


	for(int i = 0, j = rese.size() - 1; i < j; i++, j--)
		cout << rese[i] << " " << rese[j] << endl;




}



 
 
#ifdef PARTHO
   // int end_time = clock(); 
   /// printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif
 
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1