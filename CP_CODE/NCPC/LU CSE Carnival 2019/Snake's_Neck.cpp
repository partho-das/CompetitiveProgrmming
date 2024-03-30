#include <bits/stdc++.h>
using namespace std;
 
 int arr[10112][10115];
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

      
     memset(arr,-1,sizeof arr);
    long long n;
    cin >> n;
    long long u,v;
    for(long long i = 0;i<n;i++)
    {
        

        scanf("%d%d",&u,&v);
        arr[u][v]   = i+1;
    }
    long long m;
    cin >> m;
    long long cnt = 0,mx = 0;
    long long lx,ly;
    for(long long i = 0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        if(arr[u][v] != -1)
        {
           // cout << u << " " << v << endl;
            if(cnt==0)
            {
                lx = u;
                ly = v;
                cnt++;
                mx = max(cnt,mx);
            }
            else
            {
                //cout << lx <<" " << ly << " "<<  u << " " << v << arr[u][v] - arr[lx][ly] << endl;
                if( abs(arr[u][v] - arr[lx][ly] ) == 1 )
                {
                    cnt++;
                     mx = max(cnt,mx);
                }
                else
                {
                    mx = max(cnt,mx);
                    cnt = 1;
                }
                lx = u;
                ly = v;
            }
        }
        else
        {
            mx = max(cnt,mx);
            cnt = 0;
            lx = u;
            ly = v;
        }
    }

        mx = max(cnt,mx);
        cout << mx << endl;


    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
        
    return 0;
}