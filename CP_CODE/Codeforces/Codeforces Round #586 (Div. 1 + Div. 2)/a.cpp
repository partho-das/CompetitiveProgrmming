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
        string str;
        cin >> str;
        int z = 0,e= 0,r = 0,o = 0,n = 0;
        for(int i = 0;i<t;i++)
        {
            if(str[i] == 'z')
                z++;
            if(str[i] == 'r')
                r++;
            if(str[i] == 'o')
                o++;
            if(str[i] == 'n')
                n++;
            if(str[i]== 'e')
                e++;
        }

    int mn =  1000000;
    mn = min(o,n);
    mn = min(mn,e);
    o-=mn;
    e-=mn;
    int zero = min(z,e);
        zero = min(r,zero);
        zero = min(o,zero);
    
        for(int i = 0;i<mn;i++)
            cout << 1 <<" ";
        for(int i = 0;i<zero;i++)
            cout << 0 << " ";
        cout << endl;

       
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
