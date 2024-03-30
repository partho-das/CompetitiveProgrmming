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
#define FOR(i,n) for(int i = 0;i<n;i++)



void gen(int n,int pos)
{
    //cout << pos << endl;
    if(pos>5)
        return;
    int sum;
    for(int i = 0;i<5;i++)
    {
        sum = n+stor[i];
        graph[n].push_back(sum);
        gen(sum,pos+1);
    }

    return;
}


int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif  

        int n,p;
        cin >> n >> p;


        base(n,p);
        // for(auto it : stor)
        //     cout << it << " ";
        gen(0,0);
 



    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
