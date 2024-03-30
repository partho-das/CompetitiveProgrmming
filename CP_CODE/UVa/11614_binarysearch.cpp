#include <bits/stdc++.h>
using namespace std;
 

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
#define FOR(i,n) for(int i = 0;i<n;i++)

 
int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    long long n,test;
    cin >> test;

    while(test-- && scanf("%lld",&n))
    {
       // cout << n << endl;
        ll high = 1e10,low = 0,mid = (high+low)/2,value;
        long long ans = 0;
        while(high>=low)
        {
             value = (mid*(mid+1)) /2;
             //cout << value << " " << mid << endl;
            if(value <= n)
            {
               low = mid+1;
               ans = mid;
            }
            else high = mid - 1;
            mid = (high+low)/2;
        }
        printf("%lld\n",ans);
       
    }

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}