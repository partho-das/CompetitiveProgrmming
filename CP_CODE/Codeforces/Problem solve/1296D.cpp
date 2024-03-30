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
 
ll n,a,b,k,value, both,cnt = 0,ck = 0;
void fa()
{
	value = value % both;	
    if(value <= a && value) cnt++,ck = 1;
    else if(k) cnt++,k--,ck = 1;
    else ck = 0;
}


int fb()
{
	value = value % both;	
    if(value == 0 || value>b) cnt++,ck = 1;
    else if(k) cnt++,k--,ck = 1;
    else ck = 0;
}

 
int main(){
 
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
    FastIO;

    	cin >> n >> a >> b >> k;
    	both = a + b;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> value;
    		cout << value;
    		 fa();
    		

    		cout << " " << ck <<" " <<  k << endl;

    	}

    	cout << cnt << endl;
 
 
  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
