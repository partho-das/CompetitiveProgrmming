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

bool palck(string &str)
{
	for(int i = 0,j = str.size() - 1;i <= j;i++,j--)
		if(str[i]!=str[j]) return 0;
	return 1;
}



int main(){
 
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif

FastIO;

	int n,m;

	cin >> n >> m;
	std::vector<string> v;
	string str,mstr;
	int indx = -1,ck = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> str;
		if(palck(str) && ck == 0) indx = i,ck = 1,mstr = str;
		else v.pb(str);
	}

	
	for(int i = 0;i < v.size();i++)
	{
		for(int j = i + 1;j < v.size();j++)
		{
			str = v[i] + v[j];
			if(palck(str))
			{
				mstr = v[i] + mstr;
				mstr += v[j];
				break;
			}
		}
	}
	cout << mstr.size() << endl;
	cout << mstr << endl;

   

    
  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
ideone.com/y9Qfjc