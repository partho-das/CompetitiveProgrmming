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

      int a,b,c,d;

      cin >> a >> b >> c >> d;
      int ck = 3;
      int arr[100009],x = 0;
      int ac = a,bc = b,cc = c,dc = d;
      int sum = (a+b+c+d);
      int mck = 4,exit  = 0;
      while(mck--)
      {

        x = 0,ck = mck,a = ac,b = bc,c = cc,d = dc,exit = 0;
        for(int i = 0;i<sum;i++)
        {
          if((d != 0) && (ck == 3))
            {
                arr[x++] = 3;
                d--;
                ck = 2;
            }
          else if((c != 0) && (ck == 2)){

              arr[x++] = 2;
              if(d) ck = 3;
              else ck = 1;
              c--;
            }
          else if( (b != 0) && (ck == 1)){

                arr[x++] = 1;
                if(c) ck = 2;
                else ck = 0;
                b--;
                
            }
          else if((a != 0) && (ck == 0)) {
              arr[x++] = 0;
              if(b) ck = 1;
              a--;
            }
          else {
              exit = 1;
              break;
            }
        }

        if(exit == 0){
          for(int i = 0;i<x-1;i++){
            if(abs(arr[i]-arr[i+1]) !=1){
                exit = 1; 
                break;
              }
          }
        }
          if(exit == 0){
            puts("YES");
            for(int i = 0;i<x;i++)
            cout <<arr[i] << " ";
          cout << endl;
          return 0;
        }
      }

      printf("NO\n");


   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


