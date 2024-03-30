#include<bits/stdc++.h>



using namespace std;

vector<long long>divisors[1000010];

void divSieve(long long n)
{
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i;j<=n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    for(long long i=1;i<=n;i++)
    {
        printf("%d : ",i);
        for(auto it : divisors[i])
        {
            printf("%d ",it);
        }
        puts("");
    }
    return;
}





int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        divSieve(10000);


    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif


    return 0;
}