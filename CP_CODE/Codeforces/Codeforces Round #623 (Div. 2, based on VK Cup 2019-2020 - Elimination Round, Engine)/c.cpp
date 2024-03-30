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

bool taken[250],paichi[250];;
int jora[250];

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
    	memset(taken,0,sizeof taken);
    	memset(paichi,0,sizeof paichi);
    	int n;
    	cin >> n;

    	vector<int> v(n);
    	int ck = 0;
    	for(int i = 0;i<n;i++)
    	{
    		cin >> v[i];
    		if(paichi[v[i]] == 0)
    		{
    			paichi[v[i]] = 1;
    			taken[v[i]] = 1;
    		}
    		else{
    			ck = 1;
    		}
    	}
    	if(ck == 1){
    		cout << -1 << endl;
    		continue;
    	}
    	
    	for(int i = 0; i < v.size();i++)
    	{
    		ck = 1;
    		for(int j = v[i]+1;j <= 2*n ;j++)
    		{
    			if(!taken[j])
    			{
    				jora[v[i]] = j;
    				taken[j] = 1;
    				ck = 0;
    				break;
    			}
    		}
    		if(ck == 1)
    		{
    			break;
    		}
    	}
    	if(ck == 1){
    		cout << -1 << endl;
    		continue;
    	}


    	for(auto it : v)
    	{
    		cout << it << " " << jora[it] << " ";
    	}
    	cout << endl;




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
