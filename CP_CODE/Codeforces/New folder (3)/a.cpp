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
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)



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
          std::vector<int> v;
          std::vector<int> v2;
         int n;
         cin >> n;
         int value;
         for(int i = 0;i<n;i++)
         {
            sc("%d",&value);
            v.push_back(value);
         }

         int p = 0,q = n-1;
         for(int i = 0;i<n;i++)
         {
          sc("%d",&value);
          v2.push_back( (v[i] - value) );
         }
         set<int> st;
         for(int i = 0;i<n;i++)
         {
            if(v2[i] !=0)
            {

              p = i;
              break;
            }
         }
       
         for(int i = n-1;i>=0;i--)
         {
            if(v2[i] !=0)
            {

              q = i;
              break;
            }
         }
        // cout << p << " " << q << endl;
         for(int i = p;i<=q;i++)
         {
            st.insert(v2[i]);
         }

         if(st.size()==1)
         {
            int ck  = *st.begin();
            if(ck>0)
            {
              printf("NO\n");
            }
            else printf("YES\n");
         }
         else if(st.size()==0) printf("YES\n");
         else printf("NO\n");
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
