#include <bits/stdc++.h>
using namespace std;

int comb[10000000];
int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);

    comb[0] = 1;
    for(int s = 1; s < 1e6; s++){
        comb[s] = 0;
        for(int i = 1; s-i >= 0 && i <= 3; i++) comb[s] += comb[s-i];
    }
    cout << comb[3600] << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int done[1000000], saved[1000000];
int BT(int s){
    if(s < 0) return 0;
    if(s == 0) return 1;
    if(done[s]) return saved[s];

    done[s] = 1;
    int comb = 0;
    for(int i = 1; i <= 3; i++) comb += BT(s-i);
    return saved[s] = comb;
}

int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    
    cout << BT(3600) << endl;

    return 0;
}