#include<bits/stdc++.h>
using namespace std;

#define ll long long



 bool board[1000010][1000010];
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

   int x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;


       
   for(int i  = y1;i<=y2;i++)
    board[x1][i] = 1;
    for(int i  = y1;i<=y2;i++)
    board[x2][i] = 1;


    if(ck == 1)
        cout << "YES" << endl;
    else cout << "NO" << endl;


       
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
