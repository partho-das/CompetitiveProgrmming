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
        
        int n;
        cin >> n;
        int value,sum = 0,mainsum = 0;
        cin >> value;
        mainsum+=value;
        cin >> value;
         mainsum+=value;
          cin >> value;
         mainsum+=value;
          cin >> value;
         mainsum+=value;
         int cnt = 0;
        for(int i = 1;i<n;i++)
        {
            sum = 0;
            for(int j = 0;j<4;j++)
            {
                cin >> value;
                sum +=value;
            }
            if(sum > mainsum)
                cnt++;
        }

        cout << cnt+1 << endl;
       


    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
