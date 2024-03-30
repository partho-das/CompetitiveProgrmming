#include <bits/stdc++.h>
using namespace std;


#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)



int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif
    

    int test;

    cin >> test;

    while(test--)
    {
      std::vector<int> pos;
      int n;
      cin >> n;
        string str1,str2;
        cin >> str1 >> str2;

        int cnt = 0;

        for(int i = 0;i<n;i++)
        {
            if(str1[i] != str2[i])
            {
              cnt++;
              pos.push_back(i);
            }
        }
        int ck = 1;
        if(cnt == 2)
        {
            int i = pos[0],j = pos[1];

            swap(str1[i],str2[j]);
            if(str2==str1)
            {
                ck  = 0;
            }
            else
            {
              swap(str1[i],str2[j]);
              swap(str1[j],str2[i]);
                if(str2==str1)
                {
                    ck  = 0;
                }
                else ck = 1;
            }
           

           
        }
        else
        {
          ck = 1;
        }

        if(cnt == 0)
          ck = 0;

        if(!ck)
        {
          puts("YES");
        }
        else puts("NO");

    }

   #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
   #endif
    return 0;
}
