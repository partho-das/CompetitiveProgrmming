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


bool cmp(int &a,int &b)
{
    return a>b;
}

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
        cin >> n;
        int arr[1020];

        FOR(i,n) scanf("%d",&arr[i]);

        sort(arr,arr+n,cmp);

        int cnt = 0;
        int last = arr[0],mn = arr[0],mx = 0;
        for(int i = 0;i<n;i++)
        {
            cnt++;
            mn =  min(cnt,arr[i]);
             
            mx = max(mx,mn);
        }
        cout << mx << endl;

    }

   #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
   #endif
    return 0;
}
