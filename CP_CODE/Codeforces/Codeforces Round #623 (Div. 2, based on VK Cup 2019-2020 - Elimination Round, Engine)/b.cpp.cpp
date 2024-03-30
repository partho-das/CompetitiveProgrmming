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
    	int bus,tram,ihave;
    	string str;
    	cin >> bus >> tram >> ihave >> str;
    	std::vector<pii> v;
    	int value;
    	if(str[0] == 'A') value = bus;
    	if(str[0] == 'B') value = tram;
    	ll sum = value;
    	v.pb({value,1});
    	for(int i = 1;i < str.size();i++)
    	{
    		if(str[i] == 'A') value = bus;
	    	if(str[i] == 'B') value = tram;
	    	
    		if(str[i - 1] != str[i])
    		{	
    			
    			
    			if(i != str.size() - 1){
    			//cout << sum << " " << i + 1<< endl;
    			v.pb({value,i + 1}),sum+=value;
    			}
    		}
    	}
    	int ck = 0;
    	for(auto it : v)
    	{
    		if(sum <= ihave){
    			cout << it.ss << endl;
    			//cout << sum << endl;
    			ck = 1;
    			break;
    		}
    		else{
    			sum-= it.ff;
    		}
    	}
    	if(!ck)
    	cout << str.size() << endl;


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
