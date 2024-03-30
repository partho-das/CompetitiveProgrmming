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
       cin >> test;
       while(test--)
       {
          int n;

       std::vector<int> v;
          std::map<int, bool> mep;
          sc(n);
          int value;
          for(int i = 0; i < n;i++)
          {
            sc(value);
            //cout << value << endl;

            if( value %2 == 0)
            {
              mep[value] = 1;
              v.pb(value);
            } 
          }
          sort(v.begin(), v.end());

          // for(auto it : v)
          //   cout << it << endl;

          
          int cnt = 0;
          for(int i = v.size()-1;i>=0;i--)
          {
              int value  = v[i];
              
             
              while(value%2 == 0 && mep[value] == 1)
              {


                mep[value] = 0;
                value = value>>1;
                //cout << value*2 << endl;
                cnt++;
                 

                if(mep.find(value) !=mep.end())
                {
                    v[i] = 1;
                    
                    break;
                }
                else
                {
                  mep[value] = 1;
                }

                  }
          }

          
          


         cout << cnt << endl;


       }
    
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


