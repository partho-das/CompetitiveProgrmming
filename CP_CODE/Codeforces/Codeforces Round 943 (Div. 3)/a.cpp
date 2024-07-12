#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[9][6];

int find_four(int container8, int container5) {
    if (container8 == 4 || container5 == 4) return 0;
    int &ret = dp[container8][container5];
    if (ret != -1) return ret;
    ret = 100000;

    // Pouring into the container
    ret = min(find_four(min(8, container8 + 8), container5) + 1, ret);
    ret = min(find_four(container8, min(5, container5 + 5)) + 1, ret);

    // Transfer from 8 to 5
    int can_take = min(container5, 8 - container8);
    ret = min(find_four(container8 + can_take, container5 - can_take) + 1, ret);

    // Transfer from 5 to 8
    can_take = min(container8, 5 - container5);
    ret = min(find_four(container8 - can_take, container5 + can_take) + 1, ret);

    // Emptying containers
    ret = min(find_four(0, container5) + 1, ret);
    ret = min(find_four(container8, 0) + 1, ret);

    return ret;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cout << find_four(0, 0) << endl;
}

int main() {
    solve();
    return 0;
}
