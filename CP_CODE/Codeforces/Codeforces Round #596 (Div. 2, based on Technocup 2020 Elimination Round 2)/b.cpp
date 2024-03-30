#include <bits/stdc++.h>
using namespace std;
 
 const int maxn = 1e6+5;
 int arr[maxn];
 int stor[maxn];
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
            int n,k,d,last;

            scanf("%d%d%d",&n,&k,&d);
            int mn = k;
            // memset(arr, 0 ,sizeof (arr)*k );
            int cnt = 0;


            for(int i = 0;i<n;i++)
            {
                scanf("%d",&stor[i]);
                arr[ stor[i]] = 0;
            }
            int now;
            for(int i = 0;i<d;i++)
            {
                now = stor[i];
                if(arr[now] == 0)
                    cnt++;
                arr[now]++;
            }
            mn = min(cnt,mn);
            
            int first;
            for(int i = d;i<n;i++)
            {
                first = stor[i-d];
                now = stor[i];
                arr[first]--;
                if(arr[first] == 0) cnt--;

                if(arr[now] == 0)
                    cnt++;
                arr[now]++;

                mn = min(cnt,mn);;
            }

            cout << mn << endl;
        }


    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
