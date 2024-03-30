#include<bits/stdc++.h>
using namespace std;

#define ll long long




int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        
        int t;
        cin >> t;
        while(t--)
        {
            int x ;
            cin >> x;
            int cnt = 0;
            cnt = (x/6);
            if(x%6) cnt ++;
            cout << cnt << endl;
        } 
       
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
