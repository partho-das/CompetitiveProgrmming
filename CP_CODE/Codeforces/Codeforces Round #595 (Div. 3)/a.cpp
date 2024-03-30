#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif  
    int arr[102][102];
    int n;
    int stor[102];
    int test;
    cin >> test;
    while(test--)
    {
        memset(arr,0,sizeof arr);
        cin >> n;

        int x = 0,cnt = 0,value,mx = 0;
            
        for(int i = 0;i<n;i++)
            scanf("%d",&stor[i]);

            sort(stor,stor+n);

        for(int i = 0;i<n;i++)
        {
            value = stor[i];
            for(int j = 0;j<n;j++)
            {
                if(arr[j][value-1] == 0 && arr[j][value+1] == 0)
                {
                    //cout << value << " " << j << endl;
                    arr[j][value] = 1;
                    mx = max(j,mx);
                    break;
                }
            }
        }

        cout << mx+1 << endl;

    }


    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
