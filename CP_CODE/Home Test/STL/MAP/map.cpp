/// hackerrank : https://www.hackerrank.com/challenges/cpp-maps/problem
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int queary;
    cin>>queary;
    map<string,int> me;

    while(queary--)
    {
        int n,value;
        string name;
        cin>>n>>name;

        if(n == 1)
        {
            cin>>value;
           if(me.find(name)!=me.end())
           {
               me[name] = me[name] +value;
           }
           else
           {
               me.insert(make_pair(name,value));
           }
        }
        else if(n == 2)
        {
            me[name] = 0;
        }
        else if(n == 3)
        {
            cout<<me[name]<<endl;
        }

    }



    return 0;
}
