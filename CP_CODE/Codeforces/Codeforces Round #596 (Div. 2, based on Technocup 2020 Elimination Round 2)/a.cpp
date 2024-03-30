#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif  

        int a,b;

        cin >> a >> b;

        if( abs(b-a) <= 1)
        {
            if(a==b)
            {
                cout << a << "1 " << b << "2" << endl;
            }
            else if(a<b)
            {
                 cout << a << "9 " << b << "0" << endl;
            }
            else
            {
                
                cout << -1 << endl;

            }
        }
        else
        {
             if(a==9 && b==1)
                    cout << 99 << " "<< 100 << endl;
                 else
            cout << -1 << endl;
        }

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
