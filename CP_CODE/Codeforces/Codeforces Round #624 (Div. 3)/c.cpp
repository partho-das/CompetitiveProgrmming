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
 
const int maxn = 2e5 + 5;
ll frecnt[27][maxn],sum[27];
 
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
    	int n,m;
    	string str;
    	cin >> n >> m;
    	cin >> str;
    	std::vector<int> v(m);
    	
 
    	for(int i = 0;i < m;i++)
    	{
    		cin >> v[i];
 
    	}
    	
    	str = "#" + str;
    	for(int i = 0;i < 26;i++)
    	{
    		frecnt[i][0] = 0;
    		sum[i] = 0;
    		for(int j = 1;j < str.size();j++)
    		{
    			frecnt[i][j] = frecnt[i][j - 1];
    			if(str[j] == char(i + 'a')){
    				frecnt[i][j]++;
    			}
    			
    		}
 
    	}
 
 
    	for(int j = 1;j < str.size();j++)
    		{
    			sum[(str[j] - 'a')]++;
    		}
 
 
 
 
    	for(int i = 0;i < v.size();i++)
    	{
    		for(int j = 0; j < 26;j++)
    		{
    		//	cout << v[i] <<" "<< frecnt[j][v[i]] << " " << char(j + 'a' - 1) << endl;
    			sum[j]+= frecnt[j][v[i]];
    		}
    	}
 
			for(int i = 0; i < 26;i++)
    		{
    			cout << sum[i] << " ";
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