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
        std::map<int, int> fre;
        std::vector<int> stor;
        while(cin >> n)
        {
           fre[n]++;
           stor.push_back(n);
        }

        for(int i = 0;i<stor.size();i++)
        {
            int value = stor[i];
            if(fre[value])
            {   cout << value << " " << fre[value] << endl;
                fre[value] = 0;
            }
        }

     
       
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
