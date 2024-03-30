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

        string str;
        int n,k;
        cin >> n >> k;
        cin >> str;

        if(n==1 && k)
        {
            cout << "0"<< endl;
            return 0;
        }
        int cpy = k;
        if(str[0]>'1' && cpy)
        str[0] = '1',cpy--;
        for(int i = 1;i<n && cpy;i++)
            {
                if(str[i]>'0')
                    str[i]='0',cpy--;
            }
        
         cout << str << endl;
       
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
