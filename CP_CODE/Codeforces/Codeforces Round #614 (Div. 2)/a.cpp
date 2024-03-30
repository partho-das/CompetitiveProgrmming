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
   //FastIO;
 
     int test;
 
 
     cin >> test;
     while(test--)
     {
     		int n,s,k;
     		cin >> n >> s >> k;
     		int arr[10009];
 
     		int ck = 0;
     		for(int i = 0; i<k ;i++)
     		{
 
     		cin >> arr[i];
     		if(arr[i] == s)
     			ck = 1;
     		}
     		sort(arr,arr+k);
     		
     		int dis = inf;
     		for(int i = 1;i<k;i++)
     		{
     			if(arr[i] - arr[i-1] > 1)
     			{
     				int value = arr[i-1] + 1;
     				dis = min(dis,abs(value-s));
    
     				value = arr[i] - 1;
     				dis = min(dis,abs(value-s));
 
     				
     				
     			}
     		}
 
 
     		
     			if(arr[0]-1 >= 1)
     			{
     				dis = min(dis,abs(arr[0]-1-s));
     			}
 
     			 if(arr[k-1] + 1 <= n)
     			{
     				dis = min(dis,abs(arr[k-1]+1-s));
     			}
     		
 
 
     		if(ck == 0)
     			dis = 0;
 
 
     		cout << dis << endl;
     		
 
 
 
     		
 
 
     }
 	
 
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}