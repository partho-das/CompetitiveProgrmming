#include<bits/stdc++.h>
using namespace std;

#define ll long long


map<int,int> mp;
std::map<int,int>::iterator it;

deque<int> messenger;
int main()
{      srand(time(NULL));   
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        int n = 1e7,r;
        cout << 100 << endl;
        for(int j = 0;j<100;j++)
        {
           cout << 100 << endl;
      for(int i = 1;i<=100;i++)
      {
         // Initialization, should only be called once.
           r = rand() % (2441139+100) + 2441139; 
          cout << r << endl;
      }
      cout << endl;

        }
       

     

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
