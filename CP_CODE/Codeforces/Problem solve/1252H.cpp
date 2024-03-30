#include <bits/stdc++.h>
using namespace std;
 

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define vi std::vector<int>
#define vll vector<long long>
#define pll pair<long long,long long>

 
long long area(pll &a, pll &b){
    return min(a.first,b.first) * min(b.second,a.second);
}
 
bool cmp(pll &a, pll &b)
{
    return a.ss<b.ss;
}
int main(){
 
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
    int n;
 
  
    scanf("%d",&n);
    vector<pll> v(n);
    long long a,b;
    pll result(0,0);
    for(int i = 0; i<n; i++){
        scanf("%lld%lld",&a,&b);
        if(a < b) swap(a,b);
        v[i] = {a,b};
        if(result.first*result.second < a*b)
            result = {a,b};
    }
    long long A = result.first*result.second;
    if(n==1){
        printf("%lld.%d\n",A/2,(A&1) ? 5 : 0);
        return 0;
    }
    sort(v.begin(), v.end(), greater<pll>());

    // for(auto p : v) pf("%lld %lld\n", p.ff, p.ss);
 
    pll mx1(v[0]), mx2 = v[1];
    A = max(A, 2*area(mx1,mx2));
    for(int i = 2;i<n;i++){
        if(cmp(mx1,v[i])) swap(mx1,v[i]);
        if(cmp(mx2,v[i])) swap(mx2,v[i]);
        A = max(A, 2*area(mx1,mx2));
    }
 
    // printf("%lld %lld\n",mx1.first,mx1.second);
    // printf("%lld %lld\n",mx2.first,mx2.second);
 
    printf("%lld.%d\n",A/2,(A&1) ? 5 : 0);
 
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}