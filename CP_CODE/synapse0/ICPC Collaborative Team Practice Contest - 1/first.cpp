#include <bits/stdc++.h>
using namespace std;
 bool arr[1000020];
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
   int len;
   string str;

   cin >> len;
   int x = 0;
   char ch = 11,inp;
   getchar();
   for(int i = 0;i<len;i++)
   {
       inp =  getchar();
       if(inp!=ch)
       {
            str.push_back(inp);
            ch = inp;
            x++;
       }
   }
   int t = 1;
//cout <<str << endl;
 // for(int l = 0;l<2;l++)
 //    cout << str[110+l];
 //    cout << " " ;


while(t--)
{
   int first ,second;
   int xck = 1;
   for(int i = x;i>=1;)
   {
        xck = 0;
        for(int j = 0;j<x-i;j++)
        {
            first = j;
            second = j+i;
            int ck = 1;

            for(int k = 0;k<i;k++)
            {
                //cout <<str[first+k] << " " << str[second+k] << " first = " << first<< "second = " << second << " K " << k  << endl;
                if(str[first+k] != str[second+k])
                    {
                        ck = 0;
                    }

                   // cout <<str[first+k] << " " << str[second+k] << endl;
            }
            //cout << endl;
            if(ck)
            {
                cout << first << " i " << i  << endl;
                // for(int l = 0;l<i;l++)
                //     cout << str[first+l];
                //     cout << " " ;

                    // for(int l = 0;l<i;l++)
                    // cout << str[second+l];
                    // cout << " ";
                    // cout << endl;

                str.erase(second,i);
                xck = 1;
            }
            x = str.size();
        }
        if(!xck)
            i--;



        //cout << str << " " << i << endl;

   }

  
}
   cout << str.size() << endl;

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
