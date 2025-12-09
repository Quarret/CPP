#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
分析出迭代过程中的不变量，来构建hash!!!
由题意可知：
(j - i) / 2 = pre[j] - pre[i]
2 * pre[j] - pre[j] = 2 * pre[i] - i;
所以将2 * pre[i] - i作为迭代过程中的不变量，作为hash表的键，i作为hash的值
*/
int findMaxLength(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    unordered_map<int, int> mp;
    mp[0] = 0;

    int idx1 = 0, idx2 = 0, idx3 = 0;
    for (int j = 1; j <=n; j++) {
        int cur = 2 * pre[j] - j;
        if (mp.contains(cur)) ans = max(ans, j - mp[cur]);
        else {
            mp[cur] = j;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
