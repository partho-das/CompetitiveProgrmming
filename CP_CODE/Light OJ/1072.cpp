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

int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif


       int test;
       sf("%d",&test);
       
       TEST(test)
       {
          double R,res;
          int n;
          cin >> R >> n;
          double high = R,low = 0,mid = (high+low)/2,x = R-mid , need = (n*x)/(2*PI);
    
          int lst = 32;
          while(lst--)
          {
             
            
              if((need)>=R)
              {
                
                res = mid*.5;
                low = mid;
              }
            else  high = mid;
            mid = (high+low)/2;
           x = R-mid , need = (n*x)/(2*PI);
           printf("need = %lf R = %lf\n",need,R);
            printf("high = %lf low = %lf mid = %lf\n",high,low,mid);
            
            printf("\n");
          }

          printf("Case %d: %.8lf\n",cse,res*2);
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
