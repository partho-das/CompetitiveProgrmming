#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
  
        int a,b,c;

        int test;

        cin >> test;

        while(test--)
        {
            cin >> a >> b >> c;

            int cpyb = b;
            int team1 = (a+b)/3;
            team1  = min(min(team1,b/2),a);

            b = b - team1*2;
            int team2 = ((b+c)/3);
            team2  = min(min(team2,c/2),b);
            int x =  (team2+team1)*3;



            b = cpyb;
/*           cout << team1 << endl;*/
            //cout << b  << endl;
            team2 = ((b+c)/3);
            team2  = min(min(team2,c/2),b);

             b = b - team2;

            team1 = (a+b)/3;
            team1  = min(min(team1,b/2),a);



          int y = (team2+team1)*3;
            cout << max(x,y) << endl;
        }
  

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
