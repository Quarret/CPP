#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* recoverFromPreorder(string traversal) {
    int cnt = 0, num = 0, n = traversal.size();
    vector<pair<int, int>> nums;

    for (int i = 0; i < n; i++) {
        if (traversal[i] == '-') {
            cnt++;
        } else {
            num = num * 10 + (traversal[i] - '0');
            if (i + 1 == n || traversal[i + 1] == '-') {
                nums.emplace_back(cnt, num);
                cnt = 0;
                num = 0;
            }
        }
    }
    int m = nums.size();

    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(nums[l].second);

        int mid = l + 1, pre = nums[l].first, ok = 0;
        while (mid <= r && (nums[mid].first > pre + 1 || (nums[mid].first == pre + 1 && !ok))) {
            ok = 1;
            mid++;
        }

        return new TreeNode(nums[l].second, dfs(l + 1, mid - 1), dfs(mid, r));
    };

    return dfs(0, m - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
