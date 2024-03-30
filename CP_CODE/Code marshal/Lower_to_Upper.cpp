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
        
    string str;
    int t;
    cin >> t;
   getchar();
    for(int c = 1;c<= t;c++)
    {
         
        getline(cin,str);
        for(int i = 0;i<str.size(); ++i)
        {
            if(str[i]>='a' && str[i]<='z')
                str[i] -=32; 
        }

        printf("Case %d: ",c);
        cout << str <<  endl;

    }

   

           
           
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
