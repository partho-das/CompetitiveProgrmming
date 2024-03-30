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

int arr[100020];


bool cheack(int *arr,int n,int mid)
{

    for(int i = 1;i<=n;i++){
        if(arr[i-1]+mid>=arr[i]){
            if(arr[i-1]+mid>arr[i]) continue;
            else mid--;
        }
        else return 0;
    }
    return 1;
}

int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        int test,n;
        cin >> test;
        TEST(test){
            sc("%d",&n);
            for(int i = 1;i<=n;i++)
                    scanf("%d",&arr[i]);
                arr[0]= 0;
            int high = 1e7+100,low = 0,mid = high+low >> 1,ans;
            while(low <= high){
                int ck = cheack(arr,n,mid);
                if(ck) high = mid-1,ans = mid;
                else low = mid+1;
                mid = high+low >> 1;
           }
           pf("Case %d: %d\n",c,ans);
        }
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}