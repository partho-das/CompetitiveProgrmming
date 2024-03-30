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
       while(test--)
       {
          int n;

          sc(n);

          string str;
          int mcnt = 0;
          int ckone = 0,ckzero = 0,one = 0,zero = 0;

          std::vector< int > v[5];
          for(int i = 0;i<n;i++)
          {
            cin >> str;
            if(str[0] == str.back() && str[0] == '0') // 010
              {
                ckzero = 1;
                v[0].pb(i+1);
              }
            else if(str[0] == str.back() && str[0] == '1') // 101
              {
                ckone = 1;
                v[1].pb(i+1);
              }
            else if(str[0] != str.back() && str[0] == '0') // 011
            {
              v[2].pb(i+1);
              zero++;
            }
            else if(str[0] != str.back() && str[0] == '1') // 110
            {
              v[3].pb(i+1);
              one++;
            }
          }

         

          int cnt = 0,ck = 0;
          vi print;
          if(ckone && ckzero)
          {
              if((one+zero) & 1)
              {
                  if(one>zero)
                  {
                    cnt = ((one+zero)+1)/2;
                    int ex = one - cnt;
                    for(int i = 0;i<v[3].size() && ex;i++)print.pb(v[3][i]),mcnt++,ex--;
                  }
                  else
                  {

                    cnt = ((one+zero)+1)/2;
                    int ex = zero - cnt;
                    for(int i = 0;i<v[2].size() && ex;i++)print.pb(v[2][i]),mcnt++,ex--;
                  }
              }
              else{
                /// on ans;
                ck = 1;
              }
          }
          else
          {
            if((one+zero) & 1)
            {

              if(one>zero)
                  {
                    cnt = ((one+zero)+1)/2;
                    int ex = one - cnt;
                    for(int i = 0;i<v[3].size() && ex;i++)print.pb(v[3][i]),mcnt++,ex--;
                  }
                  else
                  {
                    cnt = ((one+zero)+1)/2;
                    int ex = zero - cnt;
                    for(int i = 0;i<v[2].size() && ex;i++)print.pb(v[2][i]),mcnt++,ex--;
                  }
            }
            else{

               if(one>=zero)
                  {
                    cnt = ((one+zero)+1)/2;
                    int ex = one - cnt;
                    for(int i = 0;i<v[3].size() && ex;i++)print.pb(v[3][i]),mcnt++,ex--;
                  }
                  else
                  {

                    cnt = ((one+zero)+1)/2;

                    int ex = zero - cnt;
                    for(int i = 0;i<v[2].size() && ex;i++)print.pb(v[2][i]),ex--,mcnt++;
                  }
             

       }
     }
      if(ck) mcnt = -1;

      if(mcnt !=-1 )
      {
        cout << mcnt << endl;
        for(auto it : print) cout << it <<" ";
      }
      else
      cout << mcnt << endl;
    cout << endl;
   }

    
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}



