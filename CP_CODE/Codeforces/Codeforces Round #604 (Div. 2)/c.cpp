#include <bits/stdc++.h>
using namespace std;


//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
//____________________________________________________________________________________________________________________________________

const int maxn = 4e5+10;
int arr[maxn];

int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif

       int test;
       sc(test);
       while(test--)
       {
          int n;
          sc(n);

          int mid = n/2;

          for(int i = 1;i<=n;i++) sc(arr[i]);
            int gold = 0,selver = 0,bornze = 0;
          int last = arr[mid],ck = 3;
          int stop = mid;
          for(int i = 1;i<=mid-1;i++)
          {
            if(arr[i] == arr[i+1])
              gold++;
            else
            {
              gold++; 
              stop = i;
              break;
            }
          }
          int skip = arr[mid];
          if(arr[mid] == arr[mid+1])
          {
             
            for(int i = mid;i>stop;i--)
            {
              if(skip == arr[i])
              {
                continue;
              }
              else
              {
                mid = i;
                break;
              } 
            }
          }


            for(int i = mid;i>stop;i--)
            {
              if( last==arr[i]&&ck==3 || bornze<=gold)
              { 
                 bornze++;
                 last = arr[i];
              }
              else if(ck == 3)
              {
                ck--;
                selver++;
                last = arr[i];
              }
              else if(ck == 2)
              {
                selver++;
              }
             
            }


            if(gold && selver && bornze && ((selver>gold) && (bornze>gold)) )
              printf("%d %d %d\n",gold,selver,bornze);
            else printf("0 0 0\n");
       }

      

   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


