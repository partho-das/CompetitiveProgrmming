#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6+7;


int arr[maxn];
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
    
    string str;
    
    int n,C = 0;
    while(cin >> str >> n)
    {
        memset(arr,0,sizeof arr);
        int len = (int)str.size();
        int cnt = 0,ck = 0;
        for(int i = 0;i<len;i++)
        {
            if(str[i] == '0')
            {
                ck = 0;
                arr[i] = cnt;
            }
            else if(str[i] == '1')
            {
                if(ck == 0)
                    cnt++;
                arr[i] = cnt;
                ck = 1;
            }
        }
       

        // for(int i = 0;i<len;i++)
        //     cout << arr[i];
        // cout << endl;

        printf("Case %d:\n",++C);
        for(int l = 0; l < n; ++l)
        {
            int i,j;
            cin >> i >> j;
            if(i>j)
                swap(i,j);

            if(str[i] == '0' && str[j] == '1')
                cout << "No" << endl;
            else if(str[i] == '1' && str[j] == '0')
                 cout << "No" << endl;
            else
            {
                if(arr[i]==arr[j])
                    cout<<"Yes" << endl;
                else cout << "No" << endl;
            }
        }

           

    }
   
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
