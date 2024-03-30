#include<bits/stdc++.h>
using namespace std;

#define ll long long

inline bool ispalindrom(const string &str)
{
    for(int i = 0 ,j = str.size()-1;i<j;i++,j--)
    {
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}



int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
     
       
       string str;
       cin >> str;
       if(ispalindrom(str)) cout  << str;
       else
       {
        str.push_back(str[0]);
        //cout << str << endl;
        if(ispalindrom(str))
        {   
             cout  << str;
             return 0;
        }
        else str.pop_back();
        cout<<str;
        for(int i = str.size()-2;i >= 0;i--)
            cout<<str[i];
       }
       cout << endl;
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
