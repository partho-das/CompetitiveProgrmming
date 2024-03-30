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


ll mcnt = 0;
inline bool check(ll n,ll m,ll k,ll *arr)
{
     ll cnt = 1;
      ll sum = 0;

    for(ll i = 0;i<n;i++)
    {
        if(sum+arr[i] <= k) sum+= arr[i];
        else{
            sum = arr[i];
            if(sum>k) return 0;
            cnt++;
            if(cnt>m) return 0;
        }
    }
    if(cnt <= m)
    {
        mcnt = cnt;
    }
    return cnt <= m;
}
std::vector<ll> v;
inline void print(ll n,ll m,ll k,ll *arr)
{
    v.clear();
    arr[n] = 1e9+7;
    ll cnt = m - mcnt;
   // cout << cnt << endl;
    ll sum = 0;
    for(ll i = n-1;i>=0;i--)
    {
        if(sum+arr[i]<=k)
        {
            v.pb(arr[i]);
            sum+=arr[i];
        }
        else
        {
            v.pb(-1);
            sum = arr[i];
            v.pb(arr[i]);
        }
    }
    //FOR(i,v.size()) cout << v[i] << endl; 
    reverse(v.begin() , v.end());
    v.push_back(1e9+7);
    for(ll i = 0;i<v.size()-1;i++)
    {
        if(v[i] == -1)
           printf(" / ");
        else
        {
             cout << v[i];
            if(v[i+1]!= -1 && cnt)
            {
                printf(" /");
                 cnt--;
            }
            if(v[i+1]!=-1 && i<v.size()-2)
            cout << " ";
        }

    }
    cout << endl;

    return ;
}

int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        ll start_time = clock();
    #endif

        ll test;
        scanf("%d",&test);
        ll cnt = 0;

        TEST(test)
        {
            ll lsum = 0;

            ll n,m,arr[1020];

            scanf("%lld%lld",&n,&m);

           ll sum = 0,mx = 0;
            for(ll i = 0;i<n;i++)
            {
                scanf("%lld",&arr[i]);
                sum += arr[i];
                mx = max(mx,arr[i]);
                lsum+=arr[i];
            }
           // cout << lsum <<" " << sum << endl;
            ll high = sum,low = mx,mid;
            while(high>=low)
            {
                mid = high+low >> 1;

                //cout << "high = "<< high << "low = "<< low << "mid = " << mid  << endl;
                if(check(n,m,mid,arr))
                high = mid-1;
                else low = mid+1;
            }
           print(n,m,high+1,arr);
           // cout << sum << endl;
          // printf("%lld\n",high+1);
      
        }


    #ifdef PARTHO
        ll end_time = clock();
     // printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}