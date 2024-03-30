#include <bits/stdc++.h>
using namespace std;
 

#define ll long long
#define pf printf
#define sc scanf
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vi std::vector<int>
#define vll vector<long long>
#define pi  pair<int , int>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)

bool cmp(string &a,string &b)
{
    string first,second;
    first = a+b;
    second = b+a;

    if(first>=second)
        return 1;
    else return 0;
}

 
int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        
       int test;
       cin >> test;

       TEST(test)
       {
            int n;
            sc("%d",&n);
            string str;
            std::vector<string> v;
            FOR(i,n)
            {
                cin >> str;
                v.push_back(str);
            }
            sort(v.begin(), v.end(),cmp);
            printf("Case %d: ",c);
            for(auto it : v)
                cout << it;
           cout << endl;
       }

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}