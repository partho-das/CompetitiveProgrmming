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
 
 
 
 
int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;

   int n,m;
   cin >> n >> m;
   std::vector<int> a(n),b(n),c(n);

   for(int i = 0; i < n; i++)
   	cin >> a[i];
   for(int i = 0; i < n; i++)
   	cin >> b[i];

   set <int> uniqx; 

   sort(all(a));
   sort(all(b));

  
   	for(int i = 0;i < n; i++)
   	{
   		if(a[i] <= b[0])
   			uniqx.insert(b[0] - a[i]);
   		else uniqx.insert(m - a[i] + b[0]);
   	}

   

   for(auto it : uniqx)
   {

   		bool flug = false;
   		ll value;
   		for(int i = 0 ;i < n; i++)
   		{
   			c[i] = (a[i]+it)%m;
   		}

   		sort(all(c));

   		for(int i = 0;i<n;i++)
   		{
   			if(c[i] != b[i]){
   				flug = true;
   				break;
   			}
   		}


   		if(flug == false)
   		{
   			 cout << it << endl;
   			 return 0;	
   		}


   }

  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}