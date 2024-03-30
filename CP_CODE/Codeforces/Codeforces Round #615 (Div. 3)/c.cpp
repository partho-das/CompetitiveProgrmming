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
    ll n;
    cin >> n;

   std::vector<ll> primefact;

    while(n%2 == 0)
    {
     
      primefact.pb(2);
      n = n >> 1 ;
    }
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
    
           primefact.pb(i);
            n = n/i;  
        }  
    }  
    

   
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)
    {
      
      primefact.pb(n);
    }


    ll a = 1,b = 1,c = 1,i = 1;

    if(primefact.size() >=3 )
    {
        for(auto it : primefact)
        {
          if(i == 1) a = it;
          else if(i == 2)
          {

           b *= it;
           if(a==b) 
            i--;
          }
          else c*=it;
          i++;
        }

    }

      if(a!=b && b!= c && a!= c && a>=2 && b>=2 && c>=2)
        {
        cout << "YES" << endl;  
        cout << a << " " << b << " "  << c << endl;
        }
        else cout << "NO" << endl;
    

 
  }
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}