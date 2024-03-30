#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1000010;

int sod[maxn];
vector<int>divisors[1000010];
int divgen()
{
    for(int i = 1;i < maxn ; i++)
    {
        for(int j = i+i; j < maxn; j+=i)
        {
           sod[j]+=i;
        }
    }

}



int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        divgen();


        int a,b;
        sod[1] = 0;
        while(cin >> a >> b)
        {
            if(sod[a]==b & sod[b]==a)
                printf("It is a ambicable number.\n");
            else printf("It is not a ambicable number.\n");
        }
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
