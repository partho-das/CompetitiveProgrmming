#include <bits/stdc++.h>
using namespace std;
 
#define PI 2*acos(0.0)
#define ll long long
#define pf printf
#define sc scanf
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vi std::vector<int>
#define vll vector<long long>
#define pi  pair<int , int>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)


inline bool check(int n,int m,int k,int *arr)
{
    int cnt = 1,sum = 0;

    for(int i = 0;i<n;i++)
    {
        if(sum+arr[i] <= k) sum+= arr[i];
        else{
            sum = arr[i];
            if(sum>k) return 0;
            cnt++;
            if(cnt>m) return 0;
        }
    }
    
    return cnt <= m;
}

int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        int test;
        scanf("%d",&test);
        int cnt = 0;
        TEST(test)
        {

            int n,m,arr[1020];

            scanf("%d%d",&n,&m);
           int sum = 0,mx = 0;
            for(int i = 0;i<n;i++)
            {
                scanf("%d",&arr[i]);
                sum += arr[i];
                mx = max(mx,arr[i]);
            }

            int high = sum,low = mx,mid;
            while(high>=low)
            {
                mid = high+low >> 1;

                //cout << "high = "<< high << "low = "<< low << "mid = " << mid  << endl;
                if(check(n,m,mid,arr))
                high = mid-1;
                else low = mid+1;
            }

            printf("Case %d: %d\n",c,high+1);
           // cout << sum << endl;
      
        }


    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}