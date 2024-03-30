#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       string str; cin >> str;
      puts((str.find("0000000")!=-1)||(str.find("1111111")!=-1)  ? "YES" : "NO");
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
