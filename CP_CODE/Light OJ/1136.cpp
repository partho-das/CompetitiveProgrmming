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
       TEST(test)//found some pattan.
       {
          int a,b;
          int sum = 0;
          scanf("%d%d",&a,&b);

          if(a!=b)
          {

          if(a>b) swap(a,b);
          
          if(a%3 == 0) sum+=1,a++; // taking down
          else if(a%3 == 2) sum+=2,a+=2;

          if(b%3==1) // taking up
            b--;
          else if(b%3==2)
            sum++,b-=2;

          int def = b-a +1; // inclusive defference.
          sum+= (def/3)*2; // finding pair.
          }
          else
          {
            if(a%3==0||a%3==2) sum=1;
          }

          printf("Case %d: %d\n",cse,sum);


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
