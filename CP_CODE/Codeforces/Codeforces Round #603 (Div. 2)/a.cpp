#include <bits/stdc++.h>
using namespace std;

//macros_______________________________________________________________________________________________________________________________
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
#define FOR(i,a,n)    for(int i = a; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)
//____________________________________________________________________________________________________________________________________


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
          int arr[4];
          int n = 3;
          for(int i = 0;i<n;i++)
            cin >> arr[i];
          sort(arr,arr+n);

          int def = arr[2]-arr[1];

          def = min(arr[0],def);

          arr[2] -= def;
          ll sum = def;

          arr[0]-=def;

          int mid = (arr[0]+1)/2;

          sum += min(arr[2],mid);

          

          arr[2]-=mid; 
          mid = arr[0]-mid;
          sum+= min(arr[1],mid);
          arr[1]-=mid;


          if(arr[1]<=0) arr[1] = 0;
          sum+=min(arr[1],arr[2]);


          cout << sum << endl;






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
