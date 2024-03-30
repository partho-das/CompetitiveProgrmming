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
const int maxn = 2e5+10;
int lmin,rmax,pos[maxn];
bool pri[maxn];

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
        sc(n);
        int ck = 0;
        int value,one;

        for(int i = 1;i<=n;i++)
        {
            sc(value);
            pri[i] = 0;
            pos[value] = i;
        }


        int cn = n,onep = pos[1],m = 1;
        lmin = onep;
        rmax = onep;
        for(int i = 1;i<=n;i++,m++)
        {
            if(pos[m]<onep)
            {
              lmin = min(pos[m],lmin);
            }
            else
            {
              rmax = max(pos[m],rmax);
            }


            int sum = abs(lmin-onep)+abs(rmax-onep) + 1;

            if(sum==m)
            {
              pri[m] = 1;
            }

        }

        for(int i = 1;i<=n;i++)
          printf("%d",pri[i]);
        cout << endl;
          
       }
      

   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


