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


      ll a,b,c,d,e,f;


       cin >> a >> b >> c >> d >> e >> f;
      ll sum = 0;
       if(f>=e)
       {
         ll mn = min(b,c);
          mn = min(d,mn);

          d-=mn;
          sum+= (mn*f);

          mn = min(d,a);

          sum+= mn*e;

       }
       else
       {


        ll mn = min(d,a);
         sum+= mn*e;
          d-=mn;
         mn = min(b,c);
          mn = min(d,mn);
          sum+= (mn*f);

       }

       cout << sum << endl;

    
  #ifdef PARTHO
     int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


