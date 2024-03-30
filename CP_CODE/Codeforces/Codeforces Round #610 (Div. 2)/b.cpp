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


 	int test;


 	cin >> test;

 	while(test--)
 	{
 		int n,p,k,value;

 		std::vector<int> v;

 		cin >> n >> p >> k;

 		FOR(i,0,n)
 		{
 			cin >> value;
 			v.pb(value);

 		}
 		sort(all(v));


 		
 		

 		int sum = 0,pre = 0,ans = 0,cnt = 0;

 		for(int i = 0;i<=k;i++)
 		{
 			sum = pre;
 			if(sum > p) break;
 			cnt = i ;

 			for(int j = i + k - 1 ; j<n ; j+= k)
 			{
 				if(sum+v[j] > p) break;

 				sum+= v[j];
 				cnt+=k;
 			}

 			ans = max(ans,cnt);
 			pre += v[i];
 			 		}

 		cout << ans << endl;


 	}



  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}