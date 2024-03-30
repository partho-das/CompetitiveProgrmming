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
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)



int search(int *arr,int n,int value)
{
    int high = n-1, low = 0,mid = high+low >> 1;
    int indx = 0;
    while(high >= low)
    {
        if(arr[mid] < value)
        {
            low = mid+1; 
            indx = mid;
        } 
        else
        {
            high = mid-1;
        } 
        mid = high+low >> 1;
    }
    return indx;
}
int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        
        int test,arr[2020];
        scanf("%d",&test);
        TEST(test)
        {
            int n;
            scanf("%d",&n);
            FOR(i,n) scanf("%d",&arr[i]);
            sort(arr,arr+n);
            long long sum = 0;
            FOR(i,n)
            {
                for(int j = i+1;j<n;j++)
                {
                    long long value = arr[i]+arr[j];
                    int indx = search(arr,n,value);
                    if(indx)
                    sum +=  (indx - j) ;
                }
            }
           printf("Case %d: %lld\n",c,sum);
        }

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}