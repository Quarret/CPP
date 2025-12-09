#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int numberOfBeams(vector<string>& bank) {
    int m = bank.size(), n = bank[0].size();
    vector<int> nums(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nums[i] += (bank[i][j] == '1');
        }
    }

    int pre = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if (nums[i]) {
            ans += pre * nums[i];
            pre = nums[i];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
