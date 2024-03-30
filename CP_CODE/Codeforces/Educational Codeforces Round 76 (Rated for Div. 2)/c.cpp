#include <bits/stdc++.h>
using namespace std;


#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)

const int maxn = 2e5+7;
int arr[maxn];
int pos[maxn];

int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif

  
    int test;
    cin >> test;
    while(test--)
    {
      memset(pos,0,sizeof pos);
      int n;
      cin >> n;
      int indx = 1;
      int mind = 1e9+7;
      for(int i = 0;i<n;i++,indx++)
      {
          sc("%d",&arr[i]);

          if(pos[arr[i]] !=0)
          { //cout << arr[i]  << " i = " << i << endl;
            mind = min(mind,abs(pos[arr[i]]-indx)+1);
           // cout << "pos = " << pos[arr[i]] << " " <<  indx << endl;
          }
          pos[arr[i]] = indx;
         // cout << i <<indx << endl;
         

      }
      if(mind != 1e9+7)
      cout << mind << endl;
    else cout << -1 << endl;
    }

       
      

  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}


///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
