#include <bits/stdc++.h>
using namespace std;

//macros
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
          ll a,b;

          cin >> a >> b ;


          if(a<b) swap(a,b);
          if(a == b*2 )
          {  
            printf("YES\n");
            continue;
          }


         else{

              ll low = 1,high = b,mid = high+low>>1;
              int ck = 0;
              while(low<=high)
              {
              
                if(((a-(2*mid))==b-mid) )
                {
                  ck = 1;
                  break;
                }
                else if( a < mid*2)
                {
                  high = mid-1;
                }
                else if(a>mid*2)
                {
                  
                  low = mid+1;
                }
                else if(a==mid*2)
                {
                  ck = 0;
                  break;
                }
                mid = high+low>>1;
              }

              // if(ck==0)
              // {
              //    low = 1,high = b,mid = high+low>>1;
              //   while(low<=high)
              //     {
                    
              //       if((abs(b-(2*mid))==abs(a-mid) ))
              //       {
              //         ck = 1;
              //         break;
              //       }
              //       else if( b < mid*2)
              //       {
              //         high = mid-1;
              //       }
              //       else if(b>mid*2)
              //       {
                      
              //         low = mid+1;
              //       }

              //        else if(b==mid*2)
              //       {
              //         ck = 0;
              //         break;
              //       }
              //       mid = high+low>>1;
              //     }
              // }


              

              if(ck==1)
              {
                printf("YES\n");
              }
              else
              {
                printf("NO\n");
              }
        }
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
