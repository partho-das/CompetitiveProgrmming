#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
        int n,arr[100020];

        cin >> n;

        for(int i = 0;i < n;i++)
            scanf("%d",&arr[i]);

        sort(arr,arr+n);
        long long x = 0,y = 0,ck = 0,j = 0,k = n-1;
        for(int i = 0;i<n;i++)
        {    
            if(ck==0){   
                if(arr[k] == 0)
                    break;
                x+=arr[k];
                arr[k--] = 0;
                ck = 1;
            }
            else 
            {
                y+=arr[j];
                arr[j++] = 0;
                ck = 0; 
            }

            
        }

       // cout << x << y<<  endl;
        
        long long dis = x*x + y*y;
        cout << dis << endl;


    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
