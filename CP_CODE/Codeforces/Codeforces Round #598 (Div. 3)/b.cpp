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
          int n , arr[200],pos[200];
            int mnv = 0;
            cin >> n;
           for(int i  = 0;i<n;i++)
           {
              scanf("%d",&arr[i]);
              pos[arr[i]] = i;
           }
          int cnt = n-1,now = 1,last = 0,work = 1;

          while(cnt && last!=n-1)
          {
           // cout << cnt << endl;
            mnv = n+1;
            int to = pos[now];
           // cout<< to << endl;
            for(int i = to ;i>= last+1 && cnt;i--)
            {
              //cout << arr[i] <<" " << arr[i-1]<<" " << i  << endl;
              if(arr[i]<arr[i-1]) swap(arr[i],arr[i-1]),cnt--;
            }
            for(int i = to + 1 ; i<n && cnt;i++)
            {
                mnv = min(arr[i],mnv);
            }
            now = mnv;
            //cout << now <<" to = " <<  pos[now] << endl;
            last = to;
          }

          for(int i = 0;i<n;i++) printf("%d ",arr[i]);
          puts("");
       }
  

   #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
   #endif
    return 0;
}
