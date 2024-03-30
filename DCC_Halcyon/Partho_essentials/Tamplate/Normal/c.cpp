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
	int nc = n;

	if(n == 1)
	{
		cout << "FastestFinger" << endl;
		continue;
	}
	int even = 0, odd = 0;

	if(n % 2 == 0)
	{
		while(n % 2 == 0) even++, n = n >> 1;
	}


	for(int i = 3; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			odd++;
			n /= i;
		}
	}

	if(n > 1)
		{
			if(n & 1) odd++;
			else even++;
		}

	int move = 0;



	if(!even){
		
		if(nc == 1) move = 1;
		else move = 2;
		//cout << nc << endl;
	}
	else if(!odd){ 
		if(even == 1) move = 2;
		else move = 1;

	}
	else{

		if(odd == 1 && even == 1) move = 1;
		else move = 2;
	}


	if(move == 2) cout << "Ashishgup" << endl;
	else cout << "FastestFinger" << endl;
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