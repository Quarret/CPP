/*** 
 * @Author: Quarret
 * @Date: 2025-06-01 09:53:26
 * @LastEditTime: 2025-06-09 09:57:56
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
本质O(n ^ 2)算法
对于每个j,逐个枚举i, 看 pre[j + 1] - pre[i] 是否等于k
*/
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), ans = 0;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            if (pre[j + 1] - pre[i] == k) ans++;
        }
    }

    return ans;
}

/*
为了满足时间复杂度
我们可以在遍历j的过程中，记录s[j] - k == s[i] 的值的个数
利用hash表记录实现O(1)查询
讲时间复杂度优化到O(n)
*/
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), ans = 0;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    unordered_map<int, int> cnt;
    for (int j = 0; j <= n; j++) {
        ans += cnt[pre[j] - k];
        cnt[pre[j]]++;//记录s[i]信息，利用hash表来实现O(1)查询
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
