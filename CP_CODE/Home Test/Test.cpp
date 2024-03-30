#include<bits/stdc++.h>
using namespace std;

int main()
{
    int siz;        cin >> siz;
    int arr[siz];   for(auto &e : arr) cin >> e;

    for(int curr_pos = 0;  curr_pos < siz; curr_pos++){
        for(int nxt = 0; nxt < siz; nxt++){
            if(arr[nxt] < arr[curr_pos]) swap(arr[nxt],arr[curr_pos]);
        }
        for(auto e : arr) cout << e << " "; cout << endl;
    }

    return 0;
}
