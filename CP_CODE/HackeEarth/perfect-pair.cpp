#include <bits/stdc++.h>
using namespace std;
 
 
//____________________________________________________________________________________________________________________________________
 
#define PI  2*acos(0.0)
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
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



int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;


   	int x, limit = 2e3,fre[2009],squre[2009],cubes[2009];
   	std::vector< int > stor;
   	memset(squre,0,sizeof squre);
   	memset(cubes,0,sizeof cubes);

   	for(x = 1 ; x*x <= limit ;x++) squre[x*x] = 1;
   	for(x = 1 ; x*x*x <= limit ; x++) cubes[x*x*x] = 1;

   	int test;
   	cin >> test;

   	while(test--)
   	{
   		memset(fre,0,sizeof fre);
   		stor.clear();
	   	int n,value;
	    cin >> n; 
	    FOR(i,0,n) {
	   		cin >> value;
	   		if(!fre[value]) stor.pb(value);
	   		fre[value]++;
	    }

	    int cnt = 0;
	    for(int i = 0; i < stor.size() ;i++)
	    {
	    	for(int j = i; j < stor.size() ; j++)
	    	{
	    		
	    		if( stor[i] == stor[j] && (squre[stor[i]*2] || cubes[stor[i]*2]) && fre[stor[i]])
	    			cnt+= (fre[stor[i]]*(fre[stor[i]] - 1))/2;
	    		else if( stor[i] != stor[j] && (squre[stor[i] + stor[j]] || cubes[stor[i] + stor[j]]) && fre[stor[i]] && fre[stor[j]])
	    			cnt+= fre[stor[i]] * fre[stor[j]];
	       	}
	    }

	    cout << cnt << endl;
	  
 	}
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
 
 
 
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1