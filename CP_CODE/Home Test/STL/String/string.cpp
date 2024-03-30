
#include<bits/stdc++.h>
using namespace std;



int main()
{
#ifdef PARTHO
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int start_time = clock();
#endif




    std::queue<int> myints;

  for (int i=0; i<5; i++)
  {
       myints.emplace (i);
     // std::cout << "1. size: " << myints.size() << '\n';

  }





#ifdef PARTHO
    int end_time = clock();
    printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
