#include <bits/stdc++.h>
using namespace std;
 
bool visit[100020];
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

   queue<int> enter;
    int n;
    cin >> n;
    int value;
    for( int i= 0;i<n;i++)
    {
        cin >> value;
        enter.push(value);
    }

    int fine = 0;
    for(int i = 0;!enter.empty();i++)
      {
        cin >> value;
        int top = enter.front();
        while(visit[top])
        {
            enter.pop();
            top = enter.front();
        }

        if(value==top)
        {
            visit[value] = 1;
            enter.pop();
        }
        else
        {
            if(!visit[value])
                fine++;

            visit[value] = 1;
            
        }
        

      }
      cout << fine << endl;
  

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
