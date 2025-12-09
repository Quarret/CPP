#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long splitArray(vector<int>& nums) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    int pos1 = -1, pos2 = -1;

    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!flag) {
            if (nums[i] >= nums[i + 1]) {
                flag = 1;

                pos1 = i;
                pos2 = i + 1;
            }
        } else {
            if (nums[i] <= nums[i + 1]) return -1;
        }
        pre[i + 1] = pre[i] + 1LL * nums[i];
    }
    pre[n] = pre[n - 1] + 1LL * nums[n - 1];

    if (pos1 == -1 && pos2 == -1) return abs(1LL * nums.back() - pre[n - 1]);
    return min(abs(2LL * pre[pos1] - pre[n]), abs(2LL * pre[pos2] - pre[n]));
}

int solve() {
    vector memo(21, vector(21, vector<double>(13, -1)));

    auto dfs = [&](this auto&& dfs, int i, int j, int k) -> double {
        if (i <= 0 && j <= 0 && k <= 0) return 0;

        double &res = memo[i][j][k];
        if (res != -1) return res;
        res = min(dfs(i - 10, j - 5, k - 2) + 0.6, dfs(i - 4, j - 5, k - 4) + 1);

        return res;
    };

    return dfs(20, 20, 12);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
