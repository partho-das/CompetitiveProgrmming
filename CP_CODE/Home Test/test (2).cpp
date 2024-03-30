#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("output.txt","w",stdout);
    srand(time(NULL));

    int h1,h2,m1,m2,h,m;
    int n = 100;        cout << n << endl;
    while(n--){
        h1 = rand()%24;
        m1 = rand()%60;
        h = rand()%24;
        m = rand()%60;
        h2 = (h1 + h)%24;
        m2 = (m1 + m)%60;

        cout << h1 << " " << m1 << " " << h2 << " " << m2 << " " << h << " " << m << endl;
    }

    return 0;
}
