#include<bits/stdc++.h>
using namespace std;

#define ll long long

int calculate(int full, int blank)
{
    int all = full + blank;
    if(all/3)
     return full + calculate(all/3,all%3);
    return full;  
}
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        
        int n;
        while(cin >> n)
             cout <<  calculate(n+1,0) - 1 << endl ;
         
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
