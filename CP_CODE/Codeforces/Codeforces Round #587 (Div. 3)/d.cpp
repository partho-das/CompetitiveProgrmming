#include<bits/stdc++.h>
using namespace std;

#define ll long long


long long mx = 0,arr[200100], gon[200100];

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

   long long n;

   cin >> n;
   long long sum = 0;
   for(int i = 0 ; i< n;i++)
   {
        cin >> arr[i];
        mx = max(arr[i],mx);
        sum+=arr[i];
   }

   for(long long i = 0;i<n;i++)
   {
    gon[i] = mx-arr[i];
   }
   long long have = n*mx - sum;
   long long lim = sqrt(have);
   std::vector<long long> div;
   for(long long i = 1;i<=lim;i++ )
   {
        if(have%i == 0)
        {

            div.push_back(i);
            div.push_back(have/i);
        }
       
   }


   sort(div.begin(), div.end());
   long long ck = 0,indx = 0;
   for(long long i = div.size()-1;i>=0;i--)
   {
        ck = 0;
        for(long long j = 0;j<n;j++)
        {
           
            if(gon[j]%div[i]!=0)
                {
                    ck = 1;
                    break;
                }
        }


        if(!ck)
        {
            indx = div[i];
            break;
        }
   }

   cout << have/indx << " " << indx <<endl;

       
    
  #ifdef PARTHO
        long long end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
