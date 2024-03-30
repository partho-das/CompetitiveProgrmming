#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n;


int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    
        
        cin >> n;

        int x;
   
        
        for(int i = 1;i<=n;i++)
        {
            
            if(i&1){
                x = 1;
            }
            else x = 2;
            for(int j = 1;j<=n;j++)
            {

                if(x==1 )
                {
                    cout << "W";
                    x = 2;
                }
               else if(x==2)
                {
                    cout << "B";
                    x = 1;
                }
            }
            puts("");
        }

        


    
        
        

        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
