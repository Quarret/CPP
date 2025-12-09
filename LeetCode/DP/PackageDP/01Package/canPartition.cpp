#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canPartition(vector<int>& nums) {
    int s = reduce(nums.begin(), nums.end()), n = nums.size();
    if (s % 2) return false;
    
    vector f(n + 1, vector<int>(s / 2 + 1, -1));
    auto dfs = [&](this auto&& dfs, int i, int c) -> bool {
        if (i < 0) return c == 0;

        int &res = f[i][c];
        if (res != -1) return res;
        res = (c >= nums[i] && dfs(i - 1, c - nums[i])) || dfs(i - 1, c);
        return res;
    };

    return dfs(n - 1, s);
}

bool canPartition(vector<int>& nums) {
    int s = reduce(nums.begin(), nums.end()), n = nums.size();
    if (s % 2) return false;
    s /= 2;

    vector f(n + 1, vector<int>(s + 1, 0));
    f[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c <= s; c++) {
            f[i + 1][c] = (c >= nums[i] && f[i][c - nums[i]]) || f[i][c];
        }
    }

    return f[n][s];
}

bool canPartition(vector<int>& nums) {
    int s = reduce(nums.begin(), nums.end()), n = nums.size();
    if (s % 2) return false;
    s /= 2;

    vector<int> f(s + 1);
    f[0] = 1;
    for (int x : nums) {
        for (int c = s; c >= 0; c--) {
            f[c] |= c >= x ? f[c - x] : 0;
        }
    }
    return f[s];
}


bool canPartition(vector<int>& nums) {
    int s = reduce(nums.begin(), nums.end()), n = nums.size();
    if (s % 2) return false;
    s /= 2;

    bitset<10001> f;
    f[0] = 1;
    for (int x : nums) {
        f |= f << x;
    }

    return f[s];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
