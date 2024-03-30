#include<bits/stdc++.h>
using namespace std;

#define ll long long


std::vector< pair< pair<char,char> ,int> > dif;

inline bool cmp(const pair< pair<char,char> ,int> &a,
    const pair< pair<char,char> ,int> &b)
    {
        return a.first.first<b.first.first;
    }

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        int n;
        cin >> n;
        string str,str2;

        cin >> str >> str2;

        for(int i = 0;i<str.size();i++)
        {
            if(str[i]!=str2[i])
            {
                dif.push_back({ {str[i],str2[i]} , i+1});
            }
        }


        sort(dif.begin(), dif.end(),cmp);
        std::vector< pair<int ,int> >indx;
        // for(int i = 0 ; i < dif.size() ;i++)
        // {
        //     cout << dif[i].first.first << " " << dif[i].first.second ;
        //     cout << " " << dif[i].second << endl; 
        // }
        int sum  = 0;
        if(dif.size()&1)
        {
            cout << -1 << endl;
            return 0;
        }
        else{
            for(int i = 0;i<dif.size();i+=2)
            {
                char f = dif[i].first.first,s = dif[i+1].first.first;
                if(f==s)
                {
                    sum++;
                    indx.push_back({dif[i+1].second,dif[i].second});
                }
                else
                    {
                        sum+=2;
                        indx.push_back({dif[i+1].second,dif[i+1].second});
                        indx.push_back({dif[i+1].second,dif[i].second});
                    }
            }
        }
        cout << sum << endl;

      for(auto it : indx)
        cout << it.first << " " << it.second << endl;
       
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
