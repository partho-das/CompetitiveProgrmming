/// haclerrank (https://www.hackerrank.com/challenges/cpp-sets/problem)
#include<bits/stdc++.h>
using namespace std;
int main () {

    int value,queary;
    int n;
    set<int>se;
    cin>>queary;
    while(queary--)
    {
        cin>>n>>value;
        set<int> ::iterator ite;
        if(n == 1) se.insert(value);
        else if(n == 2)
            se.erase(value);
        else if(n == 3)
        {
            set<int> ::iterator it = se.find(value);
            if(it==se.end())
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
    }
    return 0;
}
