#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 7020;

long long a[maxn],skill[maxn];

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
     
     int n;
     cin >> n;
     int maxa = 0;
       for(int i = 0;i<n;i++)
       {
            cin >> arr[i];
            maxa = max(a[i],maxa);
       }
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
