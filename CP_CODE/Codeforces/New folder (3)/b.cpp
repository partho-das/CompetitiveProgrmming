#include <bits/stdc++.h>
using namespace std;


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
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)

int stor[1000020];
int visit[1000020];
int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif
       std::vector<int> v,vis;
       int n;
       cin >> n;
      
      int day = 1;
      int in = 0,out = 0;
    
      int ck = 1;
      int cnt = 0,value;
      int last = 0;
      int turn = 0;
      for(int i = 0;i<n;i++)
      {
          cin >> value;

          if(value<0)
            vis.push_back(-value);
          else
          vis.push_back(value);

          if(value>0)
          {
            in++;
            stor[value]++;
          
            if(cnt>0 && visit[value])
            {
              ck = 0;
              break;
                
            }
            visit[value]++;
            cnt++;
           
            if(stor[value]>1)
            {
              ck = 0;
               break;
            }
          }
          else
          {
            stor[-value]--;
             out++;
             cnt--;
             if(cnt==0)
             {
              
               v.pb(i+1);

                for(int j = 0;j<vis.size();j++){
                  visit[vis[j]] = 0;
                }
                vis.clear();
             }
             
             if(stor[-value]<0)
              {
                ck = 0;
              }
          }
      }
       
        if(cnt!=0)
          ck = 0;
          if(ck == 0)
          {
            puts("-1");
          }
          else
          {
            printf("%d\n",(int)v.size());

            for(auto it : v)
            {

              cout << it - last <<" "; 
              last = it;
            }
            cout << endl;

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
