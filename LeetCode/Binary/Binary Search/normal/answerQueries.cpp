/*** 
 * @Author: Quarret
 * @Date: 2025-04-16 10:15:50
 * @LastEditTime: 2025-06-05 23:21:25
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;


/*
严谨的说明：
pre为nums不减排列的前缀和
对于每个queries[i],我们要找它在pre中最后大于等于的值
为什么？
若最长子序列出现在前，它的长度肯定没有最后出现的位置长
若最长子序列出现在后，它的值一定超过queries[i]
*/

int check(vector<int>& pre, int k) {
    int l = 0, r = pre.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (pre[mid] < k) l = mid + 1;
        else r = mid - 1; 
    }

    return l;
}
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());

        vector<int> pre(n, 0), ans(m, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        for (int i = 0; i < m; i++) {
            ans[i] = check(pre, queries[i] + 1);
        }

        return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
