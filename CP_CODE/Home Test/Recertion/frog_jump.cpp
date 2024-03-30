
#include<bits/stdc++.h>
using namespace std;


int frog(int now,int n)
{
    //cout << now << endl;
    if(now==n)
    {
        printf("%df\n", now);
        return 1;
    }
    else if(n<now)
        return 0;

    int x;
    printf("2\n"),x = frog(now+2,n);
    int y;
    printf("3\n"),y = frog(now+3,n);

    return x+y;
}


 int bigintdiv(string n,int d)
 {
    std::vector<int> result;
    int now = 0;

    for(int i = 0;i<n.size();i++)
    {
        now = now*10+(n[i]-'0');
        if(now==0)
            result.push_back(0);
      
            result.push_back((now/d));
            now = now%d;
    }
    
    int ck = 0;
    for(int i = 0;i<result.size();i++)
    {
        if(ck==0 && result[i] ==0)
            continue;
        else ck = 1;
        cout << result[i];
    }

    cout << endl;


 }


int main()
{
#ifdef PARTHO
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int start_time = clock();
#endif

    string str = "64";
    int n = 2;
    for(int i = 0;i<n;i++)
    bigintdiv(str,n);

#ifdef PARTHO
    int end_time = clock();
    printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif


}
