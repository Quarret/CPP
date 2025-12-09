#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*
定长滑动窗口
特判一下 n < 2 * k + 1时的情况
*/
vector<int> getAverages(vector<int>& nums, int k) {
    vector<int> ans;
    long long n = nums.size(), num = 0;

    if (n < 2 * k + 1) {
        for (int i = 0; i < n; i++) {
            ans.push_back(-1);
        }
        return ans;
    }

    for (int i = 0; i < k; i++) {
        ans.push_back(-1);
    }

    for (int i = 0; i < n; i++) {
        num += nums[i];

        if (i < 2 * k) continue;

        ans.push_back(num / (2 * k + 1));
        num -= nums[i - (2 * k + 1) + 1];
    }

    for (int i = 0; i < k; i++) {
        ans.push_back(-1);
    }

    return ans;
}
/*
思路相同，优化写法
*/
vector<int> getAverages1(vector<int>& nums, int k) {
    long long n = nums.size(), num = 0;
    vector<int> ans(n, - 1);

    for (int i = 0; i < n; i++) {
        num += nums[i];

        if (i < 2 * k) continue;

        ans[i - k] = num / (2 * k + 1);
        num -= nums[i - (2 * k + 1) + 1];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
