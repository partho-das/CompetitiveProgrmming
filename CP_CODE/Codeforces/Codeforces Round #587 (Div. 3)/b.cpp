#include<bits/stdc++.h>
using namespace std;

#define ll long long


std::vector<pair<int ,int >> can;

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        int n;

        cin >> n;
        int value;
        for(int i = 0;i<n;i++)
        {
            cin >> value;
            can.push_back({value,i});
        }

        sort(can.begin(), can.end());

        int x = 0,sum = 0;
        for(int i = can.size()-1 ; i >= 0 ; i--,x++)
        {
            sum+=can[i].first*x+1;
        }

        cout << sum << endl;



        for(int i = can.size()-1 ; i >= 0 ; i--,x++)
        {
            cout << can[i].second+1<<" ";
        }
       
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
