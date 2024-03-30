#include <bits/stdc++.h>
using namespace std;
 
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
            int a,b,c,d,x,y,k;


            cin >> a >> b >> c >> d >> k;

            x = (a+(c-1))/c;
            y = (b+(d-1))/d;

            if((x+y)>k)
                printf("-1\n");
            else printf("%d %d\n",x,y);
        }

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
