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
typedef vector<long long> vll;
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

int arr[200009],stor[200009];
std::vector<int> notgiven,notrecived,cmn;

int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;


   int n;

   cin >> n;
   FOR(i,1,n+1)
   {
        cin >> arr[i];
        if(arr[i] == 0) notgiven.pb(i);
        stor[arr[i]] = 1;
   }

   for(int i = 1;i <= n;i++)
   {
        if(stor[i] == 0)
        {
            notrecived.pb(i);
            if(arr[i] == 0) cmn.pb(i); 
        }
   }

    sort(notrecived.begin(), notrecived.end());
    sort(cmn.begin(), cmn.end());

   int value;
   for(int i = 0;i < cmn.size();i++)
   {
        value = notrecived.back();
        if(value != cmn[i]){
            arr[cmn[i]] = value;
            notrecived.pop_back();
        }
        else{
            swap(notrecived[notrecived.size() -1], notrecived[notrecived.size() - 2]);
           
            value = notrecived.back();
            arr[cmn[i]] = value;
            notrecived.pop_back();

        }
   }

   sort(notrecived.begin(), notrecived.end());
   sort(notgiven.begin(), notgiven.end());
    

   for(int i = 0;i < notgiven.size();i++)
   {

        value = notrecived.back();
        if(value != notgiven[i] && !arr[notgiven[i]]){
            arr[notgiven[i]] = value;
            notrecived.pop_back();
        }
        else{
            if(!arr[notgiven[i]])
            {
                swap(notrecived[notrecived.size() -1], notrecived[notrecived.size() - 2]);
                value = notrecived.back();
                arr[notgiven[i]] = value;
                notrecived.pop_back();
            }

        }
   }

   FOR(i,1,n+1)
   cout << arr[i] << " ";
   cout << endl;
   

  

  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
 
 
 
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1