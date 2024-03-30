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

    int n,l;
    ll cnt = 0;
    cin >> n ;
    int yescnt = 0;
    multiset <int, less <int> > mxcontain;
    map < int , int > mep; 
    
    int value ; 
    for(int i = 0;i < n; i++)
    {
        cin >> l;
        int mn = inf,mx = -1,ck = 0;
        for(int j = 0 ; j < l; j++)
        {
          cin >> value;
          if(mn < value) ck = 1;
          mn = min(mn,value);
          mx = max(mx,value);
        }

        if(ck)
        {
          cnt += 2*n-1 - 2*(yescnt);
          yescnt++;
        }
        else{

          mep[i] = mn;
          mxcontain.insert(mx);
        
        }
       
    }


     std::vector<int> v;

    for(auto it : mxcontain)
    {
        v.pb(it);
    }

  
    
    for(auto it : mep)
    {
        int low = 0,high = v.size() - 1,indx = -1,mid = high + low >> 1;
      

        while(low <= high)
        {
            //cout << "HI" << endl;
            if(v[mid] <= it.ss)
            {
              low = mid + 1;
            }
            else {
              high = mid - 1;
              indx = mid;
            }
            mid = high + low >> 1;
           // return 0;
        }
        if(indx != -1 )
        cnt += ( v.size()-1 - indx + 1);


    }
    cout << cnt << endl;




 
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
 
 
 
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1