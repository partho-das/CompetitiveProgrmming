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

    int q;
    cin >> q;

    while(q--)
    {
       int n,sum = 0;

       int value;
       cin >>n;
       for(int i = 0; i < n;++i)
       {
            cin >> value;
        if(value<=2048)
            sum+=value;
       }
      
        cout << (sum >= 2048 ? "YES" : "NO") << endl;
       
      
    }
       
       
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
