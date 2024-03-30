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

       sc(test);
       TEST(test)
       {
            int x[3],y[3];

            scanf("%d%d",&x[0],&y[0]);
            scanf("%d%d",&x[1],&y[1]);
            printf("Case %d: ",cse);

              ll  first = x[0]+y[0],second = x[1]+y[1]; 
            if((first&1 && second%2 == 0) || (first%2 == 0 &&  second&1))
              puts("impossible");
            else if( (x[0] == x[1]) && (y[0] == y[1]))
              puts("0");
            else if(abs(x[0]-x[1]) == abs(y[0]-y[1]))
              puts("1");
            else puts("2");
       }  

   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


