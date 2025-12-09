#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*
从头尾选不是连续的，构造一个连续的来滑动窗口
滑动窗口需要连续序列
*/
int maxScore(vector<int>& cardPoints, int k) {
    vector<int> nums;
    int n = cardPoints.size();
    for (int i = k - 1; i >= 0; i--) nums.push_back(cardPoints[i]);
    for (int i = n - 1; i >= n - k; i--) nums.push_back(cardPoints[i]);

    long long num = 0, ans = 0, m = nums.size();
    for (int i = 0; i < m; i++) {
        num += nums[i];

        if (i < k - 1) continue;

        ans = max(ans, num);
        num -= nums[i - k + 1];
    }

    return ans;
}

/*
正向思维优化：取模替代创建数组
*/
int maxScore(vector<int>& cardPoints, int k) {
    int ans = 0, n = cardPoints.size();
    int r = n - 1, num = 0;
    for (int i = r; i > r - k; i--) num += cardPoints[i];

    for (int i = 0; i <= k; i++) {
        ans = max(ans, num);

        r++;
        num += cardPoints[r % n] - cardPoints[(r - k) % n];
    }

    return ans;
}

/*
反向思维：
要从头尾不连续选k个数，不就是从数组中部连续选 n - k个数嘛

滑动窗口对于长度为0的串需要特判
*/
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();

    long long num = 0, ans = 1e9, num1 = 0;
    for (int i = 0; i < n; i++) {
        num += cardPoints[i];
        num1 += cardPoints[i];

        if (i < n - k - 1) continue;

        ans = min(ans, num);
        num -= cardPoints[i - (n - k) + 1];
    }

    ans = (n - k == 0 ? num1 : num1 - ans);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
