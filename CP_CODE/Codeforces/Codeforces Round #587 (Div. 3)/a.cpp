#include<bits/stdc++.h>
using namespace std;

#define ll long long




int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    int n;

    cin >> n;
    string str;
    cin >> str;
    int a = 0,b = 0;
   int cnt = 0;
    for(int i = 0 ; i < str.size();i++)
    {
        if(i&1)
        {
            if(str[i]=='a')
                a++;
            else b++;
            if(abs(a-b))
            {
                if(a==2)
                    str[i] = 'b';
                else str[i] = 'a';
                cnt++;
            }
        }
        else
        {
            a = 0;b  = 0;
            if(str[i]=='a')
                a++;
            else b++;
        }

    }


    cout << cnt << endl;
    cout << str<<endl;

   
       
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
