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

const int maxn = 2e5+7;
int mpow[maxn];

std::vector<pair<int,int>> hero;

bool cmp(pi &a,pi &b)
{
    if(a.ss>=b.ss)
    {
       return 1;
       if(a.ss==b.ss)
        return a.ff>b.ff;
    }

    return 0;
}

int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif

    int test;
    sc("%d",&test);
    while(test--)
    {
      int monstcnt,herocnt;
      sc("%d",&monstcnt);
      for(int i = 0;i<monstcnt;i++)
      {
        sc("%d",&mpow[i]);
      }
      sc("%d",&herocnt);
      for(int i = 0;i<herocnt;i++)
      {
          int a,s;
          sc("%d%d",&a,&s);
          hero.pb({a,s});
      }
      sort(hero.begin(), hero.end(),cmp);

      for(auto it : hero)
        cout << it.ff << " " << it.ss << endl;
      cout << endl;
      int last = 0;
      while(monstcnt>last)
      {
        int x = hero[0].ff,y = hero[0].ss;
        int mx = 0;
        pi best = hero[0];
        for(int i = last;i<monstcnt;i++)
        {
          if(mpow[last]<= hero[indx] && best.ss<= hero[indx])
            best = hero[indx];
        }
      }


      hero.clear();
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
