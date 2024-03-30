#include<bits/stdc++.h>
using namespace std;

#define ll long long


 int arr[500020];
char str[500020];
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

     

        
        gets(str);
       if(!strlen(str))
       {
        cout << "Mike" << endl;
        return 0; 
       }

       int mn = 26,ln = strlen(str);
       for(int i  = 0;i<ln;i++)
       {
        mn = min(str[i]-'a',mn);
        arr[i] = mn;
       }


        for (int i = 0; i < ln; ++i)
        {

           if( (str[i]-'a') >arr[i])
            cout << "Ann" <<endl;
            else cout << "Mike" << endl;
        }

      

        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
