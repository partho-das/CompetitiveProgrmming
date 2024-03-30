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
          int x1,x2,y1,y2;
          
          scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
          if(x1>x2) swap(x1,x2);
          if(y1>y2) swap(y1,y2);

          int n,a,b;
          sc(n);
          printf("Case %d:\n",cse);
          FOR(i,0,n)
          {
            scanf("%d%d",&a,&b);
            
            if((a>=x1 && a <= x2) && (b >= y1 && b <= y2))
              printf("Yes\n");
            else puts("No");
          }

       }

   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


