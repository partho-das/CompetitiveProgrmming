#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool taken[10];
bool ck(int n)
{
    memset(taken,0,sizeof taken);
    while(n)
    {
        int value = n%10;
        n/=10;
        if(!taken[value]) taken[value] = 1;
        else return 0;
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
        
        int l,r;

        cin >> l >> r;

        for(int i = l;i<=r;i++)
        {
            if(ck(i)) {
                cout << i << endl;
                return 0;
            }
        }
       
        cout << -1 << endl;

    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
