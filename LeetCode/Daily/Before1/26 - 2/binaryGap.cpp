#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int binaryGap(int n) {
    int pre = INT_MAX / 2, ans = 0;

    for (int i = 0; i < 32; i++) {
        if (n >> i & 1) {
            ans = max(ans, i - pre);
            pre = i;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}