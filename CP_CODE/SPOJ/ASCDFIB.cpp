#include<bits/stdc++.h>
using namespace std;

const int maxn = 1100001,MOD = 100000;
int fib[maxn];

int fibgen()
{
    fib[1] = 0;
    fib[2] = 1;
    for(int i = 3;i<maxn;i++)
    {
        fib[i] = (fib[i-1] + fib[i-2])%MOD;

    }


    return 0;
}



int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        

        
        //cout << sizeof(int);
        int t;
        //cout << maxn << endl;
        cin >> t ;
        fibgen();
        for(int i = 1;i<=t;i++)
        {
            
            int a,b;

            scanf("%d%d",&a,&b);
            int value = a+b,cnt = 1;
            printf("Case %d:",i);
            
            multiset<int> mlts;
            for(int j = a;j<=value;j++)
            {
                mlts.insert(fib[j]);
                if(mlts.size() >100){
                    auto it = mlts.end();
                    it--;
                    mlts.erase(it);
                }
            }
            for(auto it : mlts) printf(" %d",it);
            puts("");
        }
        
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
