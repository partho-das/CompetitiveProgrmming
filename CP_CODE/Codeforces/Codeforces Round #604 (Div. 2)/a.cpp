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
          string str;
          cin >> str;
          for(int i = 0;i<str.size();i++)
          {
            if(str[i] == '?')
            {
              if(i==0)
              {
                if(str[i+1]!='a')
                  str[i] = 'a';
                else if(str[i+1]!='b')
                  str[i] = 'b';
                else if(str[i+1] != 'c')
                  str[i] = 'c';
              }
              else if(i == str.size()-1)
              {
                if(str[i-1]!='a')
                  str[i] = 'a';
                else if(str[i-1]!='b')
                  str[i] = 'b';
                else if(str[i-1] != 'c')
                  str[i] = 'c';
              }
              else
              {
                 if(str[i-1] != 'a' && str[i+1]!='a')
                  str[i] = 'a';
                  else if(str[i-1] != 'b' && str[i+1]!='b')
                    str[i] = 'b';
                  else if(str[i-1] != 'c' && str[i+1]!='c')
                    str[i] = 'c';              }
            }
          }
          int ck = 0;
          for(int i = 0;i<str.size()-1;i++)
          {
            if(str[i]==str[i+1])
            {
              ck = 1;
              break;
            }
          }
          if(!ck)
            cout << str <<endl;
          else puts("-1");
       }

       

      

   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


