#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int binaryGap(int n) {
    int ans = 0, idx = 1e9;
    for (int i = 0; i <= 31; i++) {
        if ((n & (1 << i)) == (1 << i)) {
            ans = max(ans, i - idx);
            idx = i;
        }
    }        

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
