#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
    int len;
    char str[1000];

    scanf("%d%s",&len,str);


    for(int pos = len-1;pos - (len/2)>=0;pos--)
    {
        for(int ln = len/2;ln>=1;len--)
        {
            int first = pos,second = pos-len;
            int ck = 0;
            for(int i = ln - 1;i>=0;i--)
            {
                if(str[first-i]!= str[second-i])
                    {
                        ck = 1;
                        break;
                    }
            }
            if(!ck)
            {
                
            }
        }

    }
  

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
