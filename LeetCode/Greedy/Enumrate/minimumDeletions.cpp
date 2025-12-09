#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumDeletions(string word, int k) {
    unordered_map<char, int> mp;
    for (char c : word) {
        mp[c]++;
    }
    
    vector<int> nums;
    for (auto [_, c] : mp) {
        nums.push_back(c);
    }
    ranges::sort(nums);

    int ans = INT_MAX, n = nums.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + nums[i];
    }

    int maxx = *max_element(nums.begin(), nums.end());

    for (int r = k; r - k <= maxx; r++) {
        int l = r - k;
        int pos1 = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
        int pos2 = lower_bound(nums.begin(), nums.end(), r + 1) - nums.begin();
        int res = pre[pos1] + pre[n] - pre[pos2] - (n - pos2) * r;
        ans = min(ans, res);
    }

    return ans;
}

int minimumDeletions(string word, int k) {
    // 对 26 字母, 直接 cnt 计数
    const int SIGMA = 26;
    int cnt[SIGMA]{};
    for (char c : word) {
        cnt[c - 'a']++;
    }
    ranges::sort(cnt);

    int max_save = 0, s = 0, right = 0;
    for (int base : cnt) {
        // 窗口的右端点 base + k 具有单调性, 可以滑动窗口
        // 维护在 [base, base + k] 中的数据
        while (right < SIGMA && cnt[right] <= base + k) {
            s += cnt[right];
            right++;
        }

        max_save = max(max_save, s + (SIGMA - right) * (base + k));
        s -= base;
    }

    return word.size() - max_save;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
